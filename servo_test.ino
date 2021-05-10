#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx=8;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx=9;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);
void setup()
{
          // servo is connected to pin 11 of arduino
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if(bluetooth.available()>0)    //if bluetooth module is transmitting data
  {
    char pos=bluetooth.read(); // store the data in pos variable
    if(pos == 'X') {
        x.attach(11, 600, 2300);  
        x.write(100);
        delay(600);
        x.write(0);
        delay(600);
        x.detach();
                   //move servo head to the given position
    }
    else if(pos == 'Y') {
        x.attach(11, 600, 2300);
        x.write(0);
        delay(600);
        x.detach();
    }
  }
}
