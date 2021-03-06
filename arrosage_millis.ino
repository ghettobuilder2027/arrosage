/*
 *  Arrosage automatique à l'aide d'un esp 01 et d'une carte relay
 *  
 *  * Le relay fonctionne en inversé ( mettre la sortie en 0 pour activer
 *  * Pour faire clignoter (contrôle que le programme tourne toujours), il faut
 *    utiliser la sortie 0 pour le clignotement et la sortie 2 pour le relay
 *  * Le timing se fait à l'aide de la fonction millis
 *  * Un unsigned long fait environ 5O jours en secondes.
 * 
 */


const int ledPin =  0;//LED_BUILTIN;
// Pin 0 pour arrosage
const int arrosagePin1 = 2;

const unsigned long arrosageTime = 32 * 1000; // 30 secondes
const unsigned long eventInterval = 60 * 60 * 12 * 1000 - arrosageTime; // toutes les 12 heures

// Test values 
//const unsigned long arrosageTime = 5 * 1000;
//const unsigned long eventInterval = 20 * 1000 - arrosageTime;

// frequence de clignotage de la led ( pour checker que ca tourne)
const unsigned long ledTime = 500;

unsigned long previousTime = 0;
unsigned long previousLedTime = 0;

bool arrosageGoing = LOW;
bool blinker = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(arrosagePin1, OUTPUT);
  digitalWrite(ledPin, HIGH);
  digitalWrite(arrosagePin1, HIGH);
  delay(1000);
  
}

void loop() {
  unsigned long currentTime = millis();

  // Routine arrosage
  if (arrosageGoing == LOW) {
    if (currentTime - previousTime >= eventInterval) {
      previousTime = currentTime;
      // Declenchement de l'arrosage (il faut mettre le pin à LOW pour déclencher)
      arrosage (LOW, currentTime);
    }
  }
  else {
    if (currentTime - previousTime >= arrosageTime)  {
      arrosage(HIGH, currentTime);
      previousTime = currentTime;
    }
  }
  
  // Routine clignotage de la led
  if (currentTime - previousLedTime >= ledTime) {
    blinker = !blinker;
    digitalWrite(ledPin, blinker);
    previousLedTime = currentTime;

  }
}


void arrosage (bool etat, unsigned long c) {
  Serial.println ("---------------------");
  Serial.print ("changement d'etat :");
  Serial.println (etat);
  Serial.print ("current time :");
  Serial.println(c);
  arrosageGoing = !arrosageGoing;
  Serial.print ("arrosageGoing :");
  Serial.println (arrosageGoing);

  digitalWrite (arrosagePin1, etat);
  
}
