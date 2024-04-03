
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "index_html.h"

const char *ssid = "my_network";
const char *password = "ESP32_Tutorial";

const int led = 4;
const int buffer_size = 4096;

const int PIN_OUTPUT = 26; // connected to nothing but an example of a digital write from the web page
const int PIN_FAN = 5;    // pin 27 and is a PWM signal to control a fan speed
const int PIN_LED = 13;     //On board LED
const int PIN_A0 = 10;     // some analog input sensor
const int PIN_A1 = 17;     // some analog input sensor

// variables to store measure data and sensor states
int BitsA0 = 0, BitsA1 = 0;
float VoltsA0 = 0, VoltsA1 = 0;
int FanSpeed = 0;
bool LED0 = false, SomeOutput = false;
uint32_t SensorUpdate = 0;
int FanRPM = 0;

// the XML array size needs to be bigger that your maximum expected size. 2048 is way too big for this example
char XML[buffer_size];
char buf[32];

WebServer server(80);

void setup(void) {

  Serial.begin(115200);

  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  pinMode(PIN_FAN, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LED0);

  // configure LED PWM functionalitites
  ledcSetup(0, 10000, 8);
  ledcAttachPin(PIN_FAN, 0);
  ledcWrite(0, FanSpeed);

  disableCore0WDT();
  disableCore1WDT();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", HandleRoot); // this is SendWebsite()
  server.on("/xml", SendXML);

  server.on("/UPDATE_SLIDER", UpdateSlider);
  server.on("/BUTTON_0", ProcessButton_0);
  server.on("/BUTTON_1", ProcessButton_1);

  server.onNotFound(HandleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {

    if ((millis() - SensorUpdate) >= 50) {
    //Serial.println("Reading Sensors");
    SensorUpdate = millis();
    BitsA0 = analogRead(PIN_A0);
    BitsA1 = analogRead(PIN_A1);

    // standard converion to go from 12 bit resolution reads to volts on an ESP
    VoltsA0 = BitsA0 * 3.3 / 4096;
    VoltsA1 = BitsA1 * 3.3 / 4096;

  }
  server.handleClient();
  
}

void HandleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", PAGE_MAIN);
  digitalWrite(led, 0);
}

void HandleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void ProcessButton_0() {
  LED0 = !LED0;
  digitalWrite(PIN_LED, LED0);
  Serial.print("Button 0 "); Serial.println(LED0);
  server.send(200, "text/plain", ""); //Send web page
}

// same notion for processing button_1
void ProcessButton_1() {
  Serial.println("Button 1 press");
  SomeOutput = !SomeOutput;
  digitalWrite(PIN_OUTPUT, SomeOutput);
  Serial.print("Button 1 "); Serial.println(LED0);
  server.send(200, "text/plain", ""); //Send web page
}

void UpdateSlider() {
  // many I hate strings, but wifi lib uses them...
  String t_state = server.arg("VALUE");

  // conver the string sent from the web page to an int
  FanSpeed = t_state.toInt();
  Serial.print("UpdateSlider"); Serial.println(FanSpeed);
  // now set the PWM duty cycle
  ledcWrite(0, FanSpeed);

  FanRPM = map(FanSpeed, 0, 255, 0, 2400);
  strcpy(buf, "");
  sprintf(buf, "%d", FanRPM);
  sprintf(buf, buf);

  // now send it back
  server.send(200, "text/plain", buf); //Send web page
}

void SendXML() {
  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  // send bitsA0
  sprintf(buf, "<B0>%d</B0>\n", BitsA0);
  strcat(XML, buf);

  // send Volts0
  sprintf(buf, "<V0>%d.%d</V0>\n", (int) (VoltsA0), abs((int) (VoltsA0 * 10)  - ((int) (VoltsA0) * 10)));
  strcat(XML, buf);

  // send bits1
  sprintf(buf, "<B1>%d</B1>\n", BitsA1);
  strcat(XML, buf);

  // send Volts1
  sprintf(buf, "<V1>%d.%d</V1>\n", (int) (VoltsA1), abs((int) (VoltsA1 * 10)  - ((int) (VoltsA1) * 10)));
  strcat(XML, buf);

  // show led0 status
  if (LED0) {
    strcat(XML, "<LED>1</LED>\n");
  }
  else {
    strcat(XML, "<LED>0</LED>\n");
  }

  strcat(XML, "</Data>\n");
  server.send(200, "text/xml", XML);

  Serial.println(BitsA0);
  Serial.println(',');
  Serial.println(BitsA1);
  

}
