
#define SENSOR_DIGITAL_PIN 2

int data = HIGH;

void setup() {
  pinMode(SENSOR_DIGITAL_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("Flame detector initialized.");
}

void loop()
{
  data = digitalRead(SENSOR_DIGITAL_PIN);
  if (data == LOW) {
    Serial.println("Flame detected!");
  }
  delay(100);
}
