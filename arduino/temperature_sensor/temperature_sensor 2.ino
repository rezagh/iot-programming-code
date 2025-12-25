#include "DHT.h"             // Library for DHT sensors. install in library manager "DHT sensor library by Adafruit"

#define dhtPin 2            // data pin

//Uncomment the correct DHT chip. 
//#define dhtType DHT11        // DHT 11 - 3 pin - usually harder to get working
//#define dhtType DHT22      // DHT 22 (AM2302), AM2321 (4 pin)
#define dhtType DHT21      // DHT 21 (AM2301)

DHT dht(dhtPin, dhtType);    // Initialise the DHT library

float humidityVal;           // humidity
float tempValC;              // temperature in degrees Celcius
float tempValF;              // temperature in degrees Fahrenheit
float heatIndexC;            // windchill in degrees Celcius
float heatIndexF;            // windchill in degrees Fahrenheit

void setup() {
  Serial.begin(9600);        // Initialise the serial monitor
  dht.begin();               // start with reading the DHT sensor
}

void loop() {

  humidityVal = dht.readHumidity();        // get the humidity from the DHT sensor
  tempValC = dht.readTemperature();        // get the temperature in degrees Celcius from the DHT sensor
  //tempValF = dht.readTemperature(true);    // get the temperature in degrees Fahrenheit from the DHT sensor

  // Check if all values are read correctly, if not try again and exit loop()
  if (isnan(humidityVal) || isnan(tempValC)) {
    Serial.println("Reading DHT sensor failed!");
    delay(5000);
    // end the loop() function
    return;
  }
  
  // Calculate the windchill in degrees Celcius
  //heatIndexC = dht.computeHeatIndex(tempValC, humidityVal, false);

  // Calculate the windchill in degrees Fahrenheit
  //heatIndexF = dht.computeHeatIndex(tempValF, humidityVal);

  // Print all values to the serial monitor
  // \t prints a tab character
  Serial.print("Humidity: ");
  Serial.print(humidityVal);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(tempValC);
  Serial.println(" °C ");
  //Serial.print(tempValF);
  //Serial.print(" °F\t");

 // Serial.print("Windchill: ");
  //Serial.print(heatIndexC);
  //Serial.print(" °C ");
  //Serial.print(heatIndexF);
  //Serial.println(" °F");
  
  delay(5000);
}
