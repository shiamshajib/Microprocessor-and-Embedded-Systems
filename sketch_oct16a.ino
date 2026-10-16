//OEL code of Microprocessor

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
 
// Pin definitions
#define FLAME_PIN 2
#define LED_PIN 8
#define BUTTON_PIN 7
 
bool fire = false;
 
void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
 
  Serial.begin(9600);
 
  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1); // Stop if OLED not found
  }
 
  display.clearDisplay();
  display.setTextColor(WHITE);
}
 
void loop() {
  int flameState = digitalRead(FLAME_PIN);
  int buttonState = digitalRead(BUTTON_PIN);
 
  // Flame detected (LOW)
  if (flameState == LOW) {
    fire = true;
  }
 
  // Reset button
  if (buttonState == LOW) {
    fire = false;
  }
 
  display.clearDisplay();
 
  if (fire) {
    digitalWrite(LED_PIN, HIGH);
    display.setTextSize(2);
    display.setCursor(20, 20);
    display.println("FIRE!");
  } else {
    digitalWrite(LED_PIN, LOW);
    display.setTextSize(1);
    display.setCursor(20, 25);
    display.println("No Fire");
  }
 
  display.display();
  delay(200);
}

