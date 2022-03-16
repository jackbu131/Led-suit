#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>
int FlickerLocation = 0;
int delayLight = 7;
int delayDark = 75;


void flickerLoop() {
  int flicker_intesity = 4;
  int whiteNum = 0xFF;
  uint32_t col = back_right.Color(whiteNum/flicker_intesity,whiteNum/flicker_intesity,whiteNum/flicker_intesity);
  for (int j=FlickerLocation; j<MAX_NUM_OF_LEDS; j=j+3){
      set_color_all_strips(j, col);
  }
  show_all();
  delay(delayLight);
  clear_all();
  show_all();
  delay(delayDark);

  FlickerLocation++;
  if(FlickerLocation==4){FlickerLocation=0;}
}
