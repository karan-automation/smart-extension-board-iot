/*
  Smart Extension Board
  NodeMCU ESP8266 + Blynk 2.0

  Public portfolio version.
  Replace placeholder credentials locally before uploading to hardware.
*/

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Extension Board"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RELAY_1 D0
#define RELAY_2 D1
#define RELAY_3 D2
#define RELAY_4 D3

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

void setRelay(uint8_t relayPin, int value) {
  // Active-low relay board
  digitalWrite(relayPin, value ? LOW : HIGH);
}

BLYNK_WRITE(V0) {
  setRelay(RELAY_1, param.asInt());
}

BLYNK_WRITE(V1) {
  setRelay(RELAY_2, param.asInt());
}

BLYNK_WRITE(V2) {
  setRelay(RELAY_3, param.asInt());
}

BLYNK_WRITE(V3) {
  setRelay(RELAY_4, param.asInt());
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // Keep all relays off at startup
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
