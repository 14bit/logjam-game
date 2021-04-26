#include <Servo.h>

// servo positions
int dispenserPos = 90;
int timer;
int marbles = 17;
bool going = false;

Servo dispenser;

void setup() {
  //button
  pinMode(7, INPUT_PULLUP);
  dispenser.attach(5);
  timer = (random(3, 10) * 1000);

  going = false;

  //LEDs
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //buzzer
  pinMode(13, OUTPUT);

}

void loop() {

  if (going == false) {  
    if(digitalRead(7) == LOW) {
        //Start/reset
        noTone(13);
        dispenser.write(90);
        timer = (random(4, 10) * 1000);
        marbles = 17;
        digitalWrite(9, HIGH);  
        digitalWrite(10, HIGH);  
        digitalWrite(11, HIGH);
        delay (500);
        digitalWrite(9, LOW);  
        digitalWrite(10, LOW);  
        digitalWrite(11, LOW);    
        going = true;
    }   
  } else {

  if (marbles <= 0) {
    going = false;  
  }

  delay(1);
  timer -= 1;
  timer = constrain(timer, 0, 10000);

   //red
  if (timer == 3000) {
    digitalWrite(9, HIGH);  
  }

  //yellow
  if (timer == 2000) {
     digitalWrite(9, LOW);  
     digitalWrite(10, HIGH);  
  }

  //green
  if (timer == 1000) {
    digitalWrite(10, LOW);  
    digitalWrite(11, HIGH);  
  }

    if(timer == 0) {
     marbles--;
     dispenser.write(50);
     if (marbles == 0) {
        tone(13, 262);
      }
     delay (500);
     noTone(13);
     dispenser.write(90);
     digitalWrite(9, LOW);  
     digitalWrite(10, LOW);  
     digitalWrite(11, LOW);  
     timer = (random(3, 10) * 1000);
    }  
  }
}
