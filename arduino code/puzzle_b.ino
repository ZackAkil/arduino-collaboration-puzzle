

void setup() {
  
  // setup pins for wiring puzzle
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, INPUT);
  
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  
  // setup speaker pins
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
}

void loop() {
  
  check_connection(8, 7);
  play_beeps(6); // speaker should be connected from 4 -> 5
  check_connection(12, 6);
  
  celebrate();
}


void play_beeps(int beeps){
  
  for (int i=0; i<beeps; i++){
    delay(600);
    tone(5, 587, 300);
  }
  
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