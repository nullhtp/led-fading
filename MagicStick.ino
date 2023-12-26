/**
 * LED Fading Effect for ATtiny13a
 * 
 * This program controls an LED connected to pin PB1 of an ATtiny13a microcontroller.
 * It creates a dynamic fading effect by varying the LED's brightness between random
 * minimum and maximum values. The speed of fading and the delay between brightness changes
 * are also randomly determined.
 * 
 * Pin Configuration:
 * - LED connected to pin PB1.
 * - Analog input for randomness on pin A3 (optional, depends on your randomness needs).
 * 
 * Functions:
 * - generateRandom(int from, int to): Generates a random number within the specified range.
 * - setup(): Initializes the microcontroller settings.
 * - loop(): Contains the main logic for the fading effect.
 */

int ledPin = PB1;        // LED connected to pin PB1
int minValue;            // Minimum brightness level of LED
int maxValue;            // Maximum brightness level of LED

// Function to generate a random number within a range
int generateRandom(int from, int to) {
  int randomValue = analogRead(A3);  // Read analog value from pin A3
  int mappedValue = map(randomValue, 0, 1023, from, to);
  return constrain(mappedValue, from, to);  // Ensure value is within the range
}

void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as output
  minValue = generateRandom(50, 100);  // Initialize minValue with a random value
}

void loop() {
  maxValue = generateRandom(160, 250);      // Set random maximum brightness
  int fadeSpeed = generateRandom(1, 5);     // Set random fade speed
  int fadeDelay = generateRandom(25, 50);   // Set random delay between brightness changes

  // Gradually increase LED brightness from minValue to maxValue
  for (int fadeValue = minValue; fadeValue <= maxValue; fadeValue += fadeSpeed) {
    analogWrite(ledPin, fadeValue);
    delay(fadeDelay);
  }

  // Update minValue for next cycle
  minValue = generateRandom(20, 60);

  // Gradually decrease LED brightness from maxValue to minValue
  for (int fadeValue = maxValue; fadeValue >= minValue; fadeValue -= fadeSpeed) {
    analogWrite(ledPin, fadeValue);
    delay(fadeDelay);
  }
}
