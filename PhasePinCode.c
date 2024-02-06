
const int VPHASE_PIN = A1;
const float referenceVoltage = 3.3;  // Use the 3.3V reference voltage of the Arduino
const unsigned long duration = 5000;

void setup() {
  pinMode(VPHASE_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int rawValue = analogRead(VPHASE_PIN);
  float voltage = rawValue * (referenceVoltage / 1023.0);

  // Normalize the phase difference between 0 and 180 degrees
  //float phaseDifference = map(voltage, 0, 1.8, 180, 0);  // Adjusted for cyclical behavior
  float phaseDifference = 180.0 - (voltage - 0.03) / (1.8 - 0.03) * 180.0;

  // Handle cyclical behavior for phase difference
  if (voltage > 1.8) {
    phaseDifference = 0.0000000;

  }

  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);

  Serial.print(" V | Phase Difference: ");
  Serial.print(phaseDifference, 2);
  Serial.println(" degrees");

  delay(1000);
}
