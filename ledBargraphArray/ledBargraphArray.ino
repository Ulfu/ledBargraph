/*
  This example code is in the public domain.
*/

// constants won't change. They're used here to
// set pin numbers:
int ledPins[8];      // the number of the LED pin
const int buttonPin1 = 2;      // the number of the button pin
const int buttonPin2 = 3;      // the number of the button pin

int delayTime = 200;
int ledsState[8]; //Current LEDs that are HIGH
boolean buttonValue1;
boolean buttonValue2;

void setup() {
  for (int i = 0; i < 8; i++) {
    //Assign number of pins
    ledPins[i] = i + 4;
    //Set all led states to LOW
    ledsState[i] = false;
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

  for (int i = 0;  i <= 7; i++) {

    Serial.println(ledsState[i]); //Prints led state
    if (!ledsState[i] && !buttonValue1) {
      ledsState[i] = true;
      
      digitalWrite(ledPins[i], ledsState[i]);
      delay(delayTime);
      break;
    }
  }
   for (int i = 7;  i >= 0 ; i--) {
      if  (ledsState[i] && !buttonValue2) {
      ledsState[i] = false;

      digitalWrite(ledPins[i], ledsState[i]);
      delay(delayTime);
      break;
    }
   }
}
