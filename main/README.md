# Terangi Rumahmu - Smart Lighting Control System

This project uses the **ESP8266** to create a simple web-based control system for home lighting. Users can manually control two lights through the web interface or set them to automatic mode based on the environment's light sensor readings.

## Features

- Web-based control interface for switching lights ON or OFF.
- Automatic mode based on light intensity using an **LDR sensor** connected to the ESP8266.
- Password-protected access with session authentication.

## Components Used

- **ESP8266 Module**
- **LDR Sensor** (connected to A0 for reading light intensity)
- **Relay Module** to control the lights
- **Push Button Switches** for manual control
- WiFi connection for remote access

## Circuit Diagram

Connect the components as follows:

1. **A0** - LDR sensor for light detection
2. **GPIO 4** - Relay to control the first light (Saklar 1)
3. **GPIO 5** - Relay to control the second light (Saklar 2)
4. **GPIO 16** - Reserved for other controls

## Web Interface

The system hosts a web interface with two main controls:

- **Auto Mode**: Automatically switch lights ON or OFF based on the LDR sensor reading.
- **Manual Mode**: Toggle lights on or off manually using switches in the web interface.

### Web Interface Design

- Two **switches** for controlling Saklar 1 and Saklar 2.
- The web page updates the light status based on the sensor input or user action.

## Code Explanation

### Setup

The ESP8266 connects to your WiFi network using the provided SSID and password. Once connected, it starts a web server on port 80 and listens for client requests.

```cpp
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}
```

## Root Page

The root page presents two modes: Auto and Manual.

```cpp
static const char PROGMEM rootPage[] = R"rawliteral(
  <html>
  ...
  )rawliteral";

```

## Authentication

To access the control panel, a user must log in using the credentials:

    Username: admin
    Password: 12345

```cpp
if (server.arg("USERNAME") == "admin" && server.arg("PASSWORD") == "12345") {
    // Set session ID and redirect to the control page
}

```

## Light Control Logic

The control logic for the lights uses the following conditions:

- If the sensor value exceeds the threshold, the lights turn ON.
- If it is below the threshold, the lights remain OFF.

```cpp
sensorValue = analogRead(light);
if (sensorValue >= 600) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
} else {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
}

```

## Routes

The following routes are defined:

- / and /login: Handles user login and session management.
- /root/a: Auto mode (sensor-based control).
- /root/m: Manual mode (user toggles the lights).
- /root/m/Saklar1on, /root/m/Saklar1off: Toggle light 1.
- /root/m/Saklar2on, /root/m/Saklar2off: Toggle light 2.

## How to Use

1. Clone this repository or upload the sketch to your ESP8266 module.
2. Connect the ESP8266 to your WiFi by modifying the SSID and password in the code:

```cpp
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

```

3. Open the serial monitor to find the IP address assigned to the ESP8266.
4. Navigate to the IP address in your browser to access the control panel.

## Future Improvements

- Add more security features like HTTPS or stronger password encryption.
- Implement additional sensor data (e.g., temperature, humidity) for smarter control.

## License

This project is open-source and available under the MIT License.
