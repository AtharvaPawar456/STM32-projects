int sensorPin = PA0;   // Select the input pin for the potentiometer
int sensorValue = 0; // Variable to store the value coming from the sensor
void setup() {
    pinMode(sensorPin, INPUT_ANALOG);
    Serial.begin(9600);
    Serial.println("wlecome");

}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    delay(2000);
}
