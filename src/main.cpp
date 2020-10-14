#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//pin GPIO pour la connexion
const int oneWireBus = 4;
 
//initialisation de onewire
OneWire oneWire(oneWireBus);
 
//passage en référence de oneWire à DallasTemperature
DallasTemperature sensors(&oneWire);
 
void setup()
{
Serial.begin(9600);
//initialisation du senseur
sensors.begin();
}
void loop()
{
  // Permet de faire une requête de lecture de température sur notre senseur
  sensors.requestTemperatures(); 
  Serial.print("Celsius temperature: ");
  //Afficahge de la température en Celsius dans la console de monitoring
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  //Afficahge de la température en Faraneith dans la console de monitoring
  Serial.println(sensors.getTempFByIndex(0));
  //délai de 1 seconde
  delay(1000);
}