#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>

int sizeOfSnake  = 7;
int delaySnake = 4;
int RED_SNAKE = 0;
 int GREEN_SNAKE = 0;
 int BLUE_SNAKE = 0;
  // default color

void snakeLoop() {
    setColorFunc(&numOfColorSnake, &RED_SNAKE , &GREEN_SNAKE , &BLUE_SNAKE);

    for (int j=0; j<RL_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            legRight.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        legRight.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            legRight.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
        }
        legRight.show();
    }
    for (int j=0; j<LL_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            legLeft.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        legLeft.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            legLeft.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
        }
        legLeft.show();
    }
    for (int j=0; j<B_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            body.setPixelColor(k,body.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        body.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            body.setPixelColor(k,body.Color(0x00,0x00,0x00));
        }
        body.show();
    }
    for (int j=0; j<LH_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            handLeft.setPixelColor(k,body.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        handLeft.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            handLeft.setPixelColor(k,body.Color(0x00,0x00,0x00));
        }
        handLeft.show();
    }
    for (int j=0; j<RH_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            handRight.setPixelColor(k,body.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        handRight.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
        handRight.setPixelColor(k,body.Color(0x00,0x00,0x00));
        }
        handRight.show();
    }
    for (int j=0; j<HE_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            head.setPixelColor(k,body.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        head.show();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            head.setPixelColor(k,body.Color(0x00,0x00,0x00));
        }
        head.show();
        }
    }
}



