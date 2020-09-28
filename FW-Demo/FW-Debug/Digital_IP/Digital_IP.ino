#define IP1 40
#define IP2 42
#define IP3 44
#define IP4 46


#define RY1 24
#define RY2 25
#define RY3 26
#define RY4 27

void setup() {
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);
}

void loop() {
  digitalWrite(RY1, !digitalRead(IP1));
  digitalWrite(RY2, !digitalRead(IP2));
  digitalWrite(RY3, !digitalRead(IP3));
  digitalWrite(RY4, !digitalRead(IP4));
}
