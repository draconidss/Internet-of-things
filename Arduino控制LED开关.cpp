volatile int LED;
volatile int SW;
volatile int b1;
volatile int b2;
volatile int click;
volatile int lastState;
volatile int toggle;

int mixly_digitalRead(uint8_t pin) {
  pinMode(pin, INPUT);
  return digitalRead(pin);
}

void setup(){
  LED = 13;
  SW = 8;
  lastState = mixly_digitalRead(SW);
  toggle = 0;
  click = 0;
  b1 = 0;
  b2 = 0;
  Serial.begin(9600);
}

void loop(){
  pinMode(SW, INPUT_PULLUP);
  b1 = mixly_digitalRead(SW);
  Serial.println(b1);
  if (b1 != lastState) {
    delay(20);
    b2 = mixly_digitalRead(SW);
    if (b1 == b2) {
      lastState = b1;
      click = click + 1;

    }

  }
  if (click == 2) {
    click = 0;
    toggle = 1 - toggle;
    if (toggle == true) {
      pinMode(LED, OUTPUT);
      digitalWrite(LED,HIGH);

    } else {
      pinMode(LED, OUTPUT);
      digitalWrite(LED,LOW);

    }

  }

}
