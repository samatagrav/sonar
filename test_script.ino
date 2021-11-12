#include <Servo.h>

#define MOTOR1 47

#define SONAR_ECHO 11
#define SONAR_TRIGGER 2
//#define MB2_SELECT 46

Servo servo;

void setup() {
  // put your setup code here, to run once:
  //pinMode(MOTOR1, OUTPUT);
  //servo.attach(MOTOR1);

  pinMode(SONAR_ECHO, INPUT);
  pinMode(SONAR_TRIGGER, OUTPUT);

  //pinMode(MB2_SELECT, OUTPUT);

  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  //digitalWrite(MB2_SELECT, LOW);
  digitalWrite(SONAR_TRIGGER, LOW);
}

bool first = true;

long duration; // variable for the duration of sound wave travel
int distance;

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(first){
      //servo.write(20);

      delayMicroseconds(30);

      digitalWrite(SONAR_TRIGGER, LOW);
      delayMicroseconds(2);

      digitalWrite(SONAR_TRIGGER, HIGH);
      delayMicroseconds(10);
      digitalWrite(SONAR_TRIGGER, LOW);

      duration = pulseIn(SONAR_ECHO, HIGH);
      distance = duration * 0.034 / 2;

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      
      first = false;
  }
  
}