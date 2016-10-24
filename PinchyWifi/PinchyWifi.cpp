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

http(
  "<!DOCTYPE HTML>"
  "<html>"
  "<head><title>ESPPP</title></head>"
  "<body><font face=\"Segoe UI light\">"
);

http(
  "<div style=\"max-width: 400px\" >"
  "<img src=\"http://bilbaodynamics.com/wp-content/uploads/2016/04/pusheengif.gif\" style=\"max-width:100%;\"/></div>"
);


http(
  "<form action=\"LED\" method=\"get\">"
  "  LED color:"
  "  <button name=\"color\" type=\"submit\" value=\"red\">Red</button>"
  "  <button name=\"color\" type=\"submit\" value=\"green\">Green</button>"
  "  <button name=\"color\" type=\"submit\" value=\"blue\">Blue</button>"
  "</form>"
);

http(
"<form action=\"BUZZER\" method=\"get\">"
"  Buzzer:"
"  <button name=\"sound\" type=\"submit\" value=\"ON\">On</button>"
"  <button name=\"sound\" type=\"submit\" value=\"OFF\">Off</button>"
"</form>"
);

http(
"<form action=\"LCD\">"
"Nº de Pinchy: <input type=\"text\" name=\"Number\" value=\"\"><br>"
"<input type=\"submit\" value=\"Submit\">"
"</form>"
);

http(
"<form action=\"ADELANTE\">"
"Adelante (1-9seg):"
"  <input type=\"number\" name=\"seg\" min=\"1\" max=\"9\">"
"  <input type=\"submit\"></form>"
);

http(
  "<div id=\"joystick\" style=\"width:20%\">"
  "  <svg width=\"100%\" height=\"100%\" viewBox=\"0 0 100 100\">"
  "    <defs>"
  "      <linearGradient id=\"grad1\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">"
  "        <stop offset=\"0%\" style=\"stop-color:rgb(16,16,16);stop-opacity:1\" />"
  "        <stop offset=\"100%\" style=\"stop-color:rgb(240,240,240);stop-opacity:1\" />"
  "      </linearGradient>"
  "      <linearGradient id=\"grad2\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">"
  "        <stop offset=\"0%\" style=\"stop-color:rgb(240,240,240);stop-opacity:1\" />"
  "        <stop offset=\"100%\" style=\"stop-color:rgb(16,16,16);stop-opacity:1\" />"
  "      </linearGradient>"
  "      <linearGradient id=\"grad3\" x1=\"0%\" y1=\"0%\" x2=\"0%\" y2=\"100%\">"
  "        <stop offset=\"0%\" style=\"stop-color:rgb(168,168,168);stop-opacity:1\" />"
  "        <stop offset=\"100%\" style=\"stop-color:rgb(239,239,239);stop-opacity:1\" />"
  "      </linearGradient>"
  "    </defs>"
  "    <circle cx=\"50\" cy=\"50\" r=\"50\" fill=\"url(#grad1)\" />"
  "    <circle cx=\"50\" cy=\"50\" r=\"47\" fill=\"url(#grad2)\" stroke=\"black\" stroke-width=\"1.5px\" />"
  "    <circle cx=\"50\" cy=\"50\" r=\"44\" fill=\"url(#grad3)\" />"
  "    <circle cx=\"50\" cy=\"50\" r=\"20\" fill=\"#cccccc\" stroke=\"black\" onclick=\"location.href='PARAR' ;\" />"
  "    <path d=\"M50,14 54,22 46,22Z\" fill=\"rgba(0,0,0,0.8)\" onclick=\"location.href='ADELANTE' ;\" />"
  "    <path d=\"M50,86 54,78 46,78Z\" fill=\"rgba(0,0,0,0.8)\" onclick=\"location.href='ATRAS' ;\" />"
  "    <path d=\"M14,50 22,54 22,46Z\" fill=\"rgba(0,0,0,0.8)\" onclick=\"location.href='IZQUIERDA' ;\" />"
  "    <path d=\"M86,50 78,54 78,46Z\" fill=\"rgba(0,0,0,0.8)\" onclick=\"location.href='DERECHA' ;\" />"
  "  </svg>"
  "</div>"
);

http("</font></body></html>");
  delay(100);
  Serial1.println("AT+CIPCLOSE=0"
);

}
