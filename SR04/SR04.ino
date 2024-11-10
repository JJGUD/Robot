int F_Echo = 11;
int F_Trig = 12;
float duration,distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(F_Trig, OUTPUT); /*前方超音波設置*/
  pinMode(F_Echo, INPUT);
}
void loop(){
  
}

float ping_d() { //探測距離
  digitalWrite(F_Trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(F_Trig, LOW);
  delayMicroseconds(10);
  duration = pulseIn(F_Echo, HIGH);
  distance = (duration / 2) /29.1;
  Serial.println(distance);
  return distance;
}