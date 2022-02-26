#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>

int ZERO = 6;
int *funcDecoder;
int intensityForMusic = 7;
int intensity=4;
double numOfColorSnake= 2.0;
const int PUSH_BUTTON_PIN1 = 23;
const int PUSH_BUTTON_PIN2 = 19;
const int PUSH_BUTTON_PIN3 = 17;
const int PUSH_BUTTON_PIN4 = 21;
////////////////////////////////////////////////////////////////////////////////
// MAIN SKETCH FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

void setup() {
  utilitySetup();
  funcDecoder = &ZERO;
}

void loop() {
  switch(*funcDecoder){
    case 0:{ basicMusicLoop();
    
      break;
    }
    case 1:{complexMusicLoop();
    
      break;
    }
    case 2:{basicMusicLoopFour();
    
      break;
    }case 3:{
      if(numOfColorSnake== 6.0){
        numOfColorSnake=0.0;
      }
      else{
       numOfColorSnake++;
      }
      snakeLoop();
      break;
    }
    case 5:{
        flickerLoop();
      break;
    }
     case 6:{blueYellowLoop();
      break;
    }
  }
}

