int leds[10] = {0,0,0,0,0,1,1,1,1,1};
int p1av = 5;
int p2av = 4;

void setup() {
  pinMode(A2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(A1) == HIGH){
     delay(150);
     leds[p2av] = 1;
     p2av--;
     p1av--;
     if (p2av <= -1){
        p2av = 10;
      }
     Serial.println("A1");
  }
  else if(digitalRead(A2) == HIGH){
      delay(150);
      leds[p1av] = 0;
      p1av++;
      p2av++;
      if (p1av >= 10){
        p1av = 0;
      }
      Serial.println("A2");
  }
  for(int i = 0; i < 10; i++){
     Serial.print(leds[i]);
     if (leds[i] == 0){
        digitalWrite(i+3, HIGH);
     }
     else if(leds[i] == 1){
        digitalWrite(i+3, LOW);
     }
  }
  Serial.println();
  for(int i = 0; i < 10; i++){
    if(leds[i] == 0){
       Serial.print(leds[i]);
    }
    else if(leds[i] == 1){
       Serial.print(leds[i]);
    }
    Serial.println();  
  }
  if(leds[9] == 0) {
    Serial.println("Player 1 Wins!");
    Serial.end();  
  }
  if(leds[0] == 1) {
    Serial.println("Player 2 Wins!");  
    Serial.end();
  }
  
}
