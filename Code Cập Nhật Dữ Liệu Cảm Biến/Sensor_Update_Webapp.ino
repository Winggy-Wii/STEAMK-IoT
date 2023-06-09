#include <Arduino.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "html.h"
// Variables to store temperature values
String Temperature = "";
String Humidity = "";
// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

// Replace with your network credentials
const char *ssid = "*******";
const char *password = "********";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
String processor(const String &var)
{
  // Serial.println(var);
  if (var == "TEMPERATURE")
  {
    return Temperature;
  }
  else if (var == "HUMIDITY")
  {
    return Humidity;
  }
  return String();
}

void setup()
{
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  pinMode(A0,INPUT);
  Temperature = String(random(1, 1000));
  Humidity = String(random(1, 1000));
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS))
  {
    Serial.println("STA Failed to configure");
  }
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html, processor); });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", Temperature.c_str()); });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", Humidity.c_str()); });
  // Start server
  server.begin();
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    Temperature = String(random(1, 1000));
    Humidity = String(analogRead(A0));

    lastTime = millis();
  }
}
