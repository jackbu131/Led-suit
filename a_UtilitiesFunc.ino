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
const int NEO_PIXEL_PIN9 = 8;

const int ColorManagementFakeOin = 100;

const int RH_PIXEL_COUNT = 47;
const int LH_PIXEL_COUNT = 41;
const int RL_PIXEL_COUNT = 70;
const int LL_PIXEL_COUNT = 80;
const int B_PIXEL_COUNT = 74;
const int HE_PIXEL_COUNT = 40;

const int MAX_NUM_OF_LEDS = 70;


const int MAX_CHARS = 65;              // Max size of the input command buffer


////////////////////////////////////////////////////////////////////////////////
// INTERNAL STATE
// These shouldn't be modified unless you know what you're doing.
////////////////////////////////////////////////////////////////////////////////

Adafruit_NeoPixel right_front_center = Adafruit_NeoPixel(RH_PIXEL_COUNT, NEO_PIXEL_PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel right_front_right = Adafruit_NeoPixel(LH_PIXEL_COUNT, NEO_PIXEL_PIN7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel left_front_center = Adafruit_NeoPixel(RL_PIXEL_COUNT, NEO_PIXEL_PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel left_front_left = Adafruit_NeoPixel(LL_PIXEL_COUNT, NEO_PIXEL_PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel back_center = Adafruit_NeoPixel(B_PIXEL_COUNT, NEO_PIXEL_PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel back_left = Adafruit_NeoPixel(HE_PIXEL_COUNT, NEO_PIXEL_PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel back_right = Adafruit_NeoPixel(HE_PIXEL_COUNT, NEO_PIXEL_PIN9, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel colorClass = Adafruit_NeoPixel(1, ColorManagementFakeOin, NEO_GRB + NEO_KHZ800);
char commandBuffer[MAX_CHARS];

volatile unsigned long last_micros;

void Interrupt() {
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    (*funcDecoder)++
    (*funcDecoder) = (*funcDecoder) % 6
    last_micros = micros();
  }
    loop();
}

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
//     attachInterrupt(PUSH_BUTTON_PIN4, Interrupt, RISING);

    // Set up ADC and audio input.
    pinMode(AUDIO_INPUT_PIN, INPUT);
    analogReadResolution(ANALOG_READ_RESOLUTION);
    analogReadAveraging(ANALOG_READ_AVERAGING);

    // Turn on the power indicator LED.
    pinMode(POWER_LED_PIN, OUTPUT);
    digitalWrite(POWER_LED_PIN, HIGH);
  
  
  // Initialize neo pixel library and turn off the LEDs
    setup_one_strip(right_front_center)
    setup_one_strip(right_front_right)
    setup_one_strip(left_front_center)
    setup_one_strip(left_front_left)
    setup_one_strip(back_center)
    setup_one_strip(back_left)
    setup_one_strip(back_right)

    // Clear the input command buffer
    memset(commandBuffer, 0, sizeof(commandBuffer));

    // Initialize spectrum display

    spectrumSetup();
    complexSpectrumSetup();
    fourSpectrumSetup();
    // Begin sampling audio
    samplingBegin();
}


void setup_one_strip(Adafruit_NeoPixel strip, int b){
    strip.begin();
    strip.setBrightness(b);
    strip.clear();
    strip.show();
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
IntervalTimer samplingTimer;
float samples[FFT_SIZE*2];
float magnitudes[FFT_SIZE];
int sampleCounter = 0;

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


void show_all(){
    right_front_center.show();
    right_front_right.show();
    left_front_center.show();
    left_front_left.show();
    back_center.show();
    back_left.show();
    back_right.show();
}

void set_color_all_strips(int index, uint32_t rgb){
    right_front_center.setPixelColor(index, rgb);
    right_front_right.setPixelColor(index, rgb);
    left_front_center.setPixelColor(index, rgb);
    left_front_left.setPixelColor(index, rgb);
    back_center.setPixelColor(index, rgb);
    back_left.setPixelColor(index, rgb);
    back_right.setPixelColor(index, rgb);
}

void clear_all(){
    right_front_center.clear();
    right_front_right.clear();
    left_front_center.clear();
    left_front_left.clear();
    back_center.clear();
    back_left.clear();
    back_right.clear();
}


