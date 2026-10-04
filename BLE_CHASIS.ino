// BLUETOOTH CHASIS INSTRUCTIONS
#include <SoftwareSerial.h>
SoftwareSerial bt(3, 2);  //Rx, Tx
int m11 = 4;
int m12 = 5;
int m21 = 6;
int m22 = 7;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() {
  if (bt.available()) {
    char ch = bt.read();
    if (ch == 'f'){
      fwd();
    }
    if (ch == 'b'){
      rev();
    }
    if (ch == 'r'){
      rht();
    }
    if (ch == 'l'){
      lft();
    }
    if (ch == 's'){
      stp();
    }
  }
}

void fwd() {
  digitalWrite(m11, 1);
  digitalWrite(m12, 0);
  digitalWrite(m21, 1);
  digitalWrite(m22, 0);
}

void rht() {
  digitalWrite(m11, 1);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 1);
}

void rev() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 1);
  digitalWrite(m21, 1);
  digitalWrite(m22, 0);
}

void lft() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 1);
  digitalWrite(m21, 0);
  digitalWrite(m22, 1);
}
void stp() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 0);
}
