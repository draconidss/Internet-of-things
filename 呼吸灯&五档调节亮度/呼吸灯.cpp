
void fadeOff(int time) {
  for (int time = 255; time >= 0; time = time + (-5)) {
    analogWrite(10,i);
    delay(((time / 255) / 5));
  }
}

void fadeOn(int time) {
  for (int time = 255; time >= 0; time = time + (5)) {
    analogWrite(10,i);
    delay(((time / 255) / 5));
  }
}

void setup(){

}

void loop(){
  fadeOn(2000);
  fadeOff(2000);

}
