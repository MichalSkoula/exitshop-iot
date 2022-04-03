// ZAČÁTEK Nastavení -----------------------------------------------

const char* ssid = "SSID_PLACEHOLDER";    // název WIFI sítě (nepodporuje 5Ghz wifi)
const char* password = "PASSWORD_PLACEHOLDER";  // heslo
String secretKey = "SECRET_PLACEHOLDER"; // tajný klíč
const int melody = MELODY_PLACEHOLDER;

// KONEC Nastavení -------------------------------------------------

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pitches.h"

String serverPath = "https://www.exitshop.cz/sklad/jsonStats2/" + secretKey + "/30/";
String sensorReadings; // result
int updateInterval;
unsigned long lastSuccessfullGet;
unsigned long elapsedTime;
// PINS ON NODEMCU - https://www.electronicwings.com/nodemcu/nodemcu-gpio-with-arduino-ide
const unsigned int buzzer = 14; // 14 = pin 5 
const unsigned led = 13; // 5 = pin 1, 0 = pin 3
const unsigned check = 60;

WiFiClientSecure client;
HTTPClient http;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup () {
  pinMode(buzzer,OUTPUT) ;
  pinMode(led, OUTPUT); // set the digital pin as output.

  Serial.begin(9600);
  delay(1000);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected at:");
  Serial.println(WiFi.localIP());

  // the magic line, use with caution
  client.setInsecure(); 

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.setTextColor(WHITE);
  display.setTextSize(1);

  // you will get autobanned if you try to override this
  updateInterval = check * 1000;
}

void loop () {
  elapsedTime = millis() - lastSuccessfullGet;
  int elapsedTimeSeconds = ((int)((float)elapsedTime / 1000) + 1);
  
  int newOrders = 0;
  String lastUpdate = "";
  String lastOrder = "";
  bool serverOk = true;
  
  // Check WiFi connection status
  if (WiFi.status()== WL_CONNECTED){
    // Get data
    sensorReadings = httpGETRequest(serverPath + elapsedTimeSeconds);
    Serial.println(serverPath + elapsedTimeSeconds);
    Serial.println(sensorReadings);
    JSONVar myObject = JSON.parse(sensorReadings);
  
    // JSON.typeof(jsonVar) can be used to get the type of the var
    if (JSON.typeof(myObject) != "undefined") {
      //Serial.print("JSON object = ");
      //Serial.println(myObject);
  
      if (myObject.hasOwnProperty("new_orders")) {
        lastSuccessfullGet = millis();
        newOrders = (int)myObject["new_orders"];
      }
  
      if (myObject.hasOwnProperty("update")) {
        lastUpdate = (const char*)myObject["update"];
      }
  
      if (myObject.hasOwnProperty("last_order")) {
        lastOrder = (const char*)myObject["last_order"];
      }
    } else {
      Serial.println("Parsing input failed!");
      serverOk = false;
    }
  } else {
    Serial.println("WiFi Disconnected"); 
  }

  // display 
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("Objednavka: " + lastOrder);
  
  display.setCursor(0, 15);
  display.println("Aktualizace: " + lastUpdate);

  display.setCursor(0, 30);
  display.println(WiFi.status()== WL_CONNECTED ? "Wifi: OK" : "Wifi: ERROR!!!");

  display.setCursor(0, 45);
  display.println(serverOk ? "Server: OK" : "Server: ERROR!!!");

  display.display(); 

  //Serial.println(newOrders);
  if (newOrders > 0) {
    for (int i = 0; i < newOrders; i++) {
      digitalWrite(led, HIGH); // turn the LED on.

      switch (melody) {
        case 0: delay(1500); break;
        case 1: buzz(1500); break;
        case 2: playSuperMarioMelody(); break;
        case 3: playTakeOnMeMelody(); break;
        case 4: playStarWarsMelody(); break;
        case 5: playLionMelody(); break;
        case 6: playDoomMelody(); break;
        default: break;
      }

      digitalWrite(led, LOW); // turn the LED off.
      delay(500);
    }
  }
  
  delay(updateInterval);
}

String httpGETRequest(String path) {   
  // Serial.println(path);
  // Your IP address with path or Domain name with URL path 
  http.begin(client, path);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void buzz(int length) {
  digitalWrite(led, HIGH); // turn the LED on.
  tone(buzzer, 523) ; //DO note 523 Hz
  delay (length);

  digitalWrite(led, LOW); // turn the LED off.
  noTone(buzzer) ; //Turn off the pin attached to the tone()
}
