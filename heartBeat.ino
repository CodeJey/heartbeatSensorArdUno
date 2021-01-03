#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int LED11 = 13;
int reader;
int realData;
void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(LED11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reader = analogRead(0) - 550;
  realData = reader/10;
  lcd.setCursor(0, 0);
    lcd.print("value: " + realData);
  if (realData >=30 && realData <=44)
    {
      Serial.println(realData);
      delay(1000);
      Serial.println(realData);
      digitalWrite(LED11, HIGH);
      delay(100);
      digitalWrite(LED11, LOW);
    }
    else if(realData >= 45)
    {
      Serial.println(realData);
      digitalWrite(LED11, HIGH);
    }
    else 
    {
      Serial.println(realData);
      digitalWrite(LED11, HIGH);
    }
    lcd.setCursor(0,0);
    lcd.print("Value:");
    lcd.setCursor(0,1);
    lcd.print(realData);
  delay(40);
}
