#define echoPin 2
#define trigPin 3
long duration, distance, ultraSensor;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  sensorUltrasonic(trigPin, echoPin);
  ultraSensor = distance;
  Serial.print("Jarak ");
  Serial.print(ultraSensor);
  Serial.println(" cm");
  delay(1000);
}

void sensorUltrasonic(int pinTrigger, int pinEcho)
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  duration = pulseIn(pinEcho, HIGH);
  distance = (duration / 2) / 29.1;
}
