/*
 *    AT+GMR                    (Check Firmware version)
 *    AT+CWLAP                  (Scan Wifi)
 *    AT+CWJAP="SSID","pass"    (Connect)
 *    AT+CWQAP                  (Disconnect)
 *    AT+CIFSR                  (/ipconfig)
 *    AT+CIPMUX=1               (Multiple connections)
 *    AT+CIPSERVER=1,80         (Server)
 *    Print something on serial: Serial.println("  ");
*/
#include <PinchyWifi.h>
#include <Servo.h>

PinchyWifi Wifi;

char r;
String R;
boolean b = false;

Servo rueda1;
Servo rueda2;

void setup()  {
  Serial.begin(9600);
  Serial1.begin(115200);
  rueda1.attach(5);
  rueda2.attach(6);
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //Setup for the servers and multiple connections.
  digitalWrite(11, HIGH);
  delay(3000);
  Serial1.println("AT+CIPMUX=1");
  delay(500);
  Serial1.println("AT+CIPSERVER=1,80");
  delay(500);
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}

void loop(){
   while(Serial1.available() ) {
      r = Serial1.read();
      if(r == 71){
        b = true;
      }
      
      Serial.print(r);
      R = R + r;
   }
 
  while(Serial.available() ) {
     Serial1.write(Serial.read() );
  }

  if(r == '\n' && R.indexOf("GET /") > 0){
    int start = R.indexOf("/");
    int finish = R.indexOf("HTTP");
    String command = R.substring(start+1, finish-1);

    commands(command);
    R = "";
  }
  
  if(r == '\n')
    R = "";

  if(b){
    Wifi.webServer();
    b = false;
  }
  
}

//****************************************************************************
//****************************************************************************
//****************************************************************************
void commands(String command){
  if(command.startsWith("LED_")){
    if(command.equalsIgnoreCase("LED_rojo"))
      digitalWrite(11, !digitalRead(11) );

    else if(command.equalsIgnoreCase("LED_verde"))
      digitalWrite(9, !digitalRead(9) );

    else if(command.equalsIgnoreCase("LED_azul"))
      digitalWrite(10, !digitalRead(10) );
  }

  else if(command.startsWith("adelante")){
    String ss = command.substring(8);
    int sec = ss.toInt();
    rueda1.write(0);
    rueda2.write(180);
    switch (sec){
      case 1:
        delay(1000);
        break;
      case 2:
        delay(2000);
        break;
      case 3:
        delay(3000);
        break;
      case 4:
        delay(4000);
        break;
      case 5:
        delay(5000);
        break;
      case 6:
        delay(6000);
        break;
      case 7:
        delay(7000);
        break;
      case 8:
        delay(8000);
        break;
      case 9:
        delay(9000);
        break;
      default:
        delay(1000);
        break;
    }
    rueda1.write(90);
    rueda2.write(90);
  }
  else if(command.startsWith("atras")){
    String ss = command.substring(5);
    int sec = ss.toInt();
    rueda1.write(180);
    rueda2.write(0);
    switch (sec){
      case 1:
        delay(1000);
        break;
      case 2:
        delay(2000);
        break;
      case 3:
        delay(3000);
        break;
      case 4:
        delay(4000);
        break;
      case 5:
        delay(5000);
        break;
      case 6:
        delay(6000);
        break;
      case 7:
        delay(7000);
        break;
      case 8:
        delay(8000);
        break;
      case 9:
        delay(9000);
        break;
      default:
        delay(1000);
        break;
    }
    rueda1.write(90);
    rueda2.write(90);
  }
}

