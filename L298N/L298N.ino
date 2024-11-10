/*馬達*/
#define MotorA_I1 42
#define MotorA_I2 40 /*左前輪*/
#define MotorB_I1 43
#define MotorB_I2 41 /*右前輪*/

#define MotorA_PWMA 6
#define MotorB_PWMB 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(MotorA_I1, OUTPUT); /*馬達設置*/
  pinMode(MotorA_I2, OUTPUT);
  pinMode(MotorB_I1, OUTPUT);
  pinMode(MotorB_I2, OUTPUT);
  pinMode(MotorA_PWMA, OUTPUT);
  pinMode(MotorB_PWMB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void advance_forward(byte motorAspeed, byte motorBspeed) {
  analogWrite(MotorA_PWMA, motorAspeed);
  analogWrite(MotorB_PWMB, motorBspeed);

  digitalWrite(MotorA_I1, HIGH);
  digitalWrite(MotorA_I2, LOW);
  digitalWrite(MotorB_I1, HIGH);
  digitalWrite(MotorB_I2, LOW);
}

void advance_right(byte motorAspeed, byte motorBspeed) {
  analogWrite(MotorA_PWMA, motorAspeed);
  analogWrite(MotorB_PWMB, motorBspeed);

  digitalWrite(MotorA_I1, LOW);
  digitalWrite(MotorA_I2, HIGH);
  digitalWrite(MotorB_I1, HIGH);
  digitalWrite(MotorB_I2, LOW);
}
void advance_left(byte motorAspeed, byte motorBspeed) {
  analogWrite(MotorA_PWMA, motorAspeed);
  analogWrite(MotorB_PWMB, motorBspeed);

  digitalWrite(MotorA_I1, HIGH);
  digitalWrite(MotorA_I2, LOW);
  digitalWrite(MotorB_I1, LOW);
  digitalWrite(MotorB_I2, HIGH);
}

void advance_stop() {
  analogWrite(MotorA_PWMA, 0);
  analogWrite(MotorB_PWMB, 0);

  digitalWrite(MotorA_I1, LOW);
  digitalWrite(MotorA_I2, LOW);
  digitalWrite(MotorB_I1, LOW);
  digitalWrite(MotorB_I2, LOW);
}
void advance_back(byte motorAspeed, byte motorBspeed) {
  analogWrite(MotorA_PWMA, motorAspeed);
  analogWrite(MotorB_PWMB, motorBspeed);

  digitalWrite(MotorA_I1, LOW);
  digitalWrite(MotorA_I2, HIGH);
  digitalWrite(MotorB_I1, LOW);
  digitalWrite(MotorB_I2, HIGH);

}