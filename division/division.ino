
// constants won't change. They're used here to set pin numbers:
const int buttonPinA = 2;     // the number of the pushbutton pin
const int buttonPinB = 3;     // the number of the pushbutton pin
const int buttonPinC = 4;     // the number of the pushbutton pin
const int buttonPinD = 5;     // the number of the pushbutton pin
const int buttonPinE = 6;     // the number of the pushbutton pin
const int buttonPinF = 7;     // the number of the pushbutton pin
const int buttonPinG = 8;     // the number of the pushbutton pin
const int ledPinS0 =  9;      // the number of the LED pin
const int ledPinS1 =  10;      // the number of the LED pin
const int ledPinA0 =  11;      // the number of the LED pin
const int ledPinA1 =  12;
const int ledPinError =  13;

// variables will change:
int buttonStateA = 0;         // variable for reading the pushbutton status
int buttonStateB = 0;
int buttonStateC = 0;
int buttonStateD = 0;
int buttonStateE = 0;
int buttonStateF = 0;
int buttonStateG = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinS0, OUTPUT);
  pinMode(ledPinS1, OUTPUT);
  pinMode(ledPinA0, OUTPUT);
  pinMode(ledPinA1, OUTPUT);
  pinMode(ledPinError, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPinE, INPUT);
  pinMode(buttonPinF, INPUT);
  pinMode(buttonPinG, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonStateA = digitalRead(buttonPinA);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateC = digitalRead(buttonPinC);
  buttonStateD = digitalRead(buttonPinD);
  buttonStateE = digitalRead(buttonPinE);
  buttonStateF = digitalRead(buttonPinF);
  buttonStateG = digitalRead(buttonPinG);

  //División

  if (buttonStateE && buttonStateF && !buttonStateG) {
    if (!buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, HIGH);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }

    if (!buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, HIGH);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, HIGH);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, HIGH);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }

    if (!buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
    if (!buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, HIGH);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
    if (!buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, LOW);

    }
    if (!buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, HIGH);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, LOW);

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, LOW);

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, HIGH);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
    if (buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, HIGH);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
    if (buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, HIGH);
      digitalWrite(ledPinS1, HIGH);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
    if (buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, HIGH);

    }
    if (buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, HIGH);

    }
    if (buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, LOW);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, HIGH);
      digitalWrite(ledPinA1, HIGH);

    }
    if (buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      digitalWrite(ledPinError, LOW);
      digitalWrite(ledPinS0, HIGH);
      digitalWrite(ledPinS1, LOW);
      digitalWrite(ledPinA0, LOW);
      digitalWrite(ledPinA1, LOW);

    }
  }


}
