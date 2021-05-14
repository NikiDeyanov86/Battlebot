#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx = 8;  //tx of bluetooth module is connected to pin 8 of arduino
int btrx = 9;  //rx of bluetooth module is connected to pin 9 of arduino
SoftwareSerial bluetooth(bttx, btrx);

int pos = 0;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if (bluetooth.available() > 0) //if bluetooth module is transmitting data
  {
    pos = bluetooth.read(); // store the data in pos variable
    if (pos == '1') {
      Serial.println("Weapon activated!");
      x.attach(11, 600, 2300);     // servo is attached to pin 11 of arduino
      x.write(45);     // action
      delay(600);
      x.write(0);       // return to normal state
      delay(600);
      x.detach();       // the servo is detached so it doesn't consume battery's energy
      Serial.println("Weapon deactivated!");
    }
    else if (pos == '0') {
      Serial.println("Weapon centralized!");
      x.attach(11, 600, 2300);
      x.write(0);      // the servo is centralized to its normal state
      delay(600);
      x.detach();    // the servo is detached so it doesn't consume battery's energy
    }
  }
}
