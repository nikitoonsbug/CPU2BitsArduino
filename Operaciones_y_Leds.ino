
// constants won't change. They're used here to set pin numbers:
const int buttonPinA = 0;     // the number of the pushbutton pin
const int buttonPinB = 1;     // the number of the pushbutton pin
const int buttonPinC = 2;     // the number of the pushbutton pin
const int buttonPinD = 3;     // the number of the pushbutton pin
const int buttonPinE = 4;     // the number of the pushbutton pin
const int buttonPinF = 5;     // the number of the pushbutton pin
const int buttonPinG = 6;     // the number of the pushbutton pin
boolean ledPinS0;      // the number of the LED pin
boolean ledPinS1;      // the number of the LED pin
boolean ledPinA0;      // the number of the LED pin
boolean ledPinA1;
boolean ledPinError;

// variables will change:
int buttonStateA = 0;         // variable for reading the pushbutton status
int buttonStateB = 0;
int buttonStateC = 0;
int buttonStateD = 0;
int buttonStateE = 0;
int buttonStateF = 0;
int buttonStateG = 0;

//LED
const int ledPinA = 7;
const int ledPinB = 8;
const int ledPinC = 9;
const int ledPinD = 10;
const int ledPinE = 11;
const int ledPinF = 12;
const int ledPinG = 13;




void setup() {
  // initialize the LED pin as an output:
ledPinS0=false;      // the number of the LED pin
ledPinS1=false;      // the number of the LED pin
ledPinA0=false;      // the number of the LED pin
ledPinA1=false;
ledPinError=false;
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPinE, INPUT);
  pinMode(buttonPinF, INPUT);
  pinMode(buttonPinG, INPUT);

  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);

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

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:nnnnnnnnn
  //and
  if (!buttonStateE && !buttonStateF && !buttonStateG) {

    if (buttonStateA && buttonStateC) {
      // turn LED on:
      ledPinS0 = true;
    } else {
      // turn LED off:
      ledPinS0 = false;
    }

    if (buttonStateB && buttonStateD)  {
      // turn LED on:
      ledPinS1 = true;
    } else {
      // turn LED off:
      ledPinS1 = false;
    }
  }

  //OR

  if (!buttonStateE && !buttonStateF && buttonStateG) {

    if (buttonStateA || buttonStateC) {
      // turn LED on:
      ledPinS0 = true;
    } else {
      // turn LED off:
      ledPinS0 = false;
    }

    if (buttonStateB || buttonStateD)  {
      // turn LED on:
      ledPinS1 = true;
    } else {
      // turn LED off:
      ledPinS1 = false;
    }
  }

  //XOR
  if (buttonStateE && buttonStateF && buttonStateG) {

    if (buttonStateA ^ buttonStateC) {
      // turn LED on:
      ledPinS0 = true;
    } else {
      // turn LED off:
      ledPinS0 = false;
    }

    if (buttonStateB ^ buttonStateD)  {
      // turn LED on:
      ledPinS1 = true;
    } else {
      // turn LED off:
      ledPinS1 = false;
    }
  }

  //Suma
  if ((buttonStateA ^ buttonStateC) && (!buttonStateE && buttonStateF && buttonStateG)) {
    // turn LED on:
    ledPinS0 = true;
  } else {
    // turn LED off:
    ledPinS0 = false;
  }

  if ((buttonStateB ^ buttonStateD) ^ (buttonStateA && buttonStateC) && (!buttonStateE && buttonStateF && buttonStateG)) {
    // turn LED on:
    ledPinS1 = true;
  } else {
    // turn LED off:
    ledPinS1 = false;
  }

  if ((buttonStateB && buttonStateD) && (!buttonStateE && buttonStateF && buttonStateG)) {
    // turn LED on:
    ledPinA0 = true;
  } else {
    // turn LED off:
    ledPinA0 = false;
  }

  //not

  if (!buttonStateE && buttonStateF && !buttonStateG) {
    if (!buttonStateA) {
      ledPinS0 = true;
    } else {
      ledPinS0 = false;
    }

    if (!buttonStateB) {
      ledPinS1 = true;
    } else {
      ledPinS1 = false;
    }

    if (!buttonStateC) {
      ledPinA0 = true;
    } else {
      ledPinA0 = false;
    }

    if (!buttonStateD) {
      ledPinA1 = true;
    } else {
      ledPinA1 = false;
    }

  }

  //Resta

  if (buttonStateE && !buttonStateF && !buttonStateG) {
    if (!buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = true;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = true;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
  }

  //Multiplicación

  if (buttonStateE && !buttonStateF && buttonStateG) {
    if (buttonStateA && buttonStateC) {
      ledPinS0 = true;
    } else {
      ledPinS0 = false;
    }

    if ((buttonStateB && buttonStateC) ^ (buttonStateA && buttonStateD)) {
      // turn LED on:
      ledPinS1 = true;
    } else {
      // turn LED off:
      ledPinS1 = false;
    }

    if (((buttonStateB && buttonStateC) && (buttonStateA && buttonStateD)) ^ (buttonStateB && buttonStateD)) {
      // turn LED on:
      ledPinA0 = true;
    } else {
      // turn LED off:
      ledPinA0 = false;
    }

    if (((buttonStateB && buttonStateC) && (buttonStateA && buttonStateD)) && (buttonStateB && buttonStateD)) {
      // turn LED on:
      ledPinA1 = true;
    } else {
      // turn LED off:
      ledPinA1 = false;
    }

  }

  //División

  if (buttonStateE && buttonStateF && !buttonStateG) {
    if (!buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = true;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = true;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = true;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = true;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }

    if (!buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (!buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && !buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = true;
      ledPinA0 = false;
      ledPinA1 = false;

    }
    if (buttonStateA && buttonStateB && !buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = true;

    }
    if (buttonStateA && buttonStateB && !buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = true;

    }
    if (buttonStateA && buttonStateB && buttonStateC && !buttonStateD) {
      ledPinError = false;
      ledPinS0 = false;
      ledPinS1 = false;
      ledPinA0 = true;
      ledPinA1 = true;

    }
    if (buttonStateA && buttonStateB && buttonStateC && buttonStateD) {
      ledPinError = false;
      ledPinS0 = true;
      ledPinS1 = false;
      ledPinA0 = false;
      ledPinA1 = false;

    }
  }
  control();


}
void control(){


  if (!ledPinA1 && !ledPinA0 && !ledPinS1 && !ledPinS0) {
    cero();
  }
  if (!ledPinA1 && !ledPinA0 && !ledPinS1 && ledPinS0) {
    uno();
  }
  if (!ledPinA1 && !ledPinA0 && ledPinS1 && !ledPinS0) {
    dos();
  }
  if (!ledPinA1 && !ledPinA0 && ledPinS1 && ledPinS0) {
    tres();
  }

  if (!ledPinA1 && ledPinA0 && !ledPinS1 && !ledPinS0) {
    cuatro();
  }
  if (!ledPinA1 && ledPinA0 && !ledPinS1 && ledPinS0) {
    cinco();
  }
  if (!ledPinA1 && ledPinA0 && ledPinS1 && !ledPinS0) {
    seis();
  }
  if (!ledPinA1 && ledPinA0 && ledPinS1 && ledPinS0) {
    siete();
  }


 if (ledPinA1 && !ledPinA0 && !ledPinS1 && !ledPinS0) {
    ocho();
  }
  if (ledPinA1 && !ledPinA0 && !ledPinS1 && ledPinS0) {
    nueve();
  }
  if (ledPinA1 && !ledPinA0 && ledPinS1 && !ledPinS0) {
    a();
  }
  if (ledPinA1 && !ledPinA0 && ledPinS1 && ledPinS0) {
    b();
  }

  if (ledPinA1 && ledPinA0 && !ledPinS1 && !ledPinS0) {
    c();
  }
  if (ledPinA1 && ledPinA0 && !ledPinS1 && ledPinS0) {
    d();
  }
  if (ledPinA1 && ledPinA0 && ledPinS1 && !ledPinS0) {
    e();
  }
  if (ledPinA1 && ledPinA0 && ledPinS1 && ledPinS0) {
    f();
  }

  if(ledPinError){
    e();
    }

  }

void cero() {
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, HIGH);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, HIGH);
}
void uno() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, LOW);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, LOW); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
void dos() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, LOW); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void tres() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, LOW); //Quinto
  digitalWrite(ledPinE, LOW); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void cuatro() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, LOW); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, LOW); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void cinco() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, LOW); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
void seis() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
void siete() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, LOW);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, LOW); //Quinto
  digitalWrite(ledPinE, LOW); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void ocho() {
  digitalWrite(ledPinA, HIGH);
  digitalWrite(ledPinB, HIGH);
  digitalWrite(ledPinC, HIGH);
  digitalWrite(ledPinD, HIGH);
  digitalWrite(ledPinE, HIGH);
  digitalWrite(ledPinF, HIGH);
  digitalWrite(ledPinG, HIGH);
}
void nueve() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, LOW); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero

}
void a() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void b() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, LOW); //Primero
  digitalWrite(ledPinG, LOW); //Tercero

}
void c() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, LOW);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
void d() {
  digitalWrite(ledPinA, HIGH);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, LOW); //Segudo
  digitalWrite(ledPinF, LOW); //Primero
  digitalWrite(ledPinG, HIGH); //Tercero
}
void e() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
void f() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW); //Septimo
  digitalWrite(ledPinD, HIGH); //Quinto
  digitalWrite(ledPinE, HIGH); //Segudo
  digitalWrite(ledPinF, HIGH); //Primero
  digitalWrite(ledPinG, LOW); //Tercero
}
