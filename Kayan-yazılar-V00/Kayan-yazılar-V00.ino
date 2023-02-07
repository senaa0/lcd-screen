
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 3, 2, 1, 0);
byte karakter[8] = { 0x0, 0xE, 0x11, 0x10, 0x11, 0xE, 0x4, 0x0 };
void setup()
{
	lcd.begin(16, 2);
	lcd.createChar(0, karakter);
	lcd.clear();
	lcd.write(byte(0));
}
void loop()
{
}