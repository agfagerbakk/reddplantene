/* Redd Plantene
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: reddplantene.labben.org / bouvet.no/reddplantene
 * @web: bouvet.no / nikhil.luthra.no
 */
#define MOISTURE_PIN A0
#define MOISTURE_POWER_PIN D7

int sensorValue = 0;

void setup() {
  Serial.begin(115200);

  // Oppgave: Sett MOISTURE_PIN i inputmodus
  pinMode(MOISTURE_PIN, INPUT);
  
  pinMode(MOISTURE_POWER_PIN, OUTPUT);
  
  // Oppgave: Sett MOISTURE_POWER_PIN til HIGH for å sende strøm til sensoren.
  pinMode(MOISTURE_POWER_PIN, HIGH);

  delay(300);

  
}

void loop() {
  // Oppgave: Les av fuktighet
  
  int sens_val = analogRead(MOISTURE_PIN);
  Serial.printf("Moisture: %d \n", sens_val);
  
  digitalWrite(MOISTURE_PIN, sens_val);

  // Oppgave: Skriv ut fuktighet til serieport
  digitalWrite(MOISTURE_POWER_PIN, HIGH);
  
  //analogWrite(MOISTURE_PIN);
  
  delay(2000);
  // Oppgave: Vent 2 sekunder
}
