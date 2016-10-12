/*
  This code is in the public domain.
*/

// constants won't change. They're used here to
// set pin numbers:
int ledPins[8];      // the number of the LED pin
const int buttonPin1 = 2;      // the number of the button pin
const int buttonPin2 = 3;      // the number of the button pin

int ledPointer = 0; //ledsOn
int delayTime = 200; //Time to wait when a button is pressed
boolean buttonValue1;
boolean buttonValue2;

void setup() {
  for (int i = 0; i < 8; i++) {
    //Assign number of pins
    ledPins[i] = i + 4;
    // initialize the LED pins as an outputs:
    pinMode(ledPins[i], OUTPUT);
  }
  // initialize the button pins as an input pullup:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonValue1 = digitalRead(buttonPin1);
  buttonValue2 = digitalRead(buttonPin2);
  
  if (!buttonValue1) {
    ledPointer++;
  }
  if (!buttonValue2) {
    ledPointer--;
  }
  for (int i = 0;  i <= 7; i++) {

    if (i < (ledPointer - 1)) {
      
      digitalWrite(ledPins[i], HIGH);
    }
    else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  Serial.println(ledPointer); //Prints leds on
  if (!buttonValue1 || !buttonValue2)
    delay(delayTime);
}
