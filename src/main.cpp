#include "Arduino.h"
int in1 = 2;
int in2 = 4;
int inA = 3;

int in3 = 5;
int in4 = 7;
int inB = 6;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(inA, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(inB, OUTPUT);
}
void loop(){
  while(Serial.available() > 0){

    if(Serial.readString() == "move"){
      int velosity = Serial.read() - '0';
      while(velosity != -1){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        digitalWrite(inA, velosity);
        digitalWrite(inB, velosity);
      }
    } else if(Serial.readString() == "rotate"){
      if(Serial.readString() == "left"){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        digitalWrite(inA, 100);
        digitalWrite(inB, 100);
        delay(1500);
      }else if(Serial.readString() == "right"){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(inA, 100);
        digitalWrite(inB, 100);
        delay(1500);
      }
      else{
        delay(1500);
      }
    }
    else{
      delay(1500);
    }
  }
}
