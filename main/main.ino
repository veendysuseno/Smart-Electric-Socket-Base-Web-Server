#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define NUM_SWITCHES 10
int saklarPin[NUM_SWITCHES] = {D1, D2, D3, D4, D5, D6, D7, D8, D9, D10};

// Replace with your network credentials
const char* ssid = "MAI";
const char* password = "Adm1n12345";

ESP8266WebServer server(80);

// Function to send switch status to the server
void sendSwitchStatus(int switchNumber, const char* status) {
    WiFiClient client;
    String url = String("http://localhost/update_switch.php?switch=") + switchNumber + "&status=" + status;

    if (client.connect("192.168.11.200", 80)) { // Use the local IP of your XAMPP server
        client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + "192.168.1.100" + "\r\n" + "Connection: close\r\n\r\n");
        delay(500); // Wait for response
    } else {
        Serial.println("Connection failed");
    }
}

// Handler for Saklar 1 ON
void handleSaklar1On() {
    digitalWrite(saklarPin[0], LOW);
    Serial.println("Saklar 1 ON");
    sendSwitchStatus(1, "on");
}

// Handler for Saklar 1 OFF
void handleSaklar1Off() {
    digitalWrite(saklarPin[0], HIGH);
    Serial.println("Saklar 1 OFF");
    sendSwitchStatus(1, "off");
}

// Handler for Saklar 2 ON
void handleSaklar2On() {
    digitalWrite(saklarPin[1], LOW);
    Serial.println("Saklar 2 ON");
    sendSwitchStatus(2, "on");
}

// Handler for Saklar 2 OFF
void handleSaklar2Off() {
    digitalWrite(saklarPin[1], HIGH);
    Serial.println("Saklar 2 OFF");
    sendSwitchStatus(2, "off");
}

// Handler for Saklar 3 ON
void handleSaklar3On() {
    digitalWrite(saklarPin[2], LOW);
    Serial.println("Saklar 3 ON");
    sendSwitchStatus(3, "on");
}

// Handler for Saklar 3 OFF
void handleSaklar3Off() {
    digitalWrite(saklarPin[2], HIGH);
    Serial.println("Saklar 3 OFF");
    sendSwitchStatus(3, "off");
}

// Handler for Saklar 4 ON
void handleSaklar4On() {
    digitalWrite(saklarPin[3], LOW);
    Serial.println("Saklar 4 ON");
    sendSwitchStatus(4, "on");
}

// Handler for Saklar 4 OFF
void handleSaklar4Off() {
    digitalWrite(saklarPin[3], HIGH);
    Serial.println("Saklar 4 OFF");
    sendSwitchStatus(4, "off");
}

// Handler for Saklar 5 ON
void handleSaklar5On() {
    digitalWrite(saklarPin[4], LOW);
    Serial.println("Saklar 5 ON");
    sendSwitchStatus(5, "on");
}

// Handler for Saklar 5 OFF
void handleSaklar5Off() {
    digitalWrite(saklarPin[4], HIGH);
    Serial.println("Saklar 5 OFF");
    sendSwitchStatus(5, "off");
}

// Handler for Saklar 6 ON
void handleSaklar6On() {
    digitalWrite(saklarPin[5], LOW);
    Serial.println("Saklar 6 ON");
    sendSwitchStatus(6, "on");
}

// Handler for Saklar 6 OFF
void handleSaklar6Off() {
    digitalWrite(saklarPin[5], HIGH);
    Serial.println("Saklar 6 OFF");
    sendSwitchStatus(6, "off");
}

// Handler for Saklar 7 ON
void handleSaklar7On() {
    digitalWrite(saklarPin[6], LOW);
    Serial.println("Saklar 7 ON");
    sendSwitchStatus(7, "on");
}

// Handler for Saklar 7 OFF
void handleSaklar7Off() {
    digitalWrite(saklarPin[6], HIGH);
    Serial.println("Saklar 7 OFF");
    sendSwitchStatus(7, "off");
}

// Handler for Saklar 8 ON
void handleSaklar8On() {
    digitalWrite(saklarPin[7], LOW);
    Serial.println("Saklar 8 ON");
    sendSwitchStatus(8, "on");
}

// Handler for Saklar 8 OFF
void handleSaklar8Off() {
    digitalWrite(saklarPin[7], HIGH);
    Serial.println("Saklar 8 OFF");
    sendSwitchStatus(8, "off");
}

// Handler for Saklar 9 ON
void handleSaklar9On() {
    digitalWrite(saklarPin[8], LOW);
    Serial.println("Saklar 9 ON");
    sendSwitchStatus(9, "on");
}

// Handler for Saklar 9 OFF
void handleSaklar9Off() {
    digitalWrite(saklarPin[8], HIGH);
    Serial.println("Saklar 9 OFF");
    sendSwitchStatus(9, "off");
}

// Handler for Saklar 10 ON
void handleSaklar10On() {
    digitalWrite(saklarPin[9], LOW);
    Serial.println("Saklar 10 ON");
    sendSwitchStatus(10, "on");
}

// Handler for Saklar 10 OFF
void handleSaklar10Off() {
    digitalWrite(saklarPin[9], HIGH);
    Serial.println("Saklar 10 OFF");
    sendSwitchStatus(10, "off");
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");

    // Initialize all GPIO for switches
    for (int i = 0; i < NUM_SWITCHES; i++) {
        pinMode(saklarPin[i], OUTPUT);
        digitalWrite(saklarPin[i], HIGH); // Switches off initially
    }

    // Route handlers
    server.on("/login", handleLogin);
    server.on("/root", handleRoot);
    server.on("/root/m/Saklar1on", handleSaklar1On);
    server.on("/root/m/Saklar1off", handleSaklar1Off);
    server.on("/root/m/Saklar2on", handleSaklar2On);
    server.on("/root/m/Saklar2off", handleSaklar2Off);
    server.on("/root/m/Saklar3on", handleSaklar3On);
    server.on("/root/m/Saklar3off", handleSaklar3Off);
    server.on("/root/m/Saklar4on", handleSaklar4On);
    server.on("/root/m/Saklar4off", handleSaklar4Off);
    server.on("/root/m/Saklar5on", handleSaklar5On);
    server.on("/root/m/Saklar5off", handleSaklar5Off);
    server.on("/root/m/Saklar6on", handleSaklar6On);
    server.on("/root/m/Saklar6off", handleSaklar6Off);
    server.on("/root/m/Saklar7on", handleSaklar7On);
    server.on("/root/m/Saklar7off", handleSaklar7Off);
    server.on("/root/m/Saklar8on", handleSaklar8On);
    server.on("/root/m/Saklar8off", handleSaklar8Off);
    server.on("/root/m/Saklar9on", handleSaklar9On);
    server.on("/root/m/Saklar9off", handleSaklar9Off);
    server.on("/root/m/Saklar10on", handleSaklar10On);
    server.on("/root/m/Saklar10off", handleSaklar10Off);
    server.begin();
}

void loop() {
    server.handleClient();
}
