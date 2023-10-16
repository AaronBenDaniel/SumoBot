#define FORWARD 2
#define REVERSE 1
#define LEFT 4
#define RIGHT 3
#define B1 10
#define B2 9
#define A1 5
#define A2 6
int sensR;
int sensL;

void setup() {
  // put your setup code here, to run once:
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
  delay(3000);
}

void motor (int direction) {
  switch (direction) {
    case REVERSE:
      digitalWrite(B1, HIGH);
      digitalWrite(B2, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, HIGH);
      break;
    case FORWARD:
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, LOW);
      break;
    case RIGHT:
      digitalWrite(B1, HIGH);
      digitalWrite(B2, LOW);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, LOW);
      break;
    case LEFT:
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(A1, LOW);
      digitalWrite(A2, HIGH);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  
  sensR = analogRead(3);
  sensL = analogRead(4);
  
  Serial.print(sensL);
  Serial.print('\t');
  Serial.println(sensR);

  motor(FORWARD);

  if (sensR < 900){
    motor(LEFT);
    delay(2000);
  }

  if (sensL < 900){
    motor(RIGHT);
    delay(2000);
  }

  delay(100);
}
