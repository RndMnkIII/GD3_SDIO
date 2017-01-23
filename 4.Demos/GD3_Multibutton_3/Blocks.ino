void Block1()
{
    for(i=11; i<20; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-10)), 29, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block2()
{
    for(i=21; i<30; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-20)), 83, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block3()
{
    for(i=31; i<40; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-30)), 137, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block4()
{
    for(i=41; i<50; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-40)), 191, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block5()
{
    for(i=51; i<60; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-50)), 245, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block6()
{
    for(i=61; i<70; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-60)), 299, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block7()
{
    for(i=71; i<80; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-70)), 353, 78, 52, 28, 0, text);
    } GD.Tag(255);
}

void Block8()
{
    for(i=81; i<90; i++)
    {
      sprintf(text, "%d", i);
      GD.Tag(i); GD.cmd_button(0+(80*(i-80)), 407, 78, 52, 28, 0, text);
    } GD.Tag(255);
}
