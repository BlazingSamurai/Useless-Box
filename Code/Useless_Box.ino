#include <Servo.h>
int valo = 0;
int valn;

int toggle = 13;
int state = 0;

Servo arm;
Servo top;

void setup(){
  arm.attach(3);
  top.attach(9);
  Serial.begin(9600);
  pinMode(toggle, INPUT_PULLUP);
  top.write(8);
  arm.write(5);
  
}

void loop(){
  valn = digitalRead(toggle);
  Serial.print("PINN = ");
  Serial.println(valn);

  if (valo == 0 && valn == 1) {
    state++;
    
    Serial.print("STATE = ");
    Serial.println(state);
    if (state == 1){
    top.write(75);
    delay(1500);
    arm.write(169);
   
  }
  if (state == 2){
    top.write(75);
    delay(1000);
    arm.write(150);
    delay(500);
    arm.write(80);
    delay(500);
    arm.write(169);
  }
  if (state == 3){
    top.write(75);
    delay(1500);
    arm.write(150);
    delay(900);
    arm.write(8);
    delay(1000);
    top.write(8);
    delay(800);
    top.write(75);
    delay(400);
    arm.write(169);
    
   
  }
  if (state == 5){
    top.write(75);
    delay(1500);
    top.write(8);
    delay(500);
    top.write(50);
    delay(500);
    top.write(8);
    delay(500);
    top.write(40);
    delay(500);
    top.write(8);
    delay(500);
    top.write(75);
    delay(1500);
    arm.write(169);
    state = 0;
   
   
  }
  if (state == 4){
    top.write(75);
    delay(1000);
    arm.write(60);
    delay(500);
    arm.write(90);
    delay(500);
    arm.write(135);
    delay(500);
    arm.write(169);
    delay(200);
   
  }
  }
  
  
  if (valo == 1 && valn == 0) {
    arm.write(5);
    delay(1000);
    top.write(8); 
  }
   valo = valn;
   valn = digitalRead(toggle);
   delay(100);
  
}
