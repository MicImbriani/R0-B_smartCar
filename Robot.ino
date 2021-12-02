int STBY = 3;   //STBY
int EnR = 5;    //PWMA
int EnL = 6;    //PWMB
int Rforw = 7;  //AIN1 == AIN2
int Lforw = 8;  //BIN1 == BIN2

float baseDistance = 120.;
float baseSpeed = 255.;

float forwardRate = 96.5;
float rotationRate = 520.;

float rotSpeed = 170.;
float rotationRate2 = 650.;

void setup() {  
  Serial.begin(9600);
  
  pinMode(STBY, OUTPUT);
  pinMode(EnR, OUTPUT);
  pinMode(EnL, OUTPUT);
  pinMode(Rforw, OUTPUT);
  pinMode(Lforw, OUTPUT);
  
  digitalWrite(STBY, HIGH); //HIGH => move, LOW => standby
  analogWrite(EnR, 255);
  analogWrite(EnL, 255);
}

void loop() {
//  loool(193, 255.);
//  stopCar();
  turnRight(180., 100.);
  stopCar();
//  loool(193, 100);
//  stopCar();
  turnRight(270., 50.);
  stopCar();
  turnRight(360., 100.);
  terminate();

//  digitalWrite(STBY, HIGH);
//  analogWrite(EnR, 170);
//  analogWrite(EnL, 170);
//  
//  digitalWrite(Rforw, LOW);
//  digitalWrite(Lforw, HIGH);
//
//  delay(2000);
//  terminate();
}

float newForwardRate(float speed) {
  return (forwardRate * speed / baseSpeed);
}

void loool(float distance, float speed) {
  digitalWrite(STBY, HIGH);
  analogWrite(EnR, speed);
  analogWrite(EnL, speed);
  
  digitalWrite(Rforw, HIGH);
  digitalWrite(Lforw, HIGH);

  float rate = newForwardRate(speed);
  float t = distance / rate * 1000; 
  delay(t);
}



float computeDistanceInOneSec(float newSpeed) {
  return baseDistance * newSpeed / baseSpeed;
}

//float computeTimeWithoutSpeed(float distanceToRun, float distaceInOneSec){
//  return distanceToRun / distaceInOneSec;
//  }

float computeTimeWithSpeed(float distanceToRun, float speed){
  float distanceInOneSec = computeDistanceInOneSec(speed);
  return distanceToRun / distanceInOneSec * 1000.;
  }


 void turnLeft() {
  digitalWrite(Rforw, HIGH);
  digitalWrite(Lforw, LOW);
  delay(100);
}

void turnRight(float degree, float speed) {
  digitalWrite(STBY, HIGH);
  analogWrite(EnR, speed);
  analogWrite(EnL, speed);
  
  digitalWrite(Rforw, LOW);
  digitalWrite(Lforw, HIGH);

//  float w = rotationRate * speed / baseSpeed;
//  float t = degree / w;

  float w = rotationRate2 * speed / rotSpeed;
  float t = degree / w;
  delay(t*1000);
//  stopCar();
}

void stopCar() {
  digitalWrite(STBY, LOW); //HIGH => move, LOW => standby
  delay(1000);
}

void terminate(){
  digitalWrite(STBY, LOW);
  while(1==1){}
}
