#include "Arduino.h"
const int STOP_VELOCITY = -1;
const int WAITING_TIME = 1500;
int in1 = 2;
int in2 = 4;
int inA = 3;

int in3 = 5;
int in4 = 7;
int inB = 6;

void move(int velocity);
void set_motor_left();
void set_motor_right();

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
      int velocity = Serial.parseInt();
      while(velocity != -1){
        move(velocity);
      }
    }else if(Serial.readString() == "rotate"){
        if(Serial.readString() == "left"){
          set_motor_left();
      }else if(Serial.readString() == "right"){
        set_motor_right();
      }
    }
  }
}

void move(int velocity){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(inA, velocity);
    digitalWrite(inB, velocity);
    delay(WAITING_TIME);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(inA, velocity);
    digitalWrite(inB, velocity);
}

void set_motor_left(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(inA, 100);
    digitalWrite(inB, 100);
    delay(WAITING_TIME);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(inA, 0);
    digitalWrite(inB, 0);
}

void set_motor_right(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(inA, 100);
    digitalWrite(inB, 100);
    delay(WAITING_TIME);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(inA, 0);
    digitalWrite(inB, 0);
}