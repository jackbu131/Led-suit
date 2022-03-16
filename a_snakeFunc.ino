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
    clear_all();
    setColorFunc(&numOfColorSnake, &RED_SNAKE , &GREEN_SNAKE , &BLUE_SNAKE);

    setSnakeAll();
}

void setSnakeAll(){
    for (int j=0; j<HE_PIXEL_COUNT; j++){
        for (int k=j; k<j+sizeOfSnake; k++){
            right_front_center.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            right_front_right.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            left_front_center.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            left_front_left.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            back_center.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            back_left.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
            back_right.setPixelColor(k,colorClass.Color(RED_SNAKE , GREEN_SNAKE , BLUE_SNAKE));
        }
        show_all();
        delay(delaySnake);
        for (int k=j; k<j+sizeOfSnake; k++){
            right_front_center.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            right_front_right.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            left_front_center.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            left_front_left.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            back_center.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            back_left.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
            back_right.setPixelColor(k,colorClass.Color(0x00,0x00,0x00));
        }
        show_all();
        }
}
