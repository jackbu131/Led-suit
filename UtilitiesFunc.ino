// Audio Spectrum Display
// Copyright 2013 Tony DiCola (tony@tonydicola.com)

// This code is part of the guide at http://learn.adafruit.com/fft-fun-with-fourier-transforms/

#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>


////////////////////////////////////////////////////////////////////////////////
// CONIFIGURATION 
// These values can be changed to alter the behavior of the spectrum display.
////////////////////////////////////////////////////////////////////////////////

int SAMPLE_RATE_HZ = 9000;             // Sample rate of the audio in hertz.
float SPECTRUM_MIN_DB = 30.0;          // Audio intensity (in decibels) that maps to low LED brightness.
float SPECTRUM_MAX_DB = 60.0;          // Audio intensity (in decibels) that maps to high LED brightness.
int LEDS_ENABLED = 1;                  // Control if the LED's should display the spectrum or not.  1 is true, 0 is false.  
     
int INTENCITY_LEVEL_UP_PIN = 10;    
int INTENCITY_LEVEL_DOWN_PIN = 11;       
                                       // Useful for turning the LED display on and off with commands from the serial port.
const int FFT_SIZE = 256;              // Size of the FFT.  Realistically can only be at most 256 
                                       // without running out of memory for buffers and other state.
const int AUDIO_INPUT_PIN = 14;        // Input ADC pin for audio data.
const int ANALOG_READ_RESOLUTION = 10; // Bits of resolution for the ADC.
const int ANALOG_READ_AVERAGING = 16;  // Number of samples to average with each ADC reading.
const int POWER_LED_PIN = 13;          // Output pin for power LED (pin 13 to use Teensy 3.0's onboard LED).



const int NEO_PIXEL_PIN3 = 3;
const int NEO_PIXEL_PIN4 = 4;
const int NEO_PIXEL_PIN5 = 5;
const int NEO_PIXEL_PIN6 = 6;
const int NEO_PIXEL_PIN7 = 7;
const int NEO_PIXEL_PIN8 = 8;


const int ColorManagementFakeOin = 100;



const int RH_PIXEL_COUNT = 47;
const int LH_PIXEL_COUNT = 41;
const int RL_PIXEL_COUNT = 70;
const int LL_PIXEL_COUNT = 80;
const int B_PIXEL_COUNT = 74;
const int HE_PIXEL_COUNT = 40;




// Output pin for neo handRight.
const int NUM_OF_WINDOWS = 4;         // Number of neo handRight.  You should be able to increase this without
                                       // any other changes to the program.
const int MAX_CHARS = 65;              // Max size of the input command buffer



////////////////////////////////////////////////////////////////////////////////
// INTERNAL STATE
// These shouldn't be modified unless you know what you're doing.
////////////////////////////////////////////////////////////////////////////////

IntervalTimer samplingTimer;
float samples[FFT_SIZE*2];
float magnitudes[FFT_SIZE];
int sampleCounter = 0;
Adafruit_NeoPixel handRight = Adafruit_NeoPixel(RH_PIXEL_COUNT, NEO_PIXEL_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel handLeft = Adafruit_NeoPixel(LH_PIXEL_COUNT, NEO_PIXEL_PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel legRight = Adafruit_NeoPixel(RL_PIXEL_COUNT, NEO_PIXEL_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel legLeft = Adafruit_NeoPixel(LL_PIXEL_COUNT, NEO_PIXEL_PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel body = Adafruit_NeoPixel(B_PIXEL_COUNT, NEO_PIXEL_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel head = Adafruit_NeoPixel(HE_PIXEL_COUNT, NEO_PIXEL_PIN8, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel colorClass = Adafruit_NeoPixel(1, ColorManagementFakeOin, NEO_GRB + NEO_KHZ800);
char commandBuffer[MAX_CHARS];


void Interrupt() {
  //if((*funcDecoder)>=0 && (*funcDecoder)<=2){
   (*funcDecoder)++;
    delay(300);
    if((*funcDecoder)==7)
    {
      (*funcDecoder) = 0;
      delay(300);
     }
     
    // (*funcDecoder) = 3;
  //}
    
    Serial.println("funcDecoder!!!!!!");
    loop();
}
/*
void Interrupt1() {
  if(numOfColorSnake != 1.0){
    numOfColorSnake = 1.0;
  }
  numOfColorSnake = 2.0;
    delay(300);
    Serial.println("funcDecoder2!!!!!!!!1");

    loop();
}

void Interrupt2() {
  if(funcDecoder!=4)funcDecoder=4;
    //funcDecoder++;
    delay(300);
    Serial.println("funcDecoder3!!!!!");

    delay(10);
    loop();
}
void Interrupt3() {
  if(funcDecoder!=5)funcDecoder=5;
    //funcDecoder++;
    delay(300);
    Serial.println("funcDecoder5!!!!!!");

    delay(10);
    loop();
}
*/
////////////////////////////////////////////////////////////////////////////////
// MAIN SKETCH FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

void utilitySetup() {
  // Set up serial port.
  delay(1000);
  Serial.begin(38400);
  
  pinMode(INTENCITY_LEVEL_UP_PIN,INPUT);
  pinMode(INTENCITY_LEVEL_DOWN_PIN,INPUT);
  pinMode(0,INPUT);
 pinMode(PUSH_BUTTON_PIN4,INPUT);
  attachInterrupt(PUSH_BUTTON_PIN4, Interrupt, RISING);
  
 
 /* pinMode(PUSH_BUTTON_PIN3,INPUT);
  //attachInterrupt(PUSH_BUTTON_PIN3, Interrupt1, RISING);

  pinMode(PUSH_BUTTON_PIN3,INPUT);
  //attachInterrupt(PUSH_BUTTON_PIN3, Interrupt2, RISING);
  pinMode(PUSH_BUTTON_PIN4,INPUT);
 // attachInterrupt(PUSH_BUTTON_PIN4, Interrupt3, RISING);
 */
  
  
  
  // Set up ADC and audio input.
  pinMode(AUDIO_INPUT_PIN, INPUT);
  analogReadResolution(ANALOG_READ_RESOLUTION);
  analogReadAveraging(ANALOG_READ_AVERAGING);
  
  // Turn on the power indicator LED.
  pinMode(POWER_LED_PIN, OUTPUT);
  digitalWrite(POWER_LED_PIN, HIGH);
  
  
  // Initialize neo pixel library and turn off the LEDs
  handRight.begin();
  handRight.show(); 
  handLeft.begin();
  handLeft.show(); 
   legRight.begin();
 legRight.show(); 
  legLeft.begin();
  legLeft.show();
    head.begin();
 head.show(); 
  body.begin();
  body.show(); 
  
  
  // Clear the input command buffer
  memset(commandBuffer, 0, sizeof(commandBuffer));
  
  // Initialize spectrum display

  spectrumSetup();
  complexSpectrumSetup();
  fourSpectrumSetup();
  // Begin sampling audio
  samplingBegin();
}



////////////////////////////////////////////////////////////////////////////////
// UTILITY FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// Compute the average magnitude of a target frequency window vs. all other frequencies.
void windowMean(float* magnitudes, int lowBin, int highBin, float* windowMean, float* otherMean) {
    *windowMean = 0;
    *otherMean = 0;
    // Notice the first magnitude bin is skipped because it represents the
    // average power of the signal.
    for (int i = 1; i < FFT_SIZE/2; ++i) {
      if (i >= lowBin && i <= highBin) {
        *windowMean += magnitudes[i];
      }
      else {
        *otherMean += magnitudes[i];
      }
    }
    *windowMean /= (highBin - lowBin) + 1;
    *otherMean /= (FFT_SIZE / 2 - (highBin - lowBin));
}

// Convert a frequency to the appropriate FFT bin it will fall within.
int frequencyToBin(float frequency) {
  float binFrequency = float(SAMPLE_RATE_HZ) / float(FFT_SIZE);
  return int(frequency / binFrequency);
}

// Convert from HSV values (in floating point 0 to 1.0) to RGB colors usable
// by neo pixel functions.

uint32_t pixelHSVtoRGBColor(float hue, float saturation, float value, int colorModifier) {
  // Implemented from algorithm at http://en.wikipedia.org/wiki/HSL_and_HSV#From_HSV
  float chroma = value * saturation;
  float h1 = float(hue)/colorModifier;
  float x = chroma*(1.0-fabs(fmod(h1, 2.0)-1.0));
  float r = 0;
  float g = 0;
  float b = 0;
  if (h1 < 1.0) {
    r = chroma;
    //Serial.print(r,6);
    g = x;
    //Serial.println(" "+(String)g);
  }
  else if (h1 < 2.0) {
    r = x;
    g = chroma;
  }
  else if (h1 < 3.0) {
    g = chroma;
    b = x;
  }
  else if (h1 < 4.0) {
    g = x;
    b = chroma;
  }
  else if (h1 < 5.0) {
    r = x;
    b = chroma;
  }
  else if (h1 < 6.0) {
    //Serial.println("yossi");
    r = chroma;
    b = x;
  }

  float m = (value - chroma);
  //char logic='y';
  //int counter=101;
  //Serial.println(m,10);
  r += m;
  g += m;
  b += m;
  /*Serial.print(255*r,6);
  Serial.print(" ");
  Serial.print(255*g,6);
  Serial.print(" ");
  Serial.println(255*b,6);*/
  return colorClass.Color(int(255*r), int(255*g), int(255*b));
}


////////////////////////////////////////////////////////////////////////////////
// SAMPLING FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

void samplingCallback() {
  // Read from the ADC and store the sample data
  samples[sampleCounter] = (float32_t)analogRead(AUDIO_INPUT_PIN);
  // Complex FFT functions require a coefficient for the imaginary part of the input.
  // Since we only have real data, set this coefficient to zero.
  samples[sampleCounter+1] = 0.0;
  // Update sample buffer position and stop after the buffer is filled
  sampleCounter += 2;
  if (sampleCounter >= FFT_SIZE*2) {
    samplingTimer.end();
  }
}

void samplingBegin() {
  // Reset sample buffer position and start callback at necessary rate.
  sampleCounter = 0;
  samplingTimer.begin(samplingCallback, 1000000/SAMPLE_RATE_HZ);
}

boolean samplingIsDone() {
  return sampleCounter >= FFT_SIZE*2;
}



