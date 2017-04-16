# ESP8266
Program the ESP8266 through Arduino IDE, and make it work as a Web server.

# Changelog:

#### 1.3:
- This repo is now only for the library, and the .ino file has been converted to an example of the library: File>Examples>PinchyWifi

#### 1.2:
- Added buttons and inputs to the HTML making it easier and faster to send commands (instead of typing them on the URL).
- Implemented the library for the LCD Matrix. More info [here](https://github.com/BilbaoDynamics/Pinchy/tree/master/PinchyMatrix)

#### 1.00:
- Vastly improved latency, thanks to the use of a single connection. (GET petition for a _favicon.ico_ usually opened a second or even third parallel connection which was unnecesary).
- Automated the setup proces for the server on the ESP8266 (red LED will be ON until setup ends):
    
    ```AT+CIPMUX=1, AT+CIPSERVER=1,80```

- Created a library for Arduino called _PinchyWifi_ for taking out some line codes out of the main .ino file, and so that the users can't change the HTML of the web server.
- Added a few more commands for the parser to accept.
