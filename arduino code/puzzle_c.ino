
const int pingPin = 7;

void setup() {
  // setup pins for wiring puzzle
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, INPUT);
  
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
  
  // setup pins for sonar sensor
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  
  // for testing distance
  Serial.begin(9600);
}

void loop() {
  
  check_connection(12, 5);
  check_connection(9, 2);
  check_distance(); 
  
  celebrate();
}


void check_distance(){
  // check that the sonar sensor is reading around 30cm.
  
  for (int i=0; i<100; i++){
    get_distance();
    digitalWrite(3, LOW);
    delay(10);
  }
  
   for (int i=0; i<3; i++){
     if (get_distance() > 40){
       dead();
     }else if (get_distance() < 20){
       dead();
     }
     blink();
     delay(500);
   }
  
}


long get_distance(){
  
  long duration;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  Serial.println(microsecondsToCentimeters(duration));

  return microsecondsToCentimeters(duration);
  
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
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