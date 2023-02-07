#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);
long hour = 23, minute = 59, second = 59;
long countdown_time = (hour*3600) + (minute * 60) + second;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("HH:MM:SS");
}

void loop() {
  long countdowntime_seconds = countdown_time - (millis() / 1000);
  if (countdowntime_seconds >= 0) {
    long countdown_hour = countdowntime_seconds / 3600;
    long countdown_minute = ((countdowntime_seconds / 60)%60);
    long countdown_sec = countdowntime_seconds % 60;
    lcd.setCursor(4, 1);
    if (countdown_hour < 10) {
      lcd.print("0");
    }
    lcd.print(countdown_hour);
    lcd.print(":");
    if (countdown_minute < 10) {
      lcd.print("0");
    }
    lcd.print(countdown_minute);
    lcd.print(":");
    if (countdown_sec < 10) {
      lcd.print("0");
    }
    lcd.print(countdown_sec);
  }
  delay(500);
}