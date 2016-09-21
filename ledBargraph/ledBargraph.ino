/*



 The circuit:
 * LED attached from pin 3-13 to ground
 * pushbutton attached to pin 2 Pullupp-switch
 * pushbutton attached to pin 3 Pullupp-switch

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int ledMinPin = 3;      // the number of the LED pin
const int ledMaxPin = 11;      // the number of the LED pin
const int buttonPin1 = 2;      // the number of the button pin
const int buttonPin2 = 3;      // the number of the button pin

int ledsOn = 0; //Current LEDs that are HIGH
boolean buttonValue1;
boolean buttonValue2;

void setup() {
  // initialize the button pin as an input pullup:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  // initialize the LED pin as an output:
  for (int led = ledMinPin; led <= ledMaxPin; led++){
    pinMode(led, OUTPUT);
  }
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
}

void loop() {
  buttonValue1 = digitalRead(buttonPin1);
  buttonValue2 = digitalRead(buttonPin2);
  if (!buttonValue1) {    
   digitalWrite((ledMinPin + ledsOn), HIGH);
    ledsOn++;    
  }
  if (!buttonValue2) {
    digitalWrite((ledMinPin + ledsOn), LOW);
    ledsOn--;
  }
  
  ledsOn = constrain(ledsOn, 1, (ledMaxPin - ledMinPin));
  delay(60);
  Serial.println(ledsOn); //
}
