/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#include <ESP8266WiFi.h>
#include <Phant.h>

// Fyll ut med SSID og passord
#define WIFI_SSID "uit-conference"
#define WIFI_PASSWORD "arctic2017"

// Fyll ut phanthost, publickey og privatekey
const char PhantHost[] = "phant.labben.org"; //Get your public and private key by visiting http://phant.labben.org:8090
const char publicKey[] = "opM4MxyaJohQvzQb81d9fvajAWp";
const char privateKey[] = "RXNdN8ZmDBu9Rr9gGjY5Hjw2dpr";

WiFiClient client;
const int httpPort = 8090;

#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(MOISTURE_PIN, INPUT);
  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  digitalWrite(MOISTURE_POWER_PIN, LOW);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  delay(300);
  
  sensorValue = analogRead(MOISTURE_PIN);
  
  delay(100);
  //digitalWrite(MOISTURE_POWER_PIN, LOW);
  

  // Oppgave: Deklarer et Phantobjekt
   Phant phant(PhantHost, publicKey, privateKey);

   phant.add("humidity", sensorValue); 

  // Oppgave: legg til sensorverdien i Phantobjektet. Husk å bruke samme nøkkel som når du opprettet phant-stream
  

  // Oppgave: koble til Phantserveren. Skriv ut feilmelding om tilkobling mislyktes
  if(!client.connect(PhantHost, httpPort)){
    Serial.print("cannot connect to phant-server");
  }
  
  // Oppgave: Post data til Phant serveren
  client.print(phant.post());


  delay(15000);
}
