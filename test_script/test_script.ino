#include <Servo.h>

#define MOTOR1 47

#define SONAR_ECHO 12
#define SONAR_TRIGGER 2
#define MB_BAUDRATE 9600 


Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(MOTOR1);

  pinMode(SONAR_ECHO, INPUT);
  pinMode(SONAR_TRIGGER, OUTPUT);
  
  Serial.begin(MB_BAUDRATE); // // Serial Communication is starting with 9600 of baudrate speed
    
}

bool first = true;

String result ="";
long duration; // variable for the duration of sound wave travel
int distance;
int position= 0;
bool on = false;
void loop() {
  if(Serial.available() >0) {
    result =(Serial.read());
    on = true;
  }
  if(on){
    Serial.println(result);
    servo.write(45);
//     for (position = 0; position <= 180; position += 9) { 
//      scan();
//      servo.write(position);              // tell servo to go to position in variable 'pos'
//      delay(100);                       // waits 15 ms for the servo to reach the position
//    }
//    for (position = 180; position >= 0; position -= 9) { // goes from 180 degrees to 0 degrees
//  //    scan();
//      servo.write(position);              // tell servo to go to position in variable 'pos'
//      delay(100);                       // waits 15 ms for the servo to reach the position
//    }  
  on = false;
  }
   delay(100);
   Serial.print("cica");
}

void scan() {
      digitalWrite(SONAR_TRIGGER, LOW);
      delayMicroseconds(2);
      digitalWrite(SONAR_TRIGGER, HIGH);
      delayMicroseconds(10);
      digitalWrite(SONAR_TRIGGER, LOW);
      duration = pulseIn(SONAR_ECHO, HIGH);
      distance = duration * 0.034 / 2;
      Serial.print(position);
      Serial.print(-181);
      Serial.println(distance);
}
