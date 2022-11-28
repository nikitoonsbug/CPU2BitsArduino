boolean ledPinS0;  // the number of the LED pin
boolean ledPinS1;  // the number of the LED pin
boolean ledPinA0;  // the number of the LED pin
boolean ledPinA1;
boolean ledPinError;

boolean buttonStateA = true;   // the number of the pushbutton pin
boolean buttonStateB = true;   // the number of the pushbutton pin
boolean buttonStateC = true;   // the number of the pushbutton pin
boolean buttonStateD = false;  // the number of the pushbutton pin
boolean buttonStateE = false;  // the number of the pushbutton pin
boolean buttonStateF = false;  // the number of the pushbutton pin
boolean buttonStateG = false;

String m1 = "Selecciona una operacion: ";
String m2 = "Inserta el primer numero: ";
String m3 = "Inserta el segundo numero: ";




//LED
const int ledPinA = 7;
const int ledPinB = 8;
const int ledPinC = 9;
const int ledPinD = 10;
const int ledPinE = 11;
const int ledPinF = 12;
const int ledPinG = 13;

String Op = "";
int n1 = 0;
int n2 = 0;


void setup() {
  // initialize the LED pin as an output:
  ledPinS0 = false;  // the number of the LED pin
  ledPinS1 = false;  // the number of the LED pin
  ledPinA0 = false;  // the number of the LED pin
  ledPinA1 = false;
  ledPinError = false;

  // initialize the pushbutton pin as an input:
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print(m1);
  while (Serial.available() == 0) {}

  if (Serial.available()) {
    String Op = Serial.readStringUntil('\n');
    Serial.println(Op);
    if (Op == "Suma") {
      buttonStateE = false;
      buttonStateF = true;
      buttonStateG = true;
    }
    if (Op == "Resta") {
      buttonStateE = true;
      buttonStateF = false;
      buttonStateG = false;
    }
    if (Op == "Multiplicacion") {
      buttonStateE = true;
      buttonStateF = false;
      buttonStateG = true;
    }
    if (Op == "Division") {
      buttonStateE = true;
      buttonStateF = true;
      buttonStateG = false;
    }
  }
  if (Op == "Division" ) {
    Serial.print(m2);
    while (Serial.available() == 0) {}
    if (Serial.available()) {
      String num1 = Serial.readStringUntil('\n');
      Serial.println(num1);
      if (num1 == "00") {
        buttonStateA = false;
        buttonStateC = false;
      }
      if (num1 == "01") {
        buttonStateA = false;
        buttonStateC = true;
      }
      if (num1 == "10") {
        buttonStateA = true;
        buttonStateC = false;
      }
      if (num1 == "11") {
        buttonStateA = true;
        buttonStateC = true;
      }
    }
    Serial.print(m3);
    while (Serial.available() == 0) {}
    if (Serial.available()) {
      String num2 = Serial.readStringUntil('\n');
      Serial.println(num2);
      if (num2 == "00") {
        buttonStateB = false;
        buttonStateD = false;
      }
      if (num2 == "01") {
        buttonStateB = false;
        buttonStateD = true;
      }
      if (num2 == "10") {
        buttonStateB = true;
        buttonStateD = false;
      }
      if (num2 == "11") {
        buttonStateB = true;
        buttonStateD = true;
      }
    }
  } else {
    Serial.print(m2);
    while (Serial.available() == 0) {}
    if (Serial.available()) {
      String num1 = Serial.readStringUntil('\n');
      Serial.println(num1);
      if (num1 == "00") {
        buttonStateA = false;
        buttonStateB = false;
      }
      if (num1 == "01") {
        buttonStateA = false;
        buttonStateB = true;
      }
      if (num1 == "10") {
        buttonStateA = true;
        buttonStateB = false;
      }
      if (num1 == "11") {
        buttonStateA = true;
        buttonStateB = true;
      }
    }
    Serial.print(m3);
    while (Serial.available() == 0) {}
    if (Serial.available()) {
      String num2 = Serial.readStringUntil('\n');
      Serial.println(num2);
      if (num2 == "00") {
        buttonStateC = false;
        buttonStateD = false;
      }
      if (num2 == "01") {
        buttonStateC = false;
        buttonStateD = true;
      }
      if (num2 == "10") {
        buttonStateC = true;
        buttonStateD = false;
      }
      if (num2 == "11") {
        buttonStateC = true;
        buttonStateD = true;
      }
    }
  }



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

    if (buttonStateB && buttonStateD) {
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

    if (buttonStateB || buttonStateD) {
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

    if (buttonStateB ^ buttonStateD) {
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
      ledPinA0 = false;
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
      ledPinS0 = false;
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
void control() {


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

  if (ledPinError) {
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
  digitalWrite(ledPinB, LOW);   //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, LOW);   //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void dos() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, LOW);   //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void tres() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, LOW);   //Quinto
  digitalWrite(ledPinE, LOW);   //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void cuatro() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, LOW);   //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, LOW);   //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void cinco() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, LOW);   //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void seis() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void siete() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, LOW);   //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, LOW);   //Quinto
  digitalWrite(ledPinE, LOW);   //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
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
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, LOW);   //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void a() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void b() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, LOW);   //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void c() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, LOW);   //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void d() {
  digitalWrite(ledPinA, HIGH);  //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, LOW);   //Segudo
  digitalWrite(ledPinF, LOW);   //Primero
  digitalWrite(ledPinG, HIGH);  //Tercero
}
void e() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, HIGH);  //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
void f() {
  digitalWrite(ledPinA, LOW);   //Sexto
  digitalWrite(ledPinB, HIGH);  //Cuarto
  digitalWrite(ledPinC, LOW);   //Septimo
  digitalWrite(ledPinD, HIGH);  //Quinto
  digitalWrite(ledPinE, HIGH);  //Segudo
  digitalWrite(ledPinF, HIGH);  //Primero
  digitalWrite(ledPinG, LOW);   //Tercero
}
