#include "FirebaseESP8266.h" 
#include <ESP8266WiFi.h>
 
#define FIREBASE_HOST "skkuiot-240807-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH "wGmQQ4uiBvLUCNfKN6jCwOyHoDDy9wVj4Ku2LZXC"
#define WIFI_SSID "iot1" // 연결 가능한 wifi의 ssid
#define WIFI_PASSWORD "15151515" // wifi 비밀번호

#define pinLED1 D4
#define pinLED2 D7
#define pinCDS  A0
 
FirebaseData firebaseData;
FirebaseJson json;

bool autoMode = false;
 
void setup() // wifi 접속 과정.
{
  Serial.begin(9600);
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println();
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 
  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

void loop()
{
  delay(1000); 
  int valCDS = analogRead(pinCDS);
  Firebase.setInt(firebaseData, "LIGHT", valCDS);

  if(Firebase.getBool(firebaseData,"AUTO")) 
  {
    autoMode = firebaseData.boolData();
  }

  if(autoMode)
  {
    if((valCDS>=0) && (valCDS<=300))
    {
      digitalWrite(pinLED1, LOW);
      digitalWrite(pinLED2, LOW);
    }
    else if((valCDS>300) && (valCDS<=600))
    {
      digitalWrite(pinLED1, HIGH);
      digitalWrite(pinLED2, LOW);
    }
    else 
    {
      digitalWrite(pinLED1, HIGH);
      digitalWrite(pinLED2, HIGH);
    }
  }
  else
  {
    if(Firebase.getBool(firebaseData,"LED1")) 
    {
      bool valLED1 = firebaseData.boolData();
      digitalWrite(pinLED1, valLED1);
    }

    if(Firebase.getBool(firebaseData, "LED2")) 
    {
      bool valLED2 = firebaseData.boolData();
      digitalWrite(pinLED2, valLED2);
    } 
  }
/* if(Firebase.getInt(firebaseData, "Int Data Tag")){
  int valInt = firebaseData.intData();
  // write Code...
 }
 if(Firebase.getFloat(firebaseData, "Float Data Tag")){
  float valFloat = firebaseData.floatData();
  // write Code...
 }
 if(Firebase.getString(firebaseData, "String Data Tag")){
  String valStr = firebaseData.stringData();
  // write Code...
 }*/


}
