#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
const char* host = "Robot_Wifi_NodeMCU";
const char* ssid = "Robot Pemadam";
const char* password = "cerdascendikiamandiri";
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  // Connecting WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);
// Starting WEB-server
      server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
   }
void loop() {
  server.handleClient();
   delay(50);
}
void HTTP_handleRoot(void) {
if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
}


