#include "WiFi.h"
#include "HTTPClient.h"
#include "DHT.h"

// -------------------- WIFI --------------------
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// -------------------- THINGSPEAK --------------------
String apiKey = "YOUR_THINGSPEAK_API_KEY";

// -------------------- DHT SENSOR --------------------
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// -------------------- MQ SENSOR --------------------
#define MQ2PIN 34

void setup() {

  Serial.begin(115200);

  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());
}

void loop() {

  // Read DHT Values
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read MQ Sensor
  int gasValue = analogRead(MQ2PIN);

  // Print Values
  Serial.println("------ SENSOR DATA ------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Send Data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(gasValue);

    http.begin(url);

    int httpResponseCode = http.GET();

    Serial.print("ThingSpeak Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  Serial.println("--------------------------");

  delay(20000);
}
