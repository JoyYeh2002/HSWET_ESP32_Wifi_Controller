
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "index_html.h"

const char *ssid = "my_network";
const char *password = "ESP32_Tutorial";

const int PIN_LED_SERVER = 4;
const int buffer_size = 2048;

// Digital state indicators
const int PIN_LED_RUN = 11; // Experiment start light)
const int PIN_LED_STOP = 13;    // Emergency Stop

const int PIN_PWR_OPTI_MODE = 15;
const int PIN_DURABILITY_MODE = 16;
const int PIN_RATED_PWR_MODE = 18;

// Digital state sensors (ON or OFF)
const int PIN_SAFETY_STATE = 45;
const int PIN_BACKUP_PWR = 47;

// Analog pins
const int PIN_A0 = 10;     // wind-speed
const int PIN_A1 = 17;     // rpm
const int PIN_A2 = 9;      // pwr


const int PIN_FAN = 5;  


// variables to store measure data and sensor states
int BitsA0 = 0, BitsA1 = 0, BitsA2 = 0;
float VoltsA0 = 0, VoltsA1 = 0, VoltsA2 = 0;
int FanSpeed = 0;
bool STOPPED = false, RUNNING = false;

int StateSafety = 0, StateBackup = 0;

uint32_t SensorUpdate = 0;
int FanRPM = 0;

// the XML array size needs to be bigger that your maximum expected size. 2048 is way too big for this example
char XML[buffer_size];
char buf[32];

WebServer server(80);

void setup(void) {

  Serial.begin(115200);

  pinMode(PIN_LED_SERVER, OUTPUT);
  digitalWrite(PIN_LED_SERVER, 0);

  pinMode(PIN_FAN, OUTPUT);

  pinMode(PIN_LED_STOP, OUTPUT);
  digitalWrite(PIN_LED_STOP, STOPPED);

  pinMode(PIN_LED_RUN, OUTPUT);
  digitalWrite(PIN_LED_RUN, RUNNING);

// -----------------New Code-----------------
  pinMode(PIN_PWR_OPTI_MODE, OUTPUT);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);

  pinMode(PIN_DURABILITY_MODE, OUTPUT);
  digitalWrite(PIN_DURABILITY_MODE, 0);

  pinMode(PIN_RATED_PWR_MODE, OUTPUT);
  digitalWrite(PIN_RATED_PWR_MODE, 0);
// -----------------New Code-----------------

  pinMode(PIN_SAFETY_STATE, INPUT);
  pinMode(PIN_BACKUP_PWR, INPUT);


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
  server.on("/BUTTON_STOP", ProcessStopButton);
  server.on("/BUTTON_RUN", ProcessRunButton);

//-----------------New Code-----------------
  server.on("/PWR_OPTI", SetPwrOptiMode);
  server.on("/DURABILITY", SetDurabilityMode);
  server.on("/RATED_PWR", SetRatedPwrMode);
//-----------------New Code-----------------


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
    BitsA2 = analogRead(PIN_A2);

    // standard converion to go from 12 bit resolution reads to volts on an ESP
    VoltsA0 = BitsA0 * 16 / 4096; // wind speed
    VoltsA1 = BitsA1 * 2000 / 4096; // RPM
    VoltsA2 = BitsA2 * 40 / 4096;    // Power

    // Read the safety and backup states from ESP32
    StateSafety = digitalRead(PIN_SAFETY_STATE);
    StateBackup = digitalRead(PIN_BACKUP_PWR);

    Serial.println(StateSafety); // Print the value to the serial monitor
  

  }
  server.handleClient();
  
}

void HandleRoot() {
  digitalWrite(PIN_LED_SERVER, 1);
  server.send(200, "text/html", PAGE_MAIN);
  digitalWrite(PIN_LED_SERVER, 0);
}

void HandleNotFound() {
  digitalWrite(PIN_LED_SERVER, 1);
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
  digitalWrite(PIN_LED_SERVER, 0);
}

// Stop button toggles
void ProcessStopButton() {
  STOPPED = !STOPPED;
  digitalWrite(PIN_LED_STOP, STOPPED);
  Serial.print("Button 0 "); Serial.println(STOPPED);
  server.send(200, "text/plain", ""); 
}

// Run button toggles
void ProcessRunButton() {
  Serial.println("Exp run button press");
  RUNNING = !RUNNING;
  digitalWrite(PIN_LED_RUN, RUNNING);
  Serial.print("Experiment Run Status: "); Serial.println(RUNNING);
  server.send(200, "text/plain", ""); 
}

// sent power optimization mode to high
void SetPwrOptiMode() {
  Serial.println("Set to power optimization mode");
  digitalWrite(PIN_PWR_OPTI_MODE, 1);
  digitalWrite(PIN_RATED_PWR_MODE, 0);
  digitalWrite(PIN_DURABILITY_MODE, 0);
  server.send(200, "text/plain", ""); //Send web page
}

void SetRatedPwrMode() {
  Serial.println("Set to rated power mode");
  digitalWrite(PIN_RATED_PWR_MODE, 1);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);
  digitalWrite(PIN_DURABILITY_MODE, 0);
  server.send(200, "text/plain", ""); //Send web page
}

void SetDurabilityMode() {
  Serial.println("Set to durability mode");
  digitalWrite(PIN_DURABILITY_MODE, 1);
  digitalWrite(PIN_RATED_PWR_MODE, 0);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);
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
  sprintf(buf, "<wind-speed>%d.%d</wind-speed>\n", (int) (VoltsA0), abs((int) (VoltsA0 * 10)  - ((int) (VoltsA0) * 10)));
  strcat(XML, buf);

  // send bits1
  sprintf(buf, "<B1>%d</B1>\n", BitsA1);
  strcat(XML, buf);

  // send Volts1
  sprintf(buf, "<rpm>%d.%d</rpm>\n", (int) (VoltsA1), abs((int) (VoltsA1 * 10)  - ((int) (VoltsA1) * 10)));
  strcat(XML, buf);

  // send bits2
  sprintf(buf, "<B2>%d</B2>\n", BitsA2);
  strcat(XML, buf);

  // send Volts2
  sprintf(buf, "<pwr>%d.%d</pwr>\n", (int) (VoltsA2), abs((int) (VoltsA2 * 10)  - ((int) (VoltsA2) * 10)));
  strcat(XML, buf);


   // Send STOP button status
  if (STOPPED) {
    strcat(XML, "<STOP>1</STOP>\n");
  }
  else {
    strcat(XML, "<STOP>0</STOP>\n");
  }

  // Send EXP button status
  if (RUNNING) {
    strcat(XML, "<RUN>1</RUN>\n");
  }
  else {
    strcat(XML, "<RUN>0</RUN>\n");
  }

  // Send safety state
  sprintf(buf, "<SAFETY>%d</SAFETY>\n", StateSafety);
  strcat(XML, buf);

  // Send backup state
  sprintf(buf, "<BACKUP>%d</BACKUP>\n", StateBackup);
  strcat(XML, buf);

  strcat(XML, "</Data>\n");
  server.send(200, "text/xml", XML);
}