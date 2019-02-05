/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>

// Fyll ut med SSID og passord
#define WIFI_SSID "uit-conference"
#define WIFI_PASSWORD "arctic2017"

void setup() {
  Serial.begin(115200);

  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println(WIFI_SSID);

  // Oppgave: Start tilkobling til trådløst nettverk med ssid og password
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(" ... ");
    delay(500);  
  }
  // Oppgave: Skriv ut "." hvert 0.5 sekund fram til vi er tilkoblet
  //int loc_wifi = WiFi.localIP();
  
  Serial.println("Connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Oppgave: Skriv ut IP-adresse
}

void loop() {
}
