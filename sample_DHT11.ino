// board : wemos d1 r1
// sensor : DHT11
// library : DHT sensor library
// pin assign : 

#include <DHT.h>

#define DHTPIN D4     // DHT11 센서의 데이터 핀이 연결된 핀 (WeMos D1 R1 보드에서는 D4)
#define DHTTYPE DHT11 // DHT11 센서 유형

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도를 115200으로 설정
  dht.begin(); // DHT 센서를 초기화
}

void loop() {
  // 센서로부터 데이터를 읽기 전에 약간의 지연이 필요합니다.
  delay(2000);

  float humidity = dht.readHumidity();    // 습도를 읽음
  float temperature = dht.readTemperature(); // 섭씨 온도를 읽음

  // 데이터가 제대로 읽혔는지 확인
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT 센서로부터 데이터를 읽을 수 없습니다.");
  }
  else
  {
    // 온도와 습도를 시리얼 모니터에 출력
    Serial.print("습도: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("온도: ");
    Serial.print(temperature);
    Serial.println(" *C");
  }
}
