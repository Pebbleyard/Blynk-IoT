#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = " "; // ใส่ชื่อ WiFi
char pass[] = "  "; // ใส่ รหัส WiFi
char auth[] = " "; //  ใส่ Auth ดูได้ใน แอป Blynk
int item;

BLYNK_WRITE( ) { // กำหนดขา V ตามที่เราต้องการใน แอป Blynk
   item = param.asInt();
   Serial.println(item);
  digitalWrite( , item); // กำหนดขาที่ต้องการให้ LED สว่าง
}


void setup() {
  pinMode( , OUTPUT); // กำหนดขาที่ต้องการให้ LED สว่าง
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  
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
}
