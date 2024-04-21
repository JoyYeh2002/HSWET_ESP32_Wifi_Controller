
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "index_html.h"

// ----------------- Set up the web server -----------------
/* How to configure your mobile hotspot
1. Look up "mobile hotspot" on your Window laptop's search bar
2. Set the "band" to 2.4 GHz
3. Name the ssid and password to something that matches the Arduino code here
4. Turn on the mobile hotspot every time you want to use the web server.
*/
const char *ssid = "my_network";
const char *password = "ESP32_Tutorial";

// -------- [FEEL FREE TO CHANGE] Set up the pins ----------
// Digital output state indicators
const int PIN_LED_STOP = 18;   // [GOOD] Emergency Stop
const int PIN_LED_RUN = 19;    // [GOOD] Experiment start light

// LEDs for the 3 modes [GOOD]
const int PIN_PWR_OPTI_MODE = 5;   // [GOOD]
const int PIN_DURABILITY_MODE = 6; // [GOOD]
const int PIN_RATED_PWR_MODE = 7;  // [GOOD]

// Digital state sensors (ON or OFF)
// Don't use pin 8
const int PIN_SAFETY_STATE = 9;    // [GOOD]
const int PIN_BACKUP_PWR = 10;      // [GOOD]

// Analog pins for voltage, RPM, and output power
const int PIN_A0 = 0;   // voltage [GOOD]
const int PIN_A1 = 1;   // rpm [GOOD]
const int PIN_A2 = 2;   // current [GOOD]

// Analog pins for voltage, RPM, and output power
const int PIN_I_MEASURED = 3;   // current measured (E-load)
const int PIN_BLADE_PITCH = 4;  // blade pitch

// This could be smaller if possible (for web page storage)
const int buffer_size = 2048; 

// ----------------- Set up variables -----------------
const int max_voltage = 16; // [INPUT] max voltage
const int max_rpm = 2400;      // [INPUT] max RPM
const int max_current = 5;        // [INPUT] max power

// initialize booleans and integer variables
int BitsA0 = 0, BitsA1 = 0, BitsA2 = 0;
float VoltsA0 = 0, VoltsA1 = 0, VoltsA2 = 0;
bool STOPPED = false, RUNNING = false;

int StateSafety = 0, StateBackup = 0;
uint32_t SensorUpdate = 0;

// the XML array size needs to be bigger that your maximum expected size. 
// 2048 is way too big for this example
char XML[buffer_size];
char buf[32];

// ------------ Web server starts here -----------------
WebServer server(80);

void setup(void) {

  Serial.begin(115200);

  // Set up all the pins

  pinMode(PIN_LED_STOP, OUTPUT);
  digitalWrite(PIN_LED_STOP, STOPPED);

  pinMode(PIN_LED_RUN, OUTPUT);
  digitalWrite(PIN_LED_RUN, RUNNING);

  pinMode(PIN_PWR_OPTI_MODE, OUTPUT);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);

  pinMode(PIN_DURABILITY_MODE, OUTPUT);
  digitalWrite(PIN_DURABILITY_MODE, 0);

  pinMode(PIN_RATED_PWR_MODE, OUTPUT);
  digitalWrite(PIN_RATED_PWR_MODE, 0);

  pinMode(PIN_SAFETY_STATE, INPUT);
  pinMode(PIN_BACKUP_PWR, INPUT);

  // configure LED PWM functionalitites
  // [TODO] Could use these colors for voltage, RPM, PWR?
  // ledcSetup(0, 10000, 8);
  // ledcAttachPin(PIN_FAN, 0);
  // ledcWrite(0, FanSpeed);
  // pinMode(PIN_FAN, OUTPUT);

  // Might not need this
  disableCore0WDT();
  // disableCore1WDT();

  // ------ Wifi conncecion status is displayed in serial monitor ---
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

  // ------ Attach functions to their tags --------------
  server.on("/", HandleRoot); // this sends the website
  server.on("/xml", SendXML);

  // server.on("/UPDATE_SLIDER", UpdateSlider);
  server.on("/BUTTON_STOP", ProcessStopButton);
  server.on("/BUTTON_RUN", ProcessRunButton);

  server.on("/PWR_OPTI", SetPwrOptiMode);
  server.on("/DURABILITY", SetDurabilityMode);
  server.on("/RATED_PWR", SetRatedPwrMode);


  // ----------- Error handling + start server ------------
  server.onNotFound(HandleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

// -------------- Main loop -----------------
void loop(void) {
  if ((millis() - SensorUpdate) >= 50) {
    SensorUpdate = millis();

    // Read the analog pins for voltage, RPN, and power
    BitsA0 = analogRead(PIN_A0);
    BitsA1 = analogRead(PIN_A1);
    BitsA2 = analogRead(PIN_A2);

    // standard converion to go from 12 bit resolution reads to volts on an ESP
    VoltsA0 = BitsA0 * max_voltage / 4096; 
    VoltsA1 = BitsA1 * max_rpm / 4096; 
    VoltsA2 = BitsA2 * max_current / 4096;   

    // Read the safety and backup states from ESP32
    StateSafety = digitalRead(PIN_SAFETY_STATE);
    StateBackup = digitalRead(PIN_BACKUP_PWR);
  }
  server.handleClient();
}

// Sends the webpage
void HandleRoot() {
  server.send(200, "text/html", PAGE_MAIN);
}

// Hanldes file not found error
void HandleNotFound() {

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

// Set power optimization mode high
void SetPwrOptiMode() {
  Serial.println("Set to power optimization mode");
  digitalWrite(PIN_PWR_OPTI_MODE, 1);
  digitalWrite(PIN_RATED_PWR_MODE, 0);
  digitalWrite(PIN_DURABILITY_MODE, 0);
  server.send(200, "text/plain", ""); 
}

// Set rated power mode high
void SetRatedPwrMode() {
  Serial.println("Set to rated power mode");
  digitalWrite(PIN_RATED_PWR_MODE, 1);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);
  digitalWrite(PIN_DURABILITY_MODE, 0);
  server.send(200, "text/plain", ""); 
}

// Set durability mode high
void SetDurabilityMode() {
  Serial.println("Set to durability mode");
  digitalWrite(PIN_DURABILITY_MODE, 1);
  digitalWrite(PIN_RATED_PWR_MODE, 0);
  digitalWrite(PIN_PWR_OPTI_MODE, 0);
  server.send(200, "text/plain", ""); 
}

// Send the XML data to HTML in index_html.h. Encloses the data in XML tags
void SendXML() {
  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  // send bitsA0
  sprintf(buf, "<B0>%d</B0>\n", BitsA0);
  strcat(XML, buf);

  // send Volts0
  sprintf(buf, "<voltage>%d.%d</voltage>\n", (int) (VoltsA0), abs((int) (VoltsA0 * 10)  - ((int) (VoltsA0) * 10)));
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
  sprintf(buf, "<current>%d.%d</current>\n", (int) (VoltsA2), abs((int) (VoltsA2 * 10)  - ((int) (VoltsA2) * 10)));
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