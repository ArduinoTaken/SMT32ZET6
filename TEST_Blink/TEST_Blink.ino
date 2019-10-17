/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  Modified by Roger Clark. www.rogerclark.net for Maple mini 25th April 2015 , where the LED is on PB1
  
 */

int led_status = HIGH;
int LED_PIN = PE6;
int KEY2_PIN = PA0;
int loop_count=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PB1 as an output.
  pinMode(LED_PIN, OUTPUT);
  //pinMode(KEY2_PIN, INPUT_PULLUP); //PE4
  pinMode(KEY2_PIN,INPUT_PULLDOWN);  //PA0
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(KEY2_PIN) == HIGH){
    while(digitalRead(KEY2_PIN) == HIGH){
      delay(5);  
    }
    Serial.println("key2 press");
    digitalWrite(LED_PIN, led_status);
    led_status=!led_status;
  }
  delay(10); 
  loop_count +=1;
  if(loop_count >100)
  {
    Serial.println("one loop done.");
    loop_count=0;
  }
  
}
