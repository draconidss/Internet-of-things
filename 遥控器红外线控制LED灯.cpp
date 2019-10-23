#include <IRremote.h>

IRrecv irrecv_5(5);
decode_results results_5;

long ir_item;
volatile int led;
volatile boolean ledsate;

void setup(){
  led = 0;
  ledsate = 0;
  Serial.begin(9600);
  irrecv_5.enableIRIn();
}

void loop(){
  if (irrecv_5.decode(&results_5)) {
    ir_item=results_5.value;
    String type="UNKNOWN";
    String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
    if(results_5.decode_type>=1&&results_5.decode_type<=13){
      type=typelist[results_5.decode_type];
    }
    Serial.print("IR TYPE:"+type+"  ");
    Serial.println(ir_item,HEX);
    if (ir_item == 0xFF629D) {
      ledsate = !ledsate;
      led = ledsate * 128;

    }
    if (ir_item == 0xFFF21D) {
      led = constrain(led + 20, 1, 255);

    }
    if (ir_item == 0xFFA25D) {
      led = constrain(led - 20, 1, 255);

    }
    analogWrite(10,led);
    irrecv_5.resume();
  } else {
  }

}
