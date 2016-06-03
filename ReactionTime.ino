boolean notBegun = true;
boolean notBegun2 = true;
boolean done = false;
long startTime;
long startTime2;
long endTime;
long endTime2;
long randomTime;
long randomTime2;
float elapsedTime;
float elapsedTime2;
int randNum;
int randNum2;

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
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(A2) == HIGH && notBegun) {
    Serial.println("Button 1 was pressed.");
    notBegun = false;
    randomTime = random(4,10);
    randomTime = randomTime*1000;
 
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(randomTime);
    
    randNum = random(3,13);
    digitalWrite(randNum, HIGH);
    
    while (digitalRead(A2) == LOW && digitalRead(randNum)==HIGH) {
      delay(1);
      elapsedTime++;
    }
  }
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  elapsedTime = elapsedTime/1000;
  if (elapsedTime > 0 && done==false) {
    Serial.print("Player 1 Time: ");
    Serial.println(elapsedTime);
    
    while (true) {
      elapsedTime2 = loop2();
      if (elapsedTime2 != 0) {
        Serial.print("Player 2 Time: ");
        Serial.println(elapsedTime2);
        break;
      }  
    }
    if (elapsedTime < elapsedTime2) {
      Serial.println("Player 1 Wins!");
      done = true;
      Serial.end();
    }
  
    else if (elapsedTime > elapsedTime2) {
      Serial.println("Player 2 Wins!");  
      done = true;
      Serial.end();
    }
  
    else {
      Serial.println("Tie!"); 
      done = true;
      Serial.end();
    }
  }
}

float loop2() {
  while (digitalRead(A1) == HIGH && notBegun2) {
    Serial.println("Button 2 was pressed.");
    notBegun2 = false;
    randomTime2 = random(4,10);
    randomTime2 = randomTime2*1000;
 
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(randomTime2);
    
    randNum2 = random(3,13);
    digitalWrite(randNum2, HIGH);
    
    while (digitalRead(A1) == LOW && digitalRead(randNum2)==HIGH) {
      delay(1);
      elapsedTime2++;
    }
  }
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  elapsedTime2 = elapsedTime2/1000;
  return elapsedTime2;
}
