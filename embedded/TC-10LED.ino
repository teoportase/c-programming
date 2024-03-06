/*
Light up 10 LEDs based on a preset minimum and maximum temperature.
For example, 0 LEDs for 0-9 degrees Celsius, 1 LED for 10-19 etc.
Tinkercad diagram can be found in the 'assets' folder
*/

// Define pins
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9
#define LED9 10
#define LED10 11
#define temp A0

// Define variables
#define MIN 0
#define MAX 100

void setup()
{
  // Set output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  
  // Set input pins
  pinMode(temp, INPUT);
}

void loop()
{
  // Read the temperature from the sensor by mapping the voltage
  int tempC = map((analogRead(temp) - 20) * 3.04, 0, 1023, -40, 125);
  // Map the number of LEDs that need to be turned on based on temperature
  int nr_leds = map(tempC, MIN, MAX, 0, 10);
  
  // Iterate through the LEDs
  for (int i=LED1; i <= LED10; i++) {
    // If there are still LEDs left to light up
    if(nr_leds > 0) {
      // Light up the current LED
      digitalWrite(i, HIGH);
      // Reduce the number of LEDs that need to be turned on
      nr_leds--;
    }
    // If there are no more LEDs to turn on
    else {
      // Turn off the rest of the LEDs
      digitalWrite(i, LOW);
    }
  }
}