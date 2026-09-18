#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Configurações do Sensor DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Definição dos Pinos de Hardware
#define PIN_AMONIA 34
#define PIN_BOIA_AGUA 18
#define PIN_RELE_CLIMATIZACAO 23

// Parâmetros de Conectividade do CTBJ
const char* ssid = "Rede_CTBJ_Alunos";
const char* password = "SenhaRedeEscola";
const String telegramToken = "BOT_TOKEN_TELEGRAM_AQUI";
const String telegramChatID = "@alertas_pocilga_ctbj";

// Limites Críticos
const float TEMP_LIMITE_CRITICO = 28.0; // °C
const int AMONIA_LIMITE_PPM = 20;

void enviarAlertaTelegram(String mensagem) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + telegramToken + "/sendMessage?chat_id=" + telegramChatID + "&text=" + mensagem;
    http.begin(url);
    int httpCode = http.GET();
    http.end();
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  pinMode(PIN_BOIA_AGUA, INPUT_PULLUP);
  pinMode(PIN_RELE_CLIMATIZACAO, OUTPUT);
  digitalWrite(PIN_RELE_CLIMATIZACAO, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado!");
}

void loop() {
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  int nivelAgua = digitalRead(PIN_BOIA_AGUA); // LOW = Água Normal, HIGH = Falta d'água

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  // Lógica de Acionamento Automático do Sistema de Nebulização/Ventilação
  if (temp >= TEMP_LIMITE_CRITICO) {
    digitalWrite(PIN_RELE_CLIMATIZACAO, HIGH); // Liga Climatização
    enviarAlertaTelegram("🚨 ALERTA CTBJ: Temp alta na Pocilga (" + String(temp) + "°C). Climatizacao ligada!");
  } else {
    digitalWrite(PIN_RELE_CLIMATIZACAO, LOW);  // Desliga Climatização
  }

  // Alerta de Falta d'Água no Bebedouro
  if (nivelAgua == HIGH) {
    enviarAlertaTelegram("⚠️ ALERTA MANEJO: Reservatório/Bebedouro com nível BAIXO de água!");
  }

  delay(30000); // Aguarda 30 segundos para o próximo ciclo
}
