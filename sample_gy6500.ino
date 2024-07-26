// board : wemos d1 r1
// Sensor : gy6500 (Acceleration/Gyro Sensor)
// library : mpu6050


#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() 
{
  Serial.begin(9600); // 시리얼 통신 속도를 115200으로 설정
  Wire.begin(D1, D2);   // I2C 통신을 위한 SDA, SCL 핀 설정 (D1: SCL, D2: SDA)

  Serial.println("MPU6050 초기화 중...");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("MPU6050 연결 실패. 다시 시도 중...");
    delay(1000);
  }

  Serial.println("MPU6050 연결 성공!");

  // 센서 초기화
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

void loop() 
{
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  Vector rawGyro = mpu.readRawGyro();
  Vector normGyro = mpu.readNormalizeGyro();

  // 가속도 데이터 출력
  Serial.print("가속도 X: ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Y: ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Z: ");
  Serial.println(normAccel.ZAxis);

  // 자이로 데이터 출력
  Serial.print("자이로 X: ");
  Serial.print(normGyro.XAxis);
  Serial.print(" Y: ");
  Serial.print(normGyro.YAxis);
  Serial.print(" Z: ");
  Serial.println(normGyro.ZAxis);

  delay(1000); // 1초 대기
}
