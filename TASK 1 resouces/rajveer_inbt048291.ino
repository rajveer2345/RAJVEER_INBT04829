const int gasSensorPin = A0; // Analog pin for the gas sensor
const int buzzerPin = 2;     // Digital pin for the buzzer
const int ledPin = 3;        // Digital pin for the LED

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);

  // Check if the gas sensor detects gas (adjust threshold as needed)
  if (gasValue > 500) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH);    // Turn on the LED
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);
    Serial.println("SMOKE DETECTED");
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    digitalWrite(ledPin, LOW);     // Turn off the LED
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);
    Serial.println("SMOKE NOT DETECTED");
  }

  delay(1000); // Adjust the delay as needed
}

