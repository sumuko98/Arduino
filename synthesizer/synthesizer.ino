#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int potPitchPin = A0;  // Potentiometer for pitch
const int potVolPin = A1;    // Potentiometer for volume
const int potWavePin = A2;   // Potentiometer for waveform selection
const int speakerPin = 9;    // Speaker output pin

int pitch = 440;             // Default pitch (Hz)
int volume = 128;            // Default volume (PWM level)
String waveform = "SIN";     // Default waveform type

void setup() {
  lcd.begin(16, 2); // Initialize the LCD for 16x2 characters
  lcd.print("Mini Synth Ready"); // Display a welcome message
  delay(2000); // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  // 1. Read potentiometer values
  int pitchValue = analogRead(potPitchPin);
  int volumeValue = analogRead(potVolPin);
  int waveformValue = analogRead(potWavePin);

  // 2. Map values to desired ranges
  pitch = map(pitchValue, 0, 1023, 50, 2000);     // Map pitch to 50 Hz - 2000 Hz
  volume = map(volumeValue, 0, 1023, 0, 255);     // Map volume to 0 - 255
  int waveType = map(waveformValue, 0, 1023, 0, 2); // Map waveform: 0=Sine, 1=Square, 2=Triangle

  // 3. Select waveform type and generate sound
  if (waveType == 0) {
    waveform = "SIN";  // Display "SIN" for Sine wave
    generateSineWave(pitch, volume);
  } else if (waveType == 1) {
    waveform = "SQR";   // Display "SQR" for Square wave
    generateSquareWave(pitch, volume);
  } else if (waveType == 2) {
    waveform = "TRI";  // Display "TRI" for Triangle wave
    generateTriangleWave(pitch, volume);
  }

  // 4. Update LCD display
  lcd.setCursor(0, 0); // Set cursor to the first row
  lcd.print("Pitch: ");
  lcd.print(pitch);
  lcd.print(" Hz   "); // Ensure the text fits the display

  lcd.setCursor(0, 1); // Set cursor to the second row
  lcd.print("Vol: ");
  lcd.print(volume);
  lcd.print("  Wave: ");
  lcd.print(waveform);

  delay(100); // Small delay to stabilize updates
}

void generateSineWave(int frequency, int amplitude) {
  int period = 1000000 / frequency;
  int halfPeriod = period / 2;
  for (int i = 0; i < amplitude; i++) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void generateSquareWave(int frequency, int amplitude) {
  tone(speakerPin, frequency, amplitude);
  delay(1000 / frequency); // Adjust duration to match frequency
}

void generateTriangleWave(int frequency, int amplitude) {
  int period = 1000000 / frequency;
  int halfPeriod = period / 2;
  for (int i = 0; i < amplitude; i++) {
    analogWrite(speakerPin, i); // Ramp up
    delayMicroseconds(halfPeriod / 255);
  }
  for (int i = amplitude; i > 0; i--) {
    analogWrite(speakerPin, i); // Ramp down
    delayMicroseconds(halfPeriod / 255);
  }
}
