
const int led = 12;


void setup() {
  
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  // setup led and pot (dial) pins 
  pinMode(led, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);

  // led ground 
  digitalWrite(8, LOW);
  
  // pot(dial) power and ground
  digitalWrite(3, LOW);
  digitalWrite(7, HIGH);
}

void loop() {
  
  simon_says_dail(2);
  simon_says_dail(1);
  simon_says_dail(4);
  simon_says_dail(3);
  
  celebrate();
}

void simon_says_dail(int pos){
  // blink n times, then check if the dial has been moved to that position.
  blink_n_times(pos);
  delay(2000);
  if (get_dial_quad() != pos){
    dead();
  }else{
    blink();
  }
}

void blink_n_times(int n){
  
  for (int i=0; i<n; i++){
    blink_led(led);
  }
}


int get_dial_quad(){
  // get the position of dial as 1,2,3, or 4.
  
  if (analogRead(A0) < 230){
    return 4;
  }else if (analogRead(A0) < 450){
    return 3;
  } else if (analogRead(A0) < 790){
    return 2;
  } else{
    return 1;
  }
}

void blink_led(int pin){
  
  digitalWrite(pin, HIGH);
  delay(400);
  digitalWrite(pin, LOW);
  delay(400);
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