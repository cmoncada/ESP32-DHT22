
#include <DHT.h>

#define DHTPIN 15   // El pin al que está conectado el sensor DHT11 en el ESP32 (cambia según tu configuración)
#define DHTTYPE DHT22   // Tipo de sensor (DHT11, DHT22, AM2302, etc.)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);  // Pausa de 2 segundos entre lecturas

  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C, Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");
}