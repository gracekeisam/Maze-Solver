#define TRIG_F  13   // Front sensor trig
#define ECHO_F  12   // Front sensor echo

#define TRIG_L  27   // Left sensor trig
#define ECHO_L  26   // Left sensor echo

#define TRIG_R  25   // Right sensor trig
#define ECHO_R  23   // Right sensor echo



#define IN3 19   // Motor A input 1
#define IN4 18   // Motor A input 2

#define IN1 33   // Motor B input 1
#define IN2 32   // Motor B input 2

#define pwm1 21 
#define pwm2 22

#define THRESHOLD 50   // Distance in cm to consider as wall



void setup() {
  Serial.begin(9600);

  pinMode(TRIG_F, OUTPUT); 
  pinMode(ECHO_F, INPUT);

  pinMode(TRIG_L, OUTPUT); 
  pinMode(ECHO_L, INPUT);

  pinMode(TRIG_R, OUTPUT); 
  pinMode(ECHO_R, INPUT);

  pinMode(pwm1, OUTPUT); 
  pinMode(pwm2, OUTPUT); 

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);

  stopBot();
}


void loop() {
  long dFront = getDistance(TRIG_F, ECHO_F);
  long dLeft  = getDistance(TRIG_L, ECHO_L);
  long dRight = getDistance(TRIG_R, ECHO_R);

  Serial.print("Front: "); Serial.print(dFront);
  Serial.print(" | Left: "); Serial.print(dLeft);
  Serial.print(" | Right: "); Serial.println(dRight);
  analogWrite(pwm1,200);
  analogWrite(pwm2,200);

  if (dFront > 5) {
    forward();
    delay(10);
  } else {
    stopBot();
    if (dLeft > dRight && dLeft > 5) {
      leftTurn();
    } else if (dRight > 5) {
      rightTurn();
    } else {
      backward();
      delay(100);
    }
  }
}



long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); 
  long distance = duration * 0.034 / 2;        
  return distance;
}


void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void leftTurn() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  delay(300);
}

void rightTurn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  delay(300);
}

void stopBot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW);
}
