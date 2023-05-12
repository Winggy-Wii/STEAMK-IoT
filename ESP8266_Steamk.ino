#include "html.h"
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
int ledPin = 2;


const char *ssid = "*******";
const char *password = "********";
//Điền tên và mật khẩu WiFi vào đây

const char *PARAM_INPUT = "state";
//PARAM_INPUT phải giống với URL: update?&state=

AsyncWebServer server(80);
//Tạo server tại port 80
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  //kết nối WiFi
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    request->send_P(200, "text/html", index_html);
  });
  //tại root của server (http://) thì client cái html
  server.on("/update", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    //xử lí dữ liệu của server tại nhánh http://update?
    String inputMessage;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT))
    {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      digitalWrite(ledPin, inputMessage.toInt());
      //Bật tắt chân GPIO
    }
    else
    {
      inputMessage = "No message sent";
    }
    Serial.print("GPIO: ");
    Serial.print(ledPin);
    Serial.print(" - Set to: ");
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  //Kích hoạt server
  server.begin();
}

void loop() {

}
