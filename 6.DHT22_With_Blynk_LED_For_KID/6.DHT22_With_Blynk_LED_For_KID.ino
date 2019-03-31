#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
DHT dht(, DHT22); // กำหนดขาที่น้องๆต้องการจะต่อกับตัว Sensor ได้เลยครับ 

char ssid[] = " "; // ใส่ชื่อ WiFi
char pass[] = " "; // ใส่ รหัส WiFi
char auth[] = " "; // ใส่ Auth ดูได้ใน แอป Blynk
int item;
float t;
float h;


void setup() {
  pinMode(, OUTPUT); // กำหนดขาที่ต้องการให้ LED สว่าง
  pinMode(, OUTPUT); // กำหนดขาที่ต้องการให้ LED สว่าง
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  dht.begin();

  
  while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
    
  Serial.println("");
  Serial.println("WiFi connected");  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  t = dht.readTemperature();
  h = dht.readHumidity();
  delay(500);
  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.println("");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("");
  if (t < 27) {
    digitalWrite(, LOW); // กำหนดขาที่ต้องการให้ LED ดับ
    digitalWrite(, HIGH); // กำหนดขาที่ต้องการให้ LED สว่าง
  } else {
    digitalWrite(, HIGH); // กำหนดขาที่ต้องการให้ LED สว่าง
    digitalWrite(, LOW); // กำหนดขาที่ต้องการให้ LED ดับ
  }

  delay(100);
  Blynk.virtualWrite(, t);  //กำหนด V ที่ต้องการให้แสดง อุณหภูมิ
  Blynk.virtualWrite(, h); //กำหนด V ที่ต้องการให้แสดง ความชื้น
  delay(1000);
}
