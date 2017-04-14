/*
The algorithm of the program is as follows:
1. It checks whether the GPS is available or not
2. If available then the GSM of the desired sim receives a message in the format given
*/


#include <SoftwareSerial.h>
#include <TinyGPS.h>
long lat,lon;
SoftwareSerial GPS(2,3);
TinyGPS gps;

SoftwareSerial mySerial(9, 10);

void setup()
{                                     
  Serial.begin(4800);
  mySerial.begin(9600);
  GPS.begin(9600);
  pinMode(13, INPUT);
}

void loop()
{ 
  if(digitalRead(13) == 1){
    
    byte a;
    if(GPS.available()){
      
      a=GPS.read();
      while(gps.encode(a)){
         
        gps.get_position(&lat,&lon);
        Serial.println("------------------------------------GSM INSTRUCTIONS PROCESSING-------------------------------------");
        mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
        delay(1000);  // Delay of 1000 milli seconds or 1 second
        Serial.println("------------------------------------GSM INSTRUCTIONS COMPLETED-------------------------------------");

        Serial.println("------------------------------------SENDING INSTRUCTIONS PROCESSING-------------------------------------");
        mySerial.println("AT+CMGS=\"+917083545503\"\r"); //Put mobile number here
        delay(1000);
        
        mySerial.println("VEHICLE TRACKING SYSTEM"); //Put the SMS desired
        mySerial.println("Coordinates: ");
        mySerial.print("Latitude: ");
        mySerial.print((lat*0.000001),8);
        mySerial.print(" , ");
        mySerial.print("Longitude: ");  
        mySerial.println((lon*0.000001),8);
        mySerial.print("https://www.google.co.in/maps/search/");
        mySerial.print((lat*0.000001),8);
        mySerial.print(",");
        mySerial.print((lon*0.000001),8);
        mySerial.print("?sa=X&ved=");
        delay(100);
        mySerial.println((char)26); //ASCII code of CTRL+Z
        
        Serial.println("------------------------------------SENDING INSTRUCTIONS COMPLETED-------------------------------------");
        delay(1000);
        
        
        Serial.println("------------------------------------DISPLAYING THE MESSAGE SENT-------------------------------------");
        
        delay(1000);
        Serial.println("Coordinates: ");
        Serial.print("Latitude");
        Serial.print((lat*0.000001),8);
        Serial.print(" , ");
        Serial.print("Longitude");
        Serial.println((lon*0.000001),8);
        Serial.println("Link to Google Maps: ");
        Serial.print("https://www.google.co.in/maps/search/");
        Serial.print((lat*0.000001),8);
        Serial.print(",");
        Serial.print((lon*0.000001),8);
        Serial.print("?sa=X&ved="); 
        Serial.print("\n"); 
        
      }
    }
  }
}
