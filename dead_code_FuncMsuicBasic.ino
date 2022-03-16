//#define ARM_MATH_CM4
//#include <arm_math.h>
//#include <Adafruit_NeoPixel.h>
//
//
//const int NUM_OF_WINDOWS_FOR_BASIC = 20;  
//const int BASIC_COLOR_MODIFER = 60;
//float frequencyWindowForBasic[NUM_OF_WINDOWS_FOR_BASIC+1];
//float huesForBasic[NUM_OF_WINDOWS_FOR_BASIC];
//
//const int NUMB_OF_WINDOW_PER_PART = 5;
//
//
//////////////////////////////////////////////////////////////////////////////////
//// MAIN SKETCH FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////
//
//
//void basicMusicLoop() {
//
//  // Calculate FFT if a full sample is available.
//  
//  if (samplingIsDone()) {
//    // Run FFT on sample data.
//    arm_cfft_radix4_instance_f32 fft_inst;
//    arm_cfft_radix4_init_f32(&fft_inst, FFT_SIZE, 0, 1);
//    arm_cfft_radix4_f32(&fft_inst, samples);
//    // Calculate magnitude of complex numbers output by the FFT.
//    arm_cmplx_mag_f32(samples, magnitudes, FFT_SIZE);
//  
//    if (LEDS_ENABLED == 1)
//    {
//      
//      spectrumLoop();
//    }
//  
//    // Restart audio sampling.
//    samplingBegin();
//  }
//    
//  // Parse any pending commands.
// //parserLoop();
// delay(10);
//}
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////
//// SPECTRUM DISPLAY FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////
//
//void spectrumSetup() {
//  
//  // Set the frequency window values by evenly dividing the possible frequency
//  // spectrum across the number of neo handRight.
//  float windowSize = (SAMPLE_RATE_HZ / 2.0) / float(NUM_OF_WINDOWS_FOR_BASIC);
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC+1; ++i) {
//    frequencyWindowForBasic[i] = i*windowSize;
//  }
//  // Evenly spread huesForBasic across all handRight.
//  delay(100);
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC; ++i) {
//    huesForBasic[i] = 360.0*(float(i)/float(NUM_OF_WINDOWS_FOR_BASIC-1));
//    //Serial.println((String)huesForBasic[i]);
//  }
//}
//
//void spectrumLoop() {
//
//  float intensity, otherMean;
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC; ++i) {
//
//    windowMean(magnitudes, 
//               frequencyToBin(frequencyWindowForBasic[i]),
//               frequencyToBin(frequencyWindowForBasic[i+1]),
//               &intensity,
//               &otherMean);
//    // Convert intensity to decibels.
//    intensity = 20.0*log10(intensity);
//    // Scale the intensity and clamp between 0 and 1.0.
//    intensity -= SPECTRUM_MIN_DB;
//    intensity = intensity < 0.0 ? 0.0 : intensity;
//    intensity /= (SPECTRUM_MAX_DB-SPECTRUM_MIN_DB);
//    intensity = intensity > 1.0 ? 1.0 : intensity;
//   if (i>=0&&i<5){
//
//    
//      for (int j=i*RL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<RL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+i*RL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//      
//          legRight.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
//   
//       }
//       for (int j=i*LL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<LL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+i*LL_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//      
//          legLeft.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
//   
//          }
//   }  else if(i>=5&&i<10) {
//        
//        for (int j=(i-5)*B_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<B_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+(i-5)*B_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//      
//          body.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
//    
//          } 
//   } else if(i>=10&&i<15) {
//    
//      for (int j=(i-10)*LH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<LH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+(i-10)*LH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//        handLeft.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
//   
//          } 
//          for (int j=(i-10)*RH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<RH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+(i-10)*RH_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//        handRight.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
//
//          }
//  } else if(i>=15&&i<20) {
//      
//      for (int j=(i-15)*HE_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j<HE_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART+(i-15)*HE_PIXEL_COUNT/NUMB_OF_WINDOW_PER_PART; j++){
//         head.setPixelColor(j, pixelHSVtoRGBColor(huesForBasic[i], 1.0, intensity/10, BASIC_COLOR_MODIFER));
// 
//          }
//          }
//    }
//    
//
//  
//	handRight.show();
//	handLeft.show();
//	legRight.show();
//	legLeft.show();
//	body.show();
//	head.show();
//  
//}
//
//
//
//
