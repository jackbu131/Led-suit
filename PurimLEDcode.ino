#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>

int ZERO = 0;
int *funcDecoder;
int intensityForMusic = 7;
//int intensity=4;
double numOfColorSnake= 2.0;
//const int PUSH_BUTTON_PIN1 = 23;
//const int PUSH_BUTTON_PIN2 = 19;
//const int PUSH_BUTTON_PIN3 = 17;
//const int PUSH_BUTTON_PIN4 = 21;


const int NUM_OF_WINDOWS_FOR_BASIC_FOUR = 4;  
const int COLOR_MODIFIER = 60;
float frequencyWindowForBasicFour[NUM_OF_WINDOWS_FOR_BASIC_FOUR+1];
float huesForBasicFour[NUM_OF_WINDOWS_FOR_BASIC_FOUR];

const int NUM_OF_WINDOWS_FOR_COMPLEX = 70;  
const int COMPLEX_COLOR_MODIFIER = 60;
float frequencyWindowForComplex[NUM_OF_WINDOWS_FOR_COMPLEX+1];
float huesForComplex[NUM_OF_WINDOWS_FOR_COMPLEX];


int SAMPLE_RATE_HZ = 8000;             // Sample rate of the audio in hertz.
float SPECTRUM_MIN_DB = 30.0;          // Audio intensity (in decibels) that maps to low LED brightness.
float SPECTRUM_MAX_DB = 60.0;          // Audio intensity (in decibels) that maps to high LED brightness.
int LEDS_ENABLED = 1;                  // Control if the LED's should display the spectrum or not.  1 is true, 0 is false.  
     
int INTENCITY_LEVEL_UP_PIN = 10;    
int INTENCITY_LEVEL_DOWN_PIN = 11;       
                                       // Useful for turning the LED display on and off with commands from the serial port.
const int FFT_SIZE = 256;              // Size of the FFT.  Realistically can only be at most 256
                                       // without running out of memory for buffers and other state.
const int AUDIO_INPUT_PIN = A1;        // Input ADC pin for audio data.
const int ANALOG_READ_RESOLUTION = 10; // Bits of resolution for the ADC.
const int ANALOG_READ_AVERAGING = 16;  // Number of samples to average with each ADC reading.
const int POWER_LED_PIN = 13;          // Output pin for power LED (pin 13 to use Teensy 3.0's onboard LED).


const int NEO_PIXEL_PIN17 = 17;
const int NEO_PIXEL_PIN18 = 18;
const int NEO_PIXEL_PIN19 = 19;
const int NEO_PIXEL_PIN20 = 20;
const int NEO_PIXEL_PIN21 = 21;
const int NEO_PIXEL_PIN22 = 22;
const int NEO_PIXEL_PIN23 = 23;

const int ColorManagementFakeOin = 30;

const int RH_PIXEL_COUNT = 47;
const int LH_PIXEL_COUNT = 41;
const int RL_PIXEL_COUNT = 70;
const int LL_PIXEL_COUNT = 80;
const int B_PIXEL_COUNT = 74;
const int HE_PIXEL_COUNT = 40;

const int MAX_NUM_OF_LEDS = 70;


const int MAX_CHARS = 65;              // Max size of the input command buffer


IntervalTimer samplingTimer;
float samples[FFT_SIZE*2];
float magnitudes[FFT_SIZE];
int sampleCounter = 0;

IntervalTimer touchSensorTimer;
bool touchIsOn = false;
int touchSensorValue = 0;
int touchSensorOnCounter = 0;
int touchSensorOffCounter = 0;
const int touchSensorThreshold = 1500;

////////////////////////////////////////////////////////////////////////////////
// MAIN SKETCH FUNCTIONS
////////////////////////////////////////////////////////////////////////////////



void setup() {
  utilitySetup();
  funcDecoder = &ZERO;
}

void loop() {
  switch(*funcDecoder){
//    case 0:{
//      basicMusicLoop();
//      break;
//    }
    case 0:{
      complexMusicLoop();
      break;
    }
//    case 2:{
//      basicMusicLoopFour();
//      break;
//    }
    case 1:{
      if(numOfColorSnake== 6.0){
        numOfColorSnake=0.0;
      }
      else{
       numOfColorSnake++;
      }
      snakeLoop();
      break;
    }
    case 2:{
      flickerLoop();
      break;
    }
//     case 6:{
//      blueYellowLoop();
//      break;
//    }
  }
}
