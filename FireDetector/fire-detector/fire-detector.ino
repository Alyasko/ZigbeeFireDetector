
#define SENSOR_ANALOG_PIN A0
#define SENSOR_THRESHOLD 150
#define AVERAGE_BUFFER_SIZE 50

int avgSum = 0;
int bufferPtr = 0;

void setup()
{
  pinMode(SENSOR_ANALOG_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("Detector initialized.");
}

void loop()
{
  int analogSensor = analogRead(SENSOR_ANALOG_PIN);

  if (bufferPtr < AVERAGE_BUFFER_SIZE)
  {
    avgSum += analogSensor;
    delay(5);
    bufferPtr++;
  }
  else
  {
    int actualSensorValue = avgSum / AVERAGE_BUFFER_SIZE;

    Serial.print("Sensor value: ");
    Serial.println(actualSensorValue);

    if (actualSensorValue >= SENSOR_THRESHOLD)
    {
      Serial.println("Gas/smoke detected!");
    }

    avgSum = 0;
    bufferPtr = 0;
  }
}
