const int ledPin =  LED_BUILTIN;
const int arrosagePin1 = D5;
const int arrosagePin2 = D6;

const unsigned long interval = 1000 * 20 ;
const unsigned tempsArrosage  = 5000;
void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(arrosagePin1, OUTPUT);
  pinMode(arrosagePin2, OUTPUT);
  arrosage( LOW);
  delay(3000);
  arrosage( HIGH);
  
}

void loop() {
  delay(interval);
  arrosage( LOW);
  delay(tempsArrosage);
  arrosage(HIGH);

}

void arrosage (bool etat) {
  Serial.print ("changement d'etat :");
  Serial.println (etat);
  digitalWrite(ledPin, etat);
  
  digitalWrite (arrosagePin1, etat);
  digitalWrite (arrosagePin2, etat);

}
