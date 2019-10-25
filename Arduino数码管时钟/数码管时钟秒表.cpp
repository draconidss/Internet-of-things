#include <SevenSegmentExtended.h>
#include <SevenSegmentTM1637.h>

SevenSegmentExtended  display(5,4);
volatile int minute;
volatile int second;

void setup(){
   display.begin();
  second = 0;
  minute = 0;
}

void loop(){
  delay(1000);
  display.printTime(minute,second,HIGH);
  if (second == 59) {
    minute = minute + 1;

  } else {
    second = second + 1;

  }

}
