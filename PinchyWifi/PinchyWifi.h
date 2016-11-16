// PinchyWifi - Library for ESP8266 wifi module
// GitHub: https://github.com/
// This code is licensed under Creative Commons Share alike
// Ismael Estalayo.

#ifndef PinchyWifi_h
#define PinchyWifi_h

  #if ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif

  class PinchyWifi{
    public:
      void http(String output);
      void webServer(void);
  };

#endif
