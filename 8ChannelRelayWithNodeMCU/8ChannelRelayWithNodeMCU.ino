#include <ESP8266WiFi.h>

// Wi-Fi credentials
const char* ssid = "xxxxx";
const char* password = "xxxxxx";

// Define relay pins for NodeMCU
const int relayPins[8] = {D1, D2, D3, D4, D5, D6, D7, D8};

WiFiServer server(80);

int relayStates[8] = {0};  // 0 = OFF, 1 = ON

void setup() {
  Serial.begin(115200);

  // Start Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();

  // Initialize relay pins and set all relays OFF
  for (int i = 0; i < 8; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH);  // Set relay OFF
    relayStates[i] = 0;
  }
}

void handleClientRequest(WiFiClient client, String request) {
  String endpoint = request.substring(0, request.indexOf(' '));
  String path = request.substring(request.indexOf(' ') + 1, request.lastIndexOf(' '));
  
  Serial.println("Request Path: " + path);

  if (path == "/relay") {
    sendWebPage(client);  // Show home page
  } else if (path.startsWith("/relay")) {
    int relayNumber = path.charAt(7) - '0';  // Extract relay number from URL
    String action = path.substring(9);       // Extract action (ON/OFF)

    if (relayNumber >= 1 && relayNumber <= 8) {
      int pin = relayNumber - 1;
      if (action == "ON") {
        digitalWrite(relayPins[pin], LOW);  // Turn relay ON
        relayStates[pin] = 1;
        Serial.println("Relay " + String(relayNumber) + " is ON");
      } else if (action == "OFF") {
        digitalWrite(relayPins[pin], HIGH); // Turn relay OFF
        relayStates[pin] = 0;
        Serial.println("Relay " + String(relayNumber) + " is OFF");
      }
      sendWebPage(client);
    } else if (path == "/relay/all/ON") {
      for (int i = 0; i < 8; i++) {
        digitalWrite(relayPins[i], LOW);  // Turn all relays ON
        relayStates[i] = 1;
      }
      Serial.println("All relays are ON");
      sendWebPage(client);
    } else if (path == "/relay/all/OFF") {
      for (int i = 0; i < 8; i++) {
        digitalWrite(relayPins[i], HIGH); // Turn all relays OFF
        relayStates[i] = 0;
      }
      Serial.println("All relays are OFF");
      sendWebPage(client);
    }
  }
}

void sendWebPage(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<head>");
  client.println("<style>");
  client.println(".grid-container {");
  client.println("  display: grid;");
  client.println("  grid-template-columns: repeat(8, auto);");
  client.println("  gap: 10px;");
  client.println("  background-color: rgb(255, 255, 255);");
  client.println("  padding: 10px;");
  client.println("  border-width: 0;");
  client.println("}");
  client.println(".grid-container > div {");
  client.println("  background-color: rgba(255, 255, 255, 0.8);");
  client.println("  border: 1px solid black;");
  client.println("  text-align: center;");
  client.println("  font-size: 20px;");
  client.println("  padding: 10px;");
  client.println("}");
  client.println(".button1 {");
  client.println("  background-color: #04AA6D; /* Green */");
  client.println("  border: none;");
  client.println("  color: white;");
  client.println("  padding: 20px;");
  client.println("  text-align: center;");
  client.println("  text-decoration: none;");
  client.println("  display: inline-block;");
  client.println("  font-size: 16px;");
  client.println("  margin: 4px 2px;");
  client.println("  cursor: pointer;");
  client.println("  border-radius: 4px;");
  client.println("}");
  client.println(".button2 {");
  client.println("  background-color: rgb(255, 0, 0); /* Red */");
  client.println("  border: none;");
  client.println("  color: white;");
  client.println("  padding: 20px;");
  client.println("  text-align: center;");
  client.println("  text-decoration: none;");
  client.println("  display: inline-block;");
  client.println("  font-size: 16px;");
  client.println("  margin: 4px 2px;");
  client.println("  cursor: pointer;");
  client.println("  border-radius: 4px;");
  client.println("}");
  client.println(".button1.disabled {");
  client.println("  background-color: #d3d3d3;");
  client.println("  color: #a9a9a9;");
  client.println("  cursor: not-allowed;");
  client.println("}");
  client.println(".button2.disabled {");
  client.println("  background-color: #d3d3d3;");
  client.println("  color: #a9a9a9;");
  client.println("  cursor: not-allowed;");
  client.println("}");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1 style=\"text-align: center\">8 Channel Relay with NODE MCU</h1>");
  
  client.println("<div class=\"grid-container\">");

  // Relay labels
  for (int i = 1; i <= 8; i++) {
    client.println("<div>Relay " + String(i) + "</div>");
  }

  // Relay ON buttons
  for (int i = 1; i <= 8; i++) {
    String onButtonClass = relayStates[i-1] == 1 ? "button1 disabled" : "button1";
    client.println("<div><a href=\"/relay/" + String(i) + "/ON\" class=\"" + onButtonClass + "\">ON</a></div>");
  }

  // Relay OFF buttons
  for (int i = 1; i <= 8; i++) {
    String offButtonClass = relayStates[i-1] == 0 ? "button2 disabled" : "button2";
    client.println("<div><a href=\"/relay/" + String(i) + "/OFF\" class=\"" + offButtonClass + "\">OFF</a></div>");
  }

  client.println("</div>");  // Close grid-container
  client.println("</body>");
  client.println("</html>");
}


void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();
    
    // Handle the client request
    handleClientRequest(client, request);
    
    // Close the connection
    client.stop();
  }
}
