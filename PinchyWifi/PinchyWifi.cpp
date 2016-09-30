#include "Arduino.h"
#include "PinchyWifi.h"

void PinchyWifi::http(String output){
  Serial1.print("AT+CIPSEND=0,");
  Serial1.println(output.length());
  if (Serial1.find(">")){
    Serial1.println(output);
    delay(10);
    while ( Serial1.available() > 0 ){
      if (  Serial1.find("SEND OK") )
        break;
    }
  }
}

void PinchyWifi::webServer(){
http("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
http("<link rel=\"shortcut icon\" href=\"data:image/x-icon;,\" type=\"image/x-icon\"> ");

http("<!DOCTYPE HTML>");
http("<html>"
"<head><title>ESP8266</title></head>"
"<body><font face=\"Segoe UI light\">");

http(
"<div style=\"max-width: 400px\" >"
"<img src=\"http://bilbaodynamics.com/wp-content/uploads/2016/04/pusheengif.gif\" style=\"max-width:100%;\"/></div>");

http(
"<form action=\"LED\" method=\"get\">"
"  LED color:"
"  <button name=\"color\" type=\"submit\" value=\"red\">Red</button>"
"  <button name=\"color\" type=\"submit\" value=\"green\">Green</button>"
"  <button name=\"color\" type=\"submit\" value=\"blue\">Blue</button>"
"</form>");

http(
"<form action=\"BUZZER\" method=\"get\">"
"  Buzzer:"
"  <button name=\"sound\" type=\"submit\" value=\"ON\">On</button>"
"  <button name=\"sound\" type=\"submit\" value=\"OFF\">Off</button>"
"</form>");

http(
"<form action=\"LCD\">"
"Nº de Pinchy: <input type=\"text\" name=\"Number\" value=\"\"><br>"
"<input type=\"submit\" value=\"Submit\">"
"</form>");

http(
"<form action=\"ADELANTE\">"
"Adelante (1-9seg):"
"  <input type=\"number\" name=\"seg\" min=\"1\" max=\"9\">"
"  <input type=\"submit\"></form>");

http("</font></body></html>");
  delay(100);
  Serial1.println("AT+CIPCLOSE=0");
}
