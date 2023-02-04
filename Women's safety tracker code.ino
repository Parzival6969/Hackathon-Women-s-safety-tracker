
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
char msg;
char call;
int buttonpin=5;
int buzzer=6;
void setup()
{
  pinMode(buttonpin,INPUT);
  pinMode(buzzer,OUTPUT);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);// Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("SOS");
}

void loop()
{
  if(digitalRead(buttonpin)==LOW)
  {
    
    Serial.println("SOS");
    delay(2000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    mySerial.write("ATD+919535177004;\r\n");
    delay(20000);
    mySerial.write("ATH\r\n");
    SendMessage();  
  }

 if (mySerial.available()>0)
 Serial.write(mySerial.read());



}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second

  mySerial.println("AT+CMGS=\"+919535177004\"\r"); // Replace x with mobile number
  delay(1000);

  mySerial.println("Emergency , 12.9716 , 77.5946");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
