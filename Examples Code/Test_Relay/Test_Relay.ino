/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#define RL_1 24
#define RL_2 25
#define RL_3 26
#define RL_4 27

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RL_1, OUTPUT);
  pinMode(RL_2, OUTPUT);
  pinMode(RL_3, OUTPUT);
  pinMode(RL_4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(RL_1, HIGH);  
  digitalWrite(RL_2, HIGH);
  digitalWrite(RL_3, HIGH);
  digitalWrite(RL_4, HIGH);
  
  delay(3000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(RL_1, LOW);  
  digitalWrite(RL_2, LOW);
  digitalWrite(RL_3, LOW);
  digitalWrite(RL_4, LOW);
  delay(3000);                       // wait for a second
}
