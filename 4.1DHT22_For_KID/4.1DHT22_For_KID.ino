#include "DHT.h"


DHT dht( , DHT22); // กำหนดขาที่น้องๆต้องการจะต่อกับตัว Sensor ได้เลยครับ 
float t; 
float h;

void setup() {
  Serial.begin(9600);
   Serial.println("Start DHT22 ...");
   Serial.println("");
  dht.begin();
}

void loop() {
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
  delay(1000);
}
