#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float data;
float temp;
void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT);
  dht.begin();
}

void loop() {
  // data = analogRead(A0);
  // temp = data * 0.48828125;
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  lcd.setCursor(0, 0);

  lcd.print("humid:");
  lcd.print(humid);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("temp:");
  lcd.print(temp);
  lcd.print("*c");

  Serial.print("temp:");
  Serial.print(temp);
  Serial.println("*c");

  Serial.print("humid:");
  Serial.print(humid);
  Serial.println("%");


  if (temp < 28) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    lcd.print("warm:)");
  } else {
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);

    lcd.print("cool:(");
  }
  delay(2000);
  lcd.clear();
}
