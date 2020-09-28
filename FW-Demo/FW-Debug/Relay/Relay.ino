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
  digitalWrite(RY1, HIGH);   
  delay(500);                     
  digitalWrite(RY1, LOW);   
  delay(500);     

  digitalWrite(RY2, HIGH);   
  delay(500);                     
  digitalWrite(RY2, LOW);   
  delay(500);


  digitalWrite(RY3, HIGH);   
  delay(500);                     
  digitalWrite(RY3, LOW);   



  digitalWrite(RY4, HIGH);   
  delay(500);                     
  digitalWrite(RY4, LOW);   
  delay(500);

  delay(500);                       // wait for a second

  for(int i=24;i<28;i++){
    digitalWrite(i, HIGH);
    delay(200);
  }
  delay(500);
  digitalWrite(RY1, LOW);  
  digitalWrite(RY2, LOW);
  digitalWrite(RY3, LOW);
  digitalWrite(RY4, LOW);
  delay(500);
}
