#include <Servo.h>
int pinoLdr=A4;
int pinoServo=3;
int valorLdr=0;
int posiServo = 0;
int sentido = 1;
Servo s;

void setup() {
  pinMode(pinoLdr, INPUT);
  pinMode(pinoServo, OUTPUT);
  Serial.begin(9600);
  s.attach(pinoServo);
  s.write(0);

}
void loop() {
  valorLdr = analogRead(pinoLdr);
  //Serial.println(valorLdr);
  if(valorLdr>500){
    s.write(posiServo*sentido);
    delay(100);
    posiServo += 5;
    s.write(posiServo*sentido);
    delay(100);
    if(posiServo >= 180){
      posiServo = 0;
    }
  }
  else{
    s.write(posiServo*sentido);
    
    
  }
  delay(100);

}
