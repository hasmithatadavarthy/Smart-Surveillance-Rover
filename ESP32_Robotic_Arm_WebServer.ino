#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// -------------------- WIFI ACCESS POINT --------------------
const char* ssid = "ESP32_Robot_Arm";
const char* password = "12345678";

WebServer server(80);

// -------------------- SERVOS --------------------
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// -------------------- SERVO PINS --------------------
#define SERVO1_PIN 13
#define SERVO2_PIN 12
#define SERVO3_PIN 14
#define SERVO4_PIN 27

int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;

void setup() {

  Serial.begin(115200);

  // Attach Servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  // Initial Position
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);

  // Create WiFi Hotspot
  WiFi.softAP(ssid, password);

  Serial.println("WiFi Hotspot Started");
  Serial.println(WiFi.softAPIP());

  // Web Routes
  server.on("/", handleRoot);

  server.on("/s1left", []() {
    pos1 -= 10;
    servo1.write(pos1);
    server.send(200, "text/plain", "Servo1 Left");
  });

  server.on("/s1right", []() {
    pos1 += 10;
    servo1.write(pos1);
    server.send(200, "text/plain", "Servo1 Right");
  });

  server.on("/s2left", []() {
    pos2 -= 10;
    servo2.write(pos2);
    server.send(200, "text/plain", "Servo2 Left");
  });

  server.on("/s2right", []() {
    pos2 += 10;
    servo2.write(pos2);
    server.send(200, "text/plain", "Servo2 Right");
  });

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}

// -------------------- WEB PAGE --------------------
void handleRoot() {

  String html = R"rawliteral(

  <!DOCTYPE html>
  <html>
  <head>
      <title>ESP32 Robotic Arm</title>
      <style>
          body {
              text-align:center;
              font-family:Arial;
              background:#f2f2f2;
          }

          button {
              width:150px;
              height:50px;
              margin:10px;
              font-size:18px;
          }
      </style>
  </head>

  <body>

      <h1>ESP32 Robotic Arm</h1>

      <h2>Servo 1</h2>
      <a href="/s1left"><button>LEFT</button></a>
      <a href="/s1right"><button>RIGHT</button></a>

      <h2>Servo 2</h2>
      <a href="/s2left"><button>LEFT</button></a>
      <a href="/s2right"><button>RIGHT</button></a>

  </body>
  </html>

  )rawliteral";

  server.send(200, "text/html", html);
}
