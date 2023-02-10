#include "Adafruit_seesaw.h"

Adafruit_seesaw ss;

// Pin Variables
const int SENSOR_PIN = 3;
const int LIGHT_PIN = 5;

void setup() {
//Pin Functions
  pinMode(SENSOR_PIN, OUTPUT);

  pinMode(LIGHT_PIN, OUTPUT);

// Soil Sensor
  Serial.begin(115200);

  Serial.println("seesaw Soil Sensor example!");
  
  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");
    while(1) delay(1);
  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop() {
//Soil Sensor
  float tempC = ss.getTemp();
  uint16_t capread = ss.touchRead(0);

  Serial.print("Temperature: "); Serial.print(tempC); Serial.println("*C");
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(100);

//Water Pump
  if (capread < 900) {                     //Conditional: If capacitive value is less than 900, the pump will turn on
    digitalWrite(SENSOR_PIN, HIGH);       //Once it reaches a value of 900, the pump will turn off
  }else if (capread > 900) {
    digitalWrite(SENSOR_PIN, LOW);
  }

//Lights
  digitalWrite(LIGHT_PIN, HIGH);            //Turns the LED on by turning the voltage level to HIGH
  delay(10000);                         //Waits 25,200,000 milliseconds(7 hours)
  digitalWrite(LIGHT_PIN, LOW);           //Turns the LED off by turning the voltage level to LOW
  delay(10000);                       //Waits 61,200,000 milliseconds(17 hours)
}

