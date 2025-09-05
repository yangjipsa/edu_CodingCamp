// Board: LOLIN(WEMOS) D1 R1 (ESP8266) 20250905
// Libraries:
//   - ESP8266WiFi (보드 설치 시 포함)
//   - Firebase ESP8266 Client (by Mobizt)


#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

#define WIFI_SSID     "YangJipsa iPhone"
#define WIFI_PASSWORD "15151515"

// ← 여기서는 https 제거하고 host만! (끝에 / 없음)
#define FIREBASE_HOST "test3-2f43c-default-rtdb.asia-southeast1.firebasedatabase.app"
#define LEGACY_DB_SECRET "YOUR_DATABASE_SECRET"

const int LED_PIN = LED_BUILTIN; // Active-Low

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println(); Serial.println(WiFi.localIP());

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // Active-Low

  // ※ 이 라이브러리는 host(https X) 사용
  config.host = FIREBASE_HOST;
  // 레거시 토큰(데이터베이스 시크릿)
  config.signer.tokens.legacy_token = LEGACY_DB_SECRET;

  Firebase.reconnectWiFi(true);
  Firebase.begin(&config, &auth);
}

void loop() {
  // 읽기 (RTDB 네임스페이스가 아니라 get* 함수 사용)
  if (Firebase.getBool(fbdo, "/LED1")) 
  {
    bool ledOn = fbdo.boolData();
    if(ledOn) digitalWrite(LED_PIN, LOW);
    else digitalWrite(LED_PIN, HIGH); // active LOW
  }

  // 쓰기
  Firebase.setInt(fbdo,    "/device/rssi",   WiFi.RSSI());
  Firebase.setString(fbdo, "/device/ip",     WiFi.localIP().toString());
  //Firebase.setFloat(fbdo,  "/device/heapKB", ESP.getFreeHeap()/1024.0);

  delay(1000);
}
