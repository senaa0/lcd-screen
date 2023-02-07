
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

int trigger = 7;
int echo = 6;
int boy = 0;
double zaman;
double toplamYol;
int mesafe;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  zaman = pulseIn(echo, HIGH);
  toplamYol=zaman*0.034;
  mesafe=toplamYol / 2;
  boy=200 - mesafe;
  lcd.home();
  lcd.print("Boyunuz:");
  lcd.setCursor(0,1);
  lcd.print(boy);
  lcd.setCursor(10,1);
  lcd.print("cm");
  delay(100);
}
