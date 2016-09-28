/*
 *    AT+GMR                    (Check Firmware version)
 *    AT+CWLAP                  (Scan Wifi)
 *    AT+CWJAP="SSID","pass"    (Connect)
 *    AT+CWQAP                  (Disconnect)
 *    AT+CIFSR                  (/ipconfig)
 *    AT+CIPMUX=1               (Multiple connections)
 *    AT+CIPSERVER=1,80         (Server)
 *    Example of line to parse: 
 *    Print something on serial: Serial.println("  ");
*/
char r;
String R;
boolean b = false;

void setup()  {
  Serial.begin(9600);
  Serial1.begin(115200);
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
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
    webServer();
    b = false;
  }
  
}

//***************************************************************
void http(String output){
  Serial1.print("AT+CIPSEND=0,");              // AT+CIPSEND=0, num
  Serial1.println(output.length());
  if (Serial1.find(">")){                       // Si recibimos la peticion del mensaje
    Serial1.println(output);            //Aqui va el string hacia el WIFI
    delay(10);
    while ( Serial1.available() > 0 ){
      if (  Serial1.find("SEND OK") )    // Busca el OK en la respuesta del wifi
        break;
    }
  }
}

void webServer(void){
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
//***************************************************************
void commands(String command){
  if(command.equalsIgnoreCase("red")
    digitalWrite(11, !digitalRead(11) );
  
  else if(command.equalsIgnoreCase("green")
    digitalWrite(9, !digitalRead(9) );

  else if(command.equalsIgnoreCase("blue")
    digitalWrite(10, !digitalRead(10) );

  else if(command.startsWith("adelante"){
    
  }
  
}

