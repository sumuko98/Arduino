# Arduino_project

**
The Arduino code for this project can be found in the synthesizer.ino file in this repository.
**
Features/
Pitch Control: Adjust the frequency of the sound from deep bass to high-pitched tones.
Volume Control: Change the amplitude of the sound output.
Waveform Selection: Choose between three different waveforms:
Sine wave – Smooth and natural sound.
Square wave – Sharp, electronic tone with stronger harmonics.
Triangle wave – A mix of smooth and sharp sound.
Real-Time LCD Display: Shows the current pitch, volume, and waveform type as you adjust them using potentiometers.

Hardware Requirements/
Arduino Uno (or compatible board)
10kΩ Potentiometers – 3 pieces (for pitch, volume, and waveform control)
16x2 LCD Panel (with or without I2C adapter)
Small Speaker 
Breadboard and Jumper Wires

Wiring Guide/
Potentiometers:
Pitch Control: Connect the wiper (middle pin) of the first potentiometer to A0.
Volume Control: Connect the wiper of the second potentiometer to A1.
Waveform Selection: Connect the wiper of the third potentiometer to A2.
For all potentiometers:
Connect one outer pin to 5V.
Connect the other outer pin to GND.
Speaker:
Connect one terminal of the speaker to GND.
Connect the other terminal to digital pin 9 on the Arduino.
LCD Panel:
Connect the LCD panel as per the standard configuration:
RS → Pin 12 on Arduino.
E → Pin 11 on Arduino.
D4, D5, D6, D7 → Pins 5, 4, 3, 2 on Arduino, respectively.
VSS → GND.
VDD → 5V.
V0 (contrast) → Middle pin of a 10k potentiometer, with the other two pins connected to 5V and GND.
A (Anode) → 5V (via a 220Ω resistor for backlight).
K (Cathode) → GND.


Real-Time LCD Display: Shows the current pitch, volume, and waveform type as you adjust them using potentiometers.
