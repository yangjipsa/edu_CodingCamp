// board : wemos d1 r1
#define pinSW1   D2
#define pinSW2   D3

void setup()
{
  Serial.begin(9600); 
  pinMode(pinSW1, INPUT);
  pinMode(pinSW2, INPUT);
}

void loop()
{
  bool valSW1 = digitalRead(pinSW1); 
  bool valSW2 = digitalRead(pinSW2);

  Serial.print("Left Switch : ");
  Serial.print(valSW1);
  Serial.print(", Right Switch : ");
  Serial.println(valSW2);

  delay(200);
}
