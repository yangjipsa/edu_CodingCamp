//board : wemos d1 r1

#define pinSensor A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int valADC = analogRead(pinSensor);
  Serial.print("ADC Value : ");
  Serial.println(valADC);
  delay(200);
}
