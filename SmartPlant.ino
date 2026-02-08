#define MOISTURE_SENSOR_PIN 34
#define LED_PIN 25

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int moisture = analogRead(MOISTURE_SENSOR_PIN);

  int moisturePercent = map(moisture, 0, 4095, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  if (moisturePercent < 30) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ALERT: Plant needs water!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}
