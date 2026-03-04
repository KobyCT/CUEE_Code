#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define MY_ADDRESS 10
#define OTHER 20
#define ZERO 4
#define ONE 7 

int msg;
String sendMsg;
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Receive: ");
  lcd.setCursor(0, 1);
  lcd.print("Send: ");
}
void loop() {

  while(Serial.available()>0){
    char receiveMsg = Serial.read();
    if (receiveMsg=='1'){
      lcd.setCursor(8, 0);
      lcd.print("1");
      
      }else if (receiveMsg=='0'){
      lcd.setCursor(8, 0);
      lcd.print("0");
    }}
  
  if ((digitalRead(ZERO)==HIGH)&&(digitalRead(ONE)==HIGH)){
    msg = -1;
    }else if (digitalRead(ZERO)==HIGH){
      msg=0;
      Serial.println(msg);}
     else if (digitalRead(ONE)==HIGH){
      msg = 1;
      Serial.println(msg);
     }else{msg=-1;}
  if (msg != -1){
  lcd.setCursor(5, 1);
  lcd.print(msg);
  }
  delay(100);

}
