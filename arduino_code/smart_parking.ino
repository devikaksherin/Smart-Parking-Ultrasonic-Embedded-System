#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Ultrasonic sensor pins
int trigPins[4] = {5, 16, 27, 25};
int echoPins[4] = {17, 4, 26, 33};

// LED pins
int greenLED[4] = {12, 14, 32, 15};
int redLED[4]   = {2, 13, 23, 18};

// Buzzer pin
int buzzer = 19;

// Distance threshold in cm
float threshold = 35.0;

// Function to read distance
float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return 999;

  float distance = duration * 0.0343 / 2.0;
  return distance;
}

void setup() {
  Serial.begin(115200);

  // Sensor and LED pin setup
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);

    pinMode(greenLED[i], OUTPUT);
    pinMode(redLED[i], OUTPUT);

    digitalWrite(greenLED[i], HIGH); // Initially free
    digitalWrite(redLED[i], LOW);
  }

  pinMode(buzzer, OUTPUT);

  // OLED setup
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool occupied[4];
  int freeCount = 0;

  // Read all sensors
  for (int i = 0; i < 4; i++) {

    float distance = readDistance(trigPins[i], echoPins[i]);

    if (distance < threshold) {
      occupied[i] = true;

      digitalWrite(redLED[i], HIGH);
      digitalWrite(greenLED[i], LOW);

    } else {
      occupied[i] = false;

      digitalWrite(redLED[i], LOW);
      digitalWrite(greenLED[i], HIGH);

      freeCount++;
    }

    // Serial output
    Serial.print("Slot ");
    Serial.print(i + 1);
    Serial.print(": ");

    if (occupied[i])
      Serial.print("OCCUPIED");
    else
      Serial.print("FREE");

    Serial.print(" (");
    Serial.print(distance);
    Serial.println(" cm)");
  }

  Serial.print("Available Slots: ");
  Serial.println(freeCount);
  Serial.println("----------------------");

  // OLED display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("Free Slots: ");
  display.println(freeCount);

  for (int i = 0; i < 4; i++) {
    display.setCursor(0, 16 + i * 10);

    display.print("S");
    display.print(i + 1);
    display.print(": ");

    if (occupied[i])
      display.print("OCC");
    else
      display.print("FREE");
  }

  display.display();

  // Parking full buzzer
  if (freeCount == 0) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}
