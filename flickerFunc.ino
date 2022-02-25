#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>
int FlickerLocation = 0;
int delayLight = 7;
int delayDark = 75;
void flickerLoop() {
int whiteNum = 0xFF;

    for (int j=FlickerLocation; j<RL_PIXEL_COUNT; j=j+3){
      
          legRight.setPixelColor(j,colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));
   
           
    }
          for (int j=FlickerLocation; j<LL_PIXEL_COUNT; j=j+3){
      
          legLeft.setPixelColor(j,colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));
   
          }
      for (int j=FlickerLocation; j<B_PIXEL_COUNT; j=j+3){
      
          body.setPixelColor(j,colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));
          
   
          } 
      for (int j=FlickerLocation; j<LH_PIXEL_COUNT; j=j+3){
        handLeft.setPixelColor(j,colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));
   
          } 
          for (int j=FlickerLocation; j<RH_PIXEL_COUNT; j=j+3){
        handRight.setPixelColor(j,colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));

          }
      for (int j=FlickerLocation; j<HE_PIXEL_COUNT; j=j+3){
         head.setPixelColor(j, colorClass.Color(whiteNum/intensity,whiteNum/intensity,whiteNum/intensity));
          }
          
  handRight.show();
  handLeft.show();
  legRight.show();
  legLeft.show();
  body.show();
  head.show();
  delay(delayLight);
      for (int j=FlickerLocation; j<RL_PIXEL_COUNT; j=j+3){
      
          legRight.setPixelColor(j,colorClass.Color(0x00, 0x00, 0x00));
   
           
    }
          for (int j=FlickerLocation; j<LL_PIXEL_COUNT; j=j+3){
      
          legLeft.setPixelColor(j,colorClass.Color(0x00, 0x00, 0x00));
   
          }
      for (int j=FlickerLocation; j<B_PIXEL_COUNT; j=j+3){
      
          body.setPixelColor(j,colorClass.Color(0x00, 0x00, 0x00));
          
   
          } 
      for (int j=FlickerLocation; j<LH_PIXEL_COUNT; j=j+3){
        handLeft.setPixelColor(j,colorClass.Color(0x00, 0x00, 0x00));
   
          } 
          for (int j=FlickerLocation; j<RH_PIXEL_COUNT; j=j+3){
        handRight.setPixelColor(j,colorClass.Color(0x00, 0x00, 0x00));

          }
      for (int j=FlickerLocation; j<HE_PIXEL_COUNT; j=j+3){
         head.setPixelColor(j, colorClass.Color(0x00, 0x00, 0x00));
          }
    handRight.show();
  handLeft.show();
  legRight.show();
  legLeft.show();
  body.show();
  head.show();
  delay(delayDark);
  
FlickerLocation++;
if(FlickerLocation==4){FlickerLocation=0;}
  
}



