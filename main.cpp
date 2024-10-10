#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int batteryLevel = 75; 
int speed = 20; 

void setup() {
  lcd.begin();
  lcd.backlight();
  displayInitialMessage();
}

void loop() {
  updateDisplay();
  delay(1000); 
}

void displayInitialMessage() {
  lcd.setCursor(0, 0);
  lcd.print("Welcome to E-Bike");
  lcd.setCursor(0, 1);
  lcd.print("Ready to Ride!");
  delay(2000);
  lcd.clear();
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Battery: ");
  lcd.print(batteryLevel);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(speed);
  lcd.print(" km/h");

  batteryLevel -= 1; 
  speed += 1; 
  if (batteryLevel < 0) batteryLevel = 100; 
  if (speed > 50) speed = 0; 
}
