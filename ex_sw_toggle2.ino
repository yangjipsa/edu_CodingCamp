//board : wemos d1 r1
#define pinSW1  D2
#define pinLED1 D4

bool flag1 = false;
bool valLED1 = false;

void setup()
{
  pinMode(pinSW1, INPUT);
  pinMode(pinLED1, OUTPUT);
}

void loop() 
{
  bool valSW1 = digitalRead(pinSW1); // read SW1 value
  if(valSW1)
  {
    if(!flag1)
    {
      valLED1 = !valLED1;
      digitalWrite(pinLED1, valLED1);

      flag1 = true;
    }
  }
  else flag1 = false;
}
