

void setup() {
  
  // setup pins for wiring puzzle
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  pinMode(10, OUTPUT);
  pinMode(8, INPUT);
  
  
  // setup pins for supplying power to dial (pot)
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  
}


void loop() {
  
  check_connection(5, 6);
  check_connection(10, 8);
  check_dial();
  
  celebrate();
}

void check_dial(){
  
  delay(700);
  
  if (analogRead(A0) > 400){
    dead();
  }
  
  if (analogRead(A0) < 230){
    dead();
  }
  
   blink();
}



void blink(){
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(700);
  digitalWrite(LED_BUILTIN, LOW);
  
}

void check_connection(int from, int to){
  // checks that a specific pin is connected to another with a jumper wire
  
  digitalWrite(from, LOW);
  delay(300);
  
  if (digitalRead(to) != false){
    dead();
  }
  digitalWrite(from, HIGH);
  delay(300);
  if (digitalRead(to) != true){
    dead();
  }
  blink();
}
  
void dead(){
  // game over
  while(1){
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void celebrate(){
  // puzzle complete
  while(1){
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(50);                       
    digitalWrite(LED_BUILTIN, LOW);   
    delay(50);                       
  }
}
  
  
  
  



