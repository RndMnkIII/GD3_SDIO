
#include <SPI.h>
#ifndef CS
#define CS 10
#endif


class GDTransport {
private:
  byte model;
  
public:
  void ios() {
    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);

    if(MCU_Teensy3X==0)
      {
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
      }

    SPI.begin();
    // for (;;) SPI.transfer(0x33);
  }
  void begin0() {
    ios();

    SPI.begin();
#ifdef TEENSYDUINO
    #warning "RndMnkIII: definida TEENSYDUINO"
    //SPI.beginTransaction(settingsT36);
#else
     #warning "RndMnkIII: NO definida TEENSYDUINO"
#ifndef __DUE__
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPSR = (1 << SPI2X);
#endif
#endif

    hostcmd(0x00);
#if (BOARD != BOARD_FTDI_81X)
 hostcmd(0x44); // from external crystal
#endif
    hostcmd(0x68);
  }
  void begin1() {
#if 0
    delay(120);
#else
    while ((__rd16(0xc0000UL) & 0xff) != 0x08)
      ;
#endif

    // Test point: saturate SPI
    while (0) {
      SPI.beginTransaction(settingsT36);
      digitalWrite(CS, LOW);
      SPI.transfer(0x55);
      digitalWrite(CS, HIGH);
      SPI.endTransaction();
    }

#if 0
    // Test point: attempt to wake up FT8xx every 2 seconds
    while (0) {
      hostcmd(0x00);
      delay(120);
      hostcmd(0x68);
      delay(120);
      SPI.beginTransaction(settingsT36);
      digitalWrite(CS, LOW);
      Serial.println(SPI.transfer(0x10), HEX);
      Serial.println(SPI.transfer(0x24), HEX);
      Serial.println(SPI.transfer(0x00), HEX);
      Serial.println(SPI.transfer(0xff), HEX);
      Serial.println(SPI.transfer(0x00), HEX);
      Serial.println(SPI.transfer(0x00), HEX);
      Serial.println();

      digitalWrite(CS, HIGH);
      SPI.endTransaction();
      delay(2000);
    }
#endif

    // So that FT800,801      FT81x
    // model       0            1
    ft8xx_model = __rd16(0x0c0000) >> 12;  

    wp = 0;
    freespace = 4096 - 4;

    stream();
  }

  void cmd32(uint32_t x) {
    if (freespace < 4) {
      getfree(4);
    }
    wp += 4;
    freespace -= 4;
    union {
      uint32_t c;
      uint8_t b[4];
    };
    c = x;
    SPI.beginTransaction(settingsT36);
    SPI.transfer(b[0]);
    SPI.transfer(b[1]);
    SPI.transfer(b[2]);
    SPI.transfer(b[3]);
    SPI.endTransaction();
  }
  void cmdbyte(byte x) {
    if (freespace == 0) {
      getfree(1);
    }
    wp++;
    freespace--;
    SPI.beginTransaction(settingsT36);
    SPI.transfer(x);
    SPI.endTransaction();
  }
  void cmd_n(byte *s, uint16_t n) {
     SPI.beginTransaction(settingsT36);  
    if (freespace < n) {
      getfree(n);
    }
    wp += n;
    freespace -= n;
   
    while (n > 8) {
      n -= 8;
      
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
      SPI.transfer(*s++);
    }
    while (n--)
      SPI.transfer(*s++);
    SPI.endTransaction();
  }

  void flush() {
    getfree(0);
  }
  uint16_t rp() {
    uint16_t r = __rd16(REG_CMD_READ);
    if (r == 0xfff) {
      GD.alert("COPROCESSOR EXCEPTION");
    }
    return r;
  }
  void finish() {
    wp &= 0xffc;
    __end();
    __wr16(REG_CMD_WRITE, wp);
    while (rp() != wp)
      ;
    stream();
  }

  byte rd(uint32_t addr)
  {
      SPI.beginTransaction(settingsT36);
    __end(); // stop streaming
    __start(addr);
    SPI.transfer(0);  // dummy
    byte r = SPI.transfer(0);
    stream();
    SPI.endTransaction();
    return r;
  }

  void wr(uint32_t addr, byte v)
  {
    SPI.beginTransaction(settingsT36);
  
    __end(); // stop streaming
    __wstart(addr);
    SPI.transfer(v);
    stream();
    SPI.endTransaction();
  }

  uint16_t rd16(uint32_t addr)
  {
    SPI.beginTransaction(settingsT36);
  
    uint16_t r = 0;
    __end(); // stop streaming
    __start(addr);
    SPI.transfer(0);
    r = SPI.transfer(0);
    r |= (SPI.transfer(0) << 8);
    stream();
    return r;
    SPI.endTransaction();
  }

  void wr16(uint32_t addr, uint32_t v)
  {
    SPI.beginTransaction(settingsT36);  
    __end(); // stop streaming
    __wstart(addr);
    SPI.transfer(v);
    SPI.transfer(v >> 8);
    stream();
    SPI.endTransaction();
  }

  uint32_t rd32(uint32_t addr)
  {
    SPI.beginTransaction(settingsT36);    
    __end(); // stop streaming
    __start(addr);
    SPI.transfer(0);
    union {
      uint32_t c;
      uint8_t b[4];
    };
    b[0] = SPI.transfer(0);
    b[1] = SPI.transfer(0);
    b[2] = SPI.transfer(0);
    b[3] = SPI.transfer(0);
    stream();
    SPI.endTransaction();
    return c;
  }
  void rd_n(byte *dst, uint32_t addr, uint16_t n)
  {
    SPI.beginTransaction(settingsT36);     
    __end(); // stop streaming
    __start(addr);
    SPI.transfer(0);
    while (n--)
      *dst++ = SPI.transfer(0);
    stream();
    SPI.endTransaction();
  }
#ifdef ARDUINO_AVR_UNO
  void wr_n(uint32_t addr, byte *src, uint16_t n)
  {
    __end(); // stop streaming
    __wstart(addr);
    while (n--) {
      SPDR = *src++;
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
      asm volatile("nop");
    }
    while (!(SPSR & _BV(SPIF))) ;
    stream();
  }
#else
  void wr_n(uint32_t addr, byte *src, uint16_t n)
  {
    SPI.beginTransaction(settingsT36);
    __end(); // stop streaming
    __wstart(addr);
    while (n--)
      SPI.transfer(*src++);
    stream();
    SPI.endTransaction();
  }
#endif

  void wr32(uint32_t addr, unsigned long v)
  {
    SPI.beginTransaction(settingsT36);
    __end(); // stop streaming
    __wstart(addr);
    SPI.transfer(v);
    SPI.transfer(v >> 8);
    SPI.transfer(v >> 16);
    SPI.transfer(v >> 24);
    stream();
    SPI.endTransaction();
  }

  uint32_t getwp(void) {
    return RAM_CMD + (wp & 0xffc);
  }

  void bulk(uint32_t addr) {
    __end(); // stop streaming
    __start(addr);
  }
  void resume(void) {
    stream();
  }

  static void __start(uint32_t addr) // start an SPI transaction to addr
  {
    //SPI.beginTransaction(settingsT36);  
    digitalWrite(CS, LOW);
    SPI.transfer(addr >> 16);
    SPI.transfer(highByte(addr));
    SPI.transfer(lowByte(addr));  
    //SPI.endTransaction();
  }

  static void __wstart(uint32_t addr) // start an SPI write transaction to addr
  {
    //SPI.beginTransaction(settingsT36);
    digitalWrite(CS, LOW);
    SPI.transfer(0x80 | (addr >> 16));
    SPI.transfer(highByte(addr));
    SPI.transfer(lowByte(addr));
    //SPI.endTransaction();  
  }

  static void __end() // end the SPI transaction
  {
    digitalWrite(CS, HIGH);
  }

  void stop() // end the SPI transaction
  {
    wp &= 0xffc;
    __end();
    __wr16(REG_CMD_WRITE, wp);
    // while (__rd16(REG_CMD_READ) != wp) ;
  }

  void stream(void) {
    __end();
    __wstart(RAM_CMD + (wp & 0xfff));
  }

  static unsigned int __rd16(uint32_t addr)
  {
    unsigned int r;
    //SPI.beginTransaction(settingsT36);

    __start(addr);
    SPI.transfer(0);  // dummy
    r = SPI.transfer(0);
    r |= (SPI.transfer(0) << 8);
    __end();
    //SPI.endTransaction();
    return r;
  }

  static void __wr16(uint32_t addr, unsigned int v)
  {
    //SPI.beginTransaction(settingsT36);

    __wstart(addr);
    SPI.transfer(lowByte(v));
    SPI.transfer(highByte(v));
    __end();
    //SPI.endTransaction();
  }

  static void hostcmd(byte a)
  {
    SPI.beginTransaction(settingsT36);

    digitalWrite(CS, LOW);
    SPI.transfer(a);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    digitalWrite(CS, HIGH);
    SPI.endTransaction();
  }

  void getfree(uint16_t n)
  {
    wp &= 0xfff;
    SPI.beginTransaction(settingsT36);
    __end();
    __wr16(REG_CMD_WRITE, wp & 0xffc);
    do {
      uint16_t fullness = (wp - rp()) & 4095;
      freespace = (4096 - 4) - fullness;
    } while (freespace < n);
    stream();
    SPI.endTransaction();
  }

  byte streaming;
  uint16_t wp;
  uint16_t freespace;
};
