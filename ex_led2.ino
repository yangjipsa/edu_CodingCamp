// board : Wemos D1 R1

#define pinLED1 D4
#define pinLED2 D7

int timeDelay = 20;
int onTime = 5;
int offTime = timeDelay - onTime;
 
void setup()
{
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);

  // LED 1 ON
  digitalWrite(pinLED1, HIGH); 
}

void loop()
{
   // LED 2 ON
  digitalWrite(pinLED2, HIGH);
  delay(onTime);
   // LED 2 OFF 
  digitalWrite(pinLED2, LOW);  
  delay(offTime);
}
