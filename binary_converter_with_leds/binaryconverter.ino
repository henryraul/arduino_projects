#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int ledPin7 =  53;
const int ledPin6 =  51;
const int ledPin5 =  49;
const int ledPin4 =  47;
const int ledPin3 =  29;
const int ledPin2 =  27;
const int ledPin1 =  25;
const int ledPin0 =  23;

const long interval = 1000;  

int bit_pins[] = {23, 25, 27, 29, 47, 49, 51, 53};

byte number = 0;    

bool check_bit(byte pos_bit, byte number){
  byte medidor = pow(pos_bit, 2);
  return ((number & medidor)>0);
}

void show_bits(byte number){
  for (byte i = 0; i < 8; i = i + 1) {
    if (bitRead(number,i)){
        digitalWrite(bit_pins[i], HIGH);
      }else{
        digitalWrite(bit_pins[i], LOW);
      }
    }
}   

void setup() {
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin0, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  show_bits(number);
  lcd.setCursor(0, 1);
  lcd.print(number);
  
  if (number>255){
    number = 253;
  }else{
    number = number + 1;
  }
  
  delay(interval);
  lcd.clear();
}
