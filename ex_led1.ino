// Board : Wemos R1 D1

#define pinLED1 D4
#define pinLED2 D7

void setup()
{
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
}

void loop()
{
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, LOW);
  delay(1000);
  
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, HIGH);  
  delay(1000);
}
