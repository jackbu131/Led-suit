#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>
int blueLocation = 0;
int delayBlue = 100;
//int delayDark = 75;
int whiteNum = 0xFF;
int blueInd=0;
void blueYellowLoop() {

  for (int j=blueLocation;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      legRight.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        legRight.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
      Serial.println("yello");
  }
    blueInd=0;
  for (int j=0;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      legLeft.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        legLeft.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
  }
    blueInd=0;
  for (int j=0;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      body.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        body.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
  }
    blueInd=0;
  for (int j=0;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      handLeft.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        handLeft.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
  }
    blueInd=0;
  for (int j=0;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      handRight.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        handRight.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
  }
    blueInd=0;
  for (int j=0;j<RL_PIXEL_COUNT;j++){
    if (blueInd<3){
      head.setPixelColor(j,handRight.Color(0/10,whiteNum/10,0/10));
      } else {
        head.setPixelColor(j,handRight.Color(whiteNum/10,0/10,whiteNum/10));
      }
      blueInd++;
      if(blueInd==6){
        blueInd=0;
      }
  }
    blueInd=0;




  handRight.show();
  handLeft.show();
  legRight.show();
  legLeft.show();
  body.show();
  head.show();
  delay(delayBlue);
    
  
blueLocation++;
if(blueLocation==4){blueLocation=0;}
  
}



