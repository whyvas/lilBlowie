//Lil' Blowie an ESP8266, 8 bank, wifi fireworks launcher.

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "lilBlowie"
#define APPSK "boombitch"
#endif

#define PIN1 5
#define PIN2 4
#define PIN3 0
#define PIN4 16
#define PIN5 14
#define PIN6 12
#define PIN7 13
#define PIN8 15

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  sendPage();
}
void handleFire1() {
  Serial.print("Firing 1");
  digitalWrite(PIN1, LOW);
  delay(1000);
  digitalWrite(PIN1, HIGH);
  sendPage();
}
void handleFire2() {
  Serial.print("Firing 2");
  digitalWrite(PIN2, LOW);
  delay(1000);
  digitalWrite(PIN2, HIGH);
  sendPage();
}
void handleFire3() {
  Serial.print("Firing 3");
  digitalWrite(PIN3, LOW);
  delay(1000);
  digitalWrite(PIN3, HIGH);
  sendPage();
}
void handleFire4() {
  Serial.print("Firing 4");
  digitalWrite(PIN4, LOW);
  delay(1000);
  digitalWrite(PIN4, HIGH);
  sendPage();
}
void handleFire5() {
  Serial.print("Firing 5");
  digitalWrite(PIN5, LOW);
  delay(1000);
  digitalWrite(PIN5, HIGH);
  sendPage();
}
void handleFire6() {
  Serial.print("Firing 6");
  digitalWrite(PIN6, LOW);
  delay(1000);
  digitalWrite(PIN6, HIGH);
  sendPage();
}
void handleFire7() {
  Serial.print("Firing 7");
  digitalWrite(PIN7, LOW);
  delay(1000);
  digitalWrite(PIN7, HIGH);
  sendPage();
}
void handleFire8() {
  Serial.print("Firing 8");
  digitalWrite(PIN8, LOW);
  delay(1000);
  digitalWrite(PIN8, HIGH);
  sendPage();
}

void sendPage() {
  server.send(200, "text/html", "<body style=\"background-color:red\"><br><br><center><font face=\"helvetica\"><a style=\"font-size:90px\"><b>Lil\' Blowie &trade;</b><br></a></font><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/1\"\'><a style=\"font-size:60px\">Bank 1 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/2\"\'><a style=\"font-size:60px\">Bank 2 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/3\"\'><a style=\"font-size:60px\">Bank 3 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/4\"\'><a style=\"font-size:60px\">Bank 4 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/5\"\'><a style=\"font-size:60px\">Bank 5 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/6\"\'><a style=\"font-size:60px\">Bank 6 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/7\"\'><a style=\"font-size:60px\">Bank 7 FIRE!</a></button><br><button style=\"height:160px;width:400px\" type=\"button\" onclick=\'parent.location=\"/8\"\'><a style=\"font-size:60px\">Bank 8 FIRE!</a></button><br></center></body>");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(PIN5, OUTPUT);
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
  pinMode(PIN8, OUTPUT);

  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, HIGH);
  digitalWrite(PIN5, HIGH);
  digitalWrite(PIN6, HIGH);
  digitalWrite(PIN7, HIGH);
  digitalWrite(PIN8, HIGH);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/1", handleFire1);
  server.on("/2", handleFire2);
  server.on("/3", handleFire3);
  server.on("/4", handleFire4);
  server.on("/5", handleFire5);
  server.on("/6", handleFire6);
  server.on("/7", handleFire7);
  server.on("/8", handleFire8);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
