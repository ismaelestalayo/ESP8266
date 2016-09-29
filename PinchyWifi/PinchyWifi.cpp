#include "Arduino.h"
#include "PinchyWifi.h"

void PinchyWifi::http(String output)
{
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

void PinchyWifi::webServer()
{
  http("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
  http("<!DOCTYPE HTML>");
  http("<html>");
  http("<head><title>ESP8266</title></head>");
  http("<body><font face=\"Segoe UI light\">");
  http("<p float:left><img src=\"http://bilbaodynamics.com/wp-content/uploads/2016/01/BD_imagotipo_con_logo_4_v001-e1454764201240.png\" width = \"40%\"/></p>");
  http("<h1>Probando el ESP8266</h1>");
  http("<h4>(poner 192.168.0.X/comando)</h4>");
  http("<ul><li>/r</li><li>/g</li><li>/b</li></ul>");
  http("</font></body></html>");
  delay(100);
  Serial1.println("AT+CIPCLOSE=0");
}
