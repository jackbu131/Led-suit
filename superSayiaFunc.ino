#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>


void superSayiaLoop() {

    for (int j=0; j<RL_PIXEL_COUNT; j++){
      
          legRight.setPixelColor(j,handRight.Color(0xFF/5,0xD7/5,0x00));
   
           
    }
          for (int j=0; j<LL_PIXEL_COUNT; j++){
      
          legLeft.setPixelColor(j,handRight.Color(0xFF/5,0xD7/5,0x00));
   
          }
      for (int j=0; j<B_PIXEL_COUNT; j++){
      
          body.setPixelColor(j,handRight.Color(0xFF/5,0xD7/5,0x00));
          
   
          } 
      for (int j=0; j<LH_PIXEL_COUNT; j++){
        handLeft.setPixelColor(j,handRight.Color(0xFF/5,0xD7/5,0x00));
   
          } 
          for (int j=0; j<RH_PIXEL_COUNT; j++){
        handRight.setPixelColor(j,handRight.Color(0xFF/5,0xD7/5,0x00));

          }
      for (int j=0; j<HE_PIXEL_COUNT; j++){
         head.setPixelColor(j, handRight.Color(0xFF/5,0xD7/5,0x00));
          }
          
  handRight.show();
  handLeft.show();
  legRight.show();
  legLeft.show();
  body.show();
  head.show();
  delay(1);
      for (int j=0; j<RL_PIXEL_COUNT; j++){
      
          legRight.setPixelColor(j,handRight.Color(0x00, 0x00, 0x00));
   
           
    }
          for (int j=0; j<LL_PIXEL_COUNT; j++){
      
          legLeft.setPixelColor(j,handRight.Color(0x00, 0x00, 0x00));
   
          }
      for (int j=0; j<B_PIXEL_COUNT; j++){
      
          body.setPixelColor(j,handRight.Color(0x00, 0x00, 0x00));
          
   
          } 
      for (int j=0; j<LH_PIXEL_COUNT; j++){
        handLeft.setPixelColor(j,handRight.Color(0x00, 0x00, 0x00));
   
          } 
          for (int j=0; j<RH_PIXEL_COUNT; j++){
        handRight.setPixelColor(j,handRight.Color(0x00, 0x00, 0x00));

          }
      for (int j=0; j<HE_PIXEL_COUNT; j++){
         head.setPixelColor(j, handRight.Color(0x00, 0x00, 0x00));
          }
    handRight.show();
  handLeft.show();
  legRight.show();
  legLeft.show();
  body.show();
  head.show();
  delay(25);
}



