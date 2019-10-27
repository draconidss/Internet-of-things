volatile boolean a;
volatile boolean b;
volatile int brightness;
volatile int click;
volatile boolean lastState;

void setup(){
  a = 0;
  b = 0;
  lastState = 0;
  click = 0;
  pinMode(2, INPUT);
  brightness = 0;
  pinMode(0, INPUT_PULLUP);
  lastState = digitalRead(2);
  Serial.begin(9600);
}

void loop(){
  a = digitalRead(2);
  if (a != b) {
    delay(20);
    b = digitalRead(2);
    if (a == b) {
      lastState = a;
      click = click + 1;

    }
    if (click == 2) {
      click = 0;
      brightness = (long) ((brightness + 1)) % (long) (6);
      Serial.println(brightness);
      analogWrite(10,(brightness * 45));

    }

  }

  lastState = digitalRead(2);

}
