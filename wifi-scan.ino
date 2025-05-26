#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "projeto/agua";

WiFiClient espClient;
PubSubClient client(espClient);

// Telegram
String botToken = "7973485306:AAE6GV6Bw6lqT4SPIv6qHyTSPIDUx-MhwJw";
String chatId = "8069838121";

// Pinos
const int trigPin = 5;
const int echoPin = 18;
const int moisturePin = 36;
const int pumpPin = 2;

void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando-se ao WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println(" conectado!");
    } else {
      Serial.print(" falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura da distância (sensor ultrassônico)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Leitura do sensor de umidade (potenciômetro)
  int moistureValue = analogRead(moisturePin);
  float moisturePercent = map(moistureValue, 0, 4095, 100, 0);

  // Controle da bomba (LED)
  if (moisturePercent < 30 && distance < 10) {
    digitalWrite(pumpPin, HIGH); // Liga bomba
  } else {
    digitalWrite(pumpPin, LOW);  // Desliga bomba
  }

  // Publicação no MQTT
  String payload = "{";
  payload += "\"distancia\":" + String(distance, 2) + ",";
  payload += "\"umidade\":" + String(moisturePercent, 1) + ",";
  payload += "\"bomba\":" + String(digitalRead(pumpPin));
  payload += "}";

  client.publish(mqtt_topic, payload.c_str());
  Serial.println("Publicado: " + payload);

  delay(5000); // Aguarda 5 segundos para próxima leitura
}

