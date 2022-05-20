const int ledPin =  LED_BUILTIN;
//const unsigned long arrosageTime = 20 * 1000;
//const unsigned long eventInterval = 60 * 60 * 12 * 1000 - arrosageTime;
const unsigned long arrosageTime = 2 * 1000;
const unsigned long eventInterval = 9 * 1000 - arrosageTime;
const unsigned long ledTime = 500;
unsigned long previousTime = 0;
unsigned long previousLedTime = 0;

bool arrosageGoing = LOW;
bool blinker = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}

void loop() {

  /* Updates frequently */
  unsigned long currentTime = millis();
 

  /* This is the event */
  if (arrosageGoing == LOW) {
    if (currentTime - previousTime >= eventInterval) {
      previousTime = currentTime;
      arrosage (LOW, currentTime);
    }
  }
  else {
    if (currentTime - previousTime >= arrosageTime)  {
      arrosage(HIGH, currentTime);
      previousTime = currentTime;
    }
  }
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

  //digitalWrite (arrosagePin1, etat);
  //digitalWrite (arrosagePin2, etat);

}
