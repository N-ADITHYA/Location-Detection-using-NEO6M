#include <Ultrasonic.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

// GPS pins
#define RXPin D7
#define TXPin D6
#define GPSBaud 9600

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

// WiFi credentials
const char* ssid = "your_ssid";
const char* password = "your_password";

// Server IP address (replace with your FastAPI server IP)
const char* server = "your_ipv4_address";  // <-- Replace this with your FastAPI server IPv4

WiFiClient client;

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPSBaud);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void loop() {
  // Read data from GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());

    if (gps.location.isUpdated()) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();

      Serial.print("Lat: "); Serial.print(latitude, 6);
      Serial.print(" Lon: "); Serial.println(longitude, 6);

      // Send GPS data to server
      sendGPSData(latitude, longitude);
    }
  }
}

void sendGPSData(float lat, float lon) {
  WiFiClient client;
  Serial.println("Connecting to server: your_ipv4_address");  // <-- Replace with actual server IP

  if (client.connect(server, 8000)) { // Port 8000 matches FastAPI default
    Serial.println(" Connected to server! Sending GPS data...");

    // Prepare JSON payload
    StaticJsonDocument<200> jsonDoc;
    jsonDoc["latitude"] = lat;
    jsonDoc["longitude"] = lon;
    String postData;
    serializeJson(jsonDoc, postData);

    // Send HTTP POST request
    Serial.print(" Sending Data: ");
    Serial.println(postData);

    client.println("POST /gps HTTP/1.1");
    client.println("Host: your_ipv4_address");  // <-- Replace with actual server IP
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(postData.length()));
    client.println();
    client.println(postData);

    delay(500);
    Serial.println(" Data sent successfully!");
  } else {
    Serial.println(" Connection to server failed!");
  }

  client.stop();
}
