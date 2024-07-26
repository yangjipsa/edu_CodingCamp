//board : wemos d1 r1
#define pinSW1  D2
#define pinLED1 D4

bool cState1 = false; // current state of sw1
bool lState1 = false; // last state of sw1

bool valLED1 = false;

void setup()
{
  pinMode(pinSW1, INPUT);
  pinMode(pinLED1, OUTPUT);
}

void loop() 
{
  cState1 = digitalRead(pinSW1); // read SW1 value
  delay(10); // for debouncing
  
  if (cState1 < lState1) // detecting rising edge
  {
    valLED1 = !valLED1;
    digitalWrite(pinLED1, valLED1);
  }

  lState1 = cState1; // sw1 value update
}
