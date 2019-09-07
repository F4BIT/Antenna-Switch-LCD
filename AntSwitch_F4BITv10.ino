#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address on A4-A5

const int PIN_BUTTON7 = A7; //reset
const int PIN_BUTTON1 = A0; //antenna 1
const int PIN_BUTTON2 = A1; //antenna 2
const int PIN_BUTTON3 = A2; //antenna 3
const int PIN_BUTTON4 = A3; //antenne 4
const int relay1 = 2; // relay antenna 1
const int relay2 = 3; // relay antenna 2
const int relay3 = 4; // relay antenna 3
const int relay4 = 5; // relay antenna 4
int buttonState = 0; // variable for reading the pushbutton status
unsigned int Data;
// initialize antenna name
char antenna1[12]=  "Antenne 1";
char antenna2[12] = "Antenne 2";
char antenna3[12] = "Antenne 3";
char antenna4[12] = "Antenne 4";
void setup()
{
// initialize the relay1,2,3,4 pins as an output:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

//initialize communication  
  Serial.begin(9600);
  
// initialize all relay OFF
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);

// initialize the lcd
  lcd.init(); 
  
// Print a startup message to the LCD.
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Antenna Switch");
  lcd.setCursor(7, 1);
  lcd.print("v 1.0");
  lcd.setCursor(3, 3);
  lcd.print("F4BIT / KW4BIT");
}

/* Main program */
void loop()
{


  if (hasBeenPressed(PIN_BUTTON7)) {
    Data = 7;
    Serial.println(Data);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("RESET "); // View on LCD
    lcd.setCursor(0, 3);
    lcd.print("..........");
    delay(500);
    lcd.clear();
  }
  if (Data == 7) {
    Serial.println(Data);
    digitalWrite(13, HIGH);
    delay(800);

    lcd.setCursor(3, 0);
    lcd.print("Antenna Switch");
    lcd.setCursor(7, 1);
    lcd.print("v 1.0");
    lcd.setCursor(3, 3);
    lcd.print("F4BIT / KW4BIT");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
  }
  if (hasBeenPressed(PIN_BUTTON1)) {
    Data = 1;
    Serial.println(Data);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(antenna1); // View on LCD
    lcd.setCursor(0, 3);
    lcd.print("Check..........");
    delay(1000);
    lcd.clear();
  }
  if (Data == 1) {
    Serial.println(Data);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    lcd.setCursor(0, 1);
    lcd.print(antenna1); //
    lcd.setCursor(0, 3);
    lcd.print("******** OK ********");

    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);


  }
  if (hasBeenPressed(PIN_BUTTON2)) {
    Data = 2;
    Serial.println(Data);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(antenna2); // View on LCD
    lcd.setCursor(0, 3);
    lcd.print("Check..........");
    delay(1000);
    lcd.clear();
  }
  if (Data == 2) {
    Serial.println(Data);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    lcd.setCursor(0, 1);
    lcd.print(antenna2); //
    lcd.setCursor(0, 3);
    lcd.print("******** OK ********");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);

  }
  if (hasBeenPressed(PIN_BUTTON3)) {
    Data = 3;
    Serial.println(Data);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(antenna3); // View on LCD
    lcd.setCursor(0, 3);
    lcd.print("Check..........");
    delay(1000);
    lcd.clear();
  }
  if (Data == 3) {
    Serial.println(Data);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    lcd.setCursor(0, 1);
    lcd.print(antenna3); //
    lcd.setCursor(0, 3);
    lcd.print("******** OK ********");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, HIGH);
  }
  if (hasBeenPressed(PIN_BUTTON4)) {
    Data = 4;
    Serial.println(Data);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(antenna4); // View on LCD
    lcd.setCursor(0, 3);
    lcd.print("Check..........");
    delay(1000);
    lcd.clear();
  }
  if (Data == 4) {
    Serial.println(Data);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    lcd.setCursor(0, 1);
    lcd.print(antenna4); //
    lcd.setCursor(0, 3);
    lcd.print("******** OK ********");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, LOW);
  }

}

boolean hasBeenPressed(int pin) {
  if (analogRead(pin) > 1000) {
    return true;
  } else {
    return false;
  }
}
