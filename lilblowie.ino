//Lil' Blowie an ESP8266, 8 bank, wifi fireworks launcher.
#include <ESP8266WiFi.h>

const char* ssid = "yourssid";
const char* password = "yourpassword";

WiFiServer server(80);

void setup() {
Serial.begin(115200);
delay(1);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(0, OUTPUT);
pinMode(2, OUTPUT);
pinMode(14, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(15, OUTPUT);

digitalWrite(5, HIGH);
digitalWrite(4, HIGH);
digitalWrite(0, HIGH);
digitalWrite(2, HIGH);
digitalWrite(14, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
digitalWrite(15, HIGH);

// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

// Start the server
server.begin();
Serial.println("Server started");

// Print the IP address
Serial.print("Use this URL to connect: ");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");
}

void loop() {
// Check if a client has connected
WiFiClient client = server.available();
if (!client) {
return;
}

// Wait until the client sends some data
Serial.println("new client");
while(!client.available()){
delay(10);
}

// Read the first line of the request
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();

// Fire Ze fucking missiles!
if (request.indexOf("/LB=1") != -1) {
Serial.print("Firing 1");
digitalWrite(5, LOW);
delay(1000);
digitalWrite(5, HIGH);
}

if (request.indexOf("/LB=2") != -1) {
Serial.print("Firing 2");
digitalWrite(4, LOW);
delay(1000);
digitalWrite(4, HIGH);
}

if (request.indexOf("/LB=3") != -1) {
Serial.print("Firing 3");
digitalWrite(0, LOW);
delay(1000);
digitalWrite(0, HIGH);
}
if (request.indexOf("/LB=4") != -1) {
Serial.print("Firing 4");
digitalWrite(2, LOW);
delay(1000);
digitalWrite(2, HIGH);
}
if (request.indexOf("/LB=5") != -1) {
Serial.print("Firing 5");
digitalWrite(14, LOW);
delay(1000);
digitalWrite(14, HIGH);
}
if (request.indexOf("/LB=6") != -1) {
Serial.print("Firing 6");
digitalWrite(12, LOW);
delay(1000);
digitalWrite(12, HIGH);
}
if (request.indexOf("/LB=7") != -1) {
Serial.print("Firing 7");
digitalWrite(13, LOW);
delay(1000);
digitalWrite(13, HIGH);
}
if (request.indexOf("/LB=8") != -1) {
Serial.print("Firing 8");
digitalWrite(15, LOW);
delay(1000);
digitalWrite(15, HIGH);
}



// Return the response
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<body style=\"background-color:red;\">");
client.println("<br><br>");

client.println("<center><font face=\"helvetica\"><a style=\"font-size:90px\"><b>Lil' Blowie &trade;</b><br></font></a>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=1'\"><a style=\"font-size:60px\">Bank 1 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=2'\"><a style=\"font-size:60px\">Bank 2 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=3'\"><a style=\"font-size:60px\">Bank 3 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=4'\"><a style=\"font-size:60px\">Bank 4 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=5'\"><a style=\"font-size:60px\">Bank 5 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=6'\"><a style=\"font-size:60px\">Bank 6 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=7'\"><a style=\"font-size:60px\">Bank 7 FIRE!</a></button><br>");
client.println("<button style=\"height:160px;width:400px\" type=\"button\" onClick=\"parent.location='/LB=8'\"><a style=\"font-size:60px\">Bank 8 FIRE!</a></button><br></center>");
client.println("");
client.println("</body>");
client.println("</html>");

delay(10);
Serial.println("Client disonnected");
Serial.println("");

}
