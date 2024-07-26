// board : wemos d1 r1
#define pinSW1   D2
#define pinSW2   D3
#define pinLED1  D4
#define pinLED2  D7

void setup()
{
  pinMode(pinSW1, INPUT);
  pinMode(pinSW2, INPUT);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
}

void loop()
{
  bool valSW1 = digitalRead(pinSW1); 
  bool valSW2 = digitalRead(pinSW2);

  if(valSW1) digitalWrite(pinLED1, HIGH);
  else       digitalWrite(pinLED1, LOW);

  if(valSW2) digitalWrite(pinLED2, HIGH);
  else       digitalWrite(pinLED2, LOW);
}
