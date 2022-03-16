//#define ARM_MATH_CM4
//#include <arm_math.h>
//#include <Adafruit_NeoPixel.h>
//
//
//////////////////////////////////////////////////////////////////////////////////
//// MAIN SKETCH FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////
//
//
//void basicMusicLoopFour() {
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
//      fourSpectrumLoop();
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
//void fourSpectrumSetup() {
//  
//  // Set the frequency window values by evenly dividing the possible frequency
//  // spectrum across the number of neo handRight.
//  float windowSize = (SAMPLE_RATE_HZ / 2.0) / float(NUM_OF_WINDOWS_FOR_BASIC_FOUR);
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC_FOUR+1; ++i) {
//    frequencyWindowForBasicFour[i] = i*windowSize;
//  }
//  // Evenly spread huesForBasicFour across all handRight.
//  delay(100);
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC_FOUR; ++i) {
//    huesForBasicFour[i] = 360.0*(float(i)/float(NUM_OF_WINDOWS_FOR_BASIC_FOUR-1));
//    //Serial.println((String)huesForBasicFour[i]);
//  }
//}
//
//void fourSpectrumLoop() {
//  // Update each LED based on the intensity of the audio 
//  // in the associated frequency window.
//  float intensity, otherMean;
//  for (int i = 0; i < NUM_OF_WINDOWS_FOR_BASIC_FOUR; ++i) {
//    //int k=0;
//    //if(i<4){k=0;}else if(i<8){k=6;} else if (i<12){k=11;}else {k=15;}
//    windowMean(magnitudes, 
//               frequencyToBin(frequencyWindowForBasicFour[i]),
//               frequencyToBin(frequencyWindowForBasicFour[i+1]),
//               &intensity,
//               &otherMean);
//    // Convert intensity to decibels.
//    intensity = 20.0*log10(intensity);
//    // Scale the intensity and clamp between 0 and 1.0.
//    intensity -= SPECTRUM_MIN_DB;
//    intensity = intensity < 0.0 ? 0.0 : intensity;
//    intensity /= (SPECTRUM_MAX_DB-SPECTRUM_MIN_DB);
//    intensity = intensity > 1.0 ? 1.0 : intensity;
//    switch (i){
//      case 0: {for (int j=0; j<RL_PIXEL_COUNT; j++){
//      
//          legRight.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/10, COLOR_MODIFIER));
//   
//          } 
//          {for (int j=0; j<LL_PIXEL_COUNT; j++){
//      
//          legLeft.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/10,COLOR_MODIFIER));
//   
//          }break;}
//      case 1: {for (int j=0; j<B_PIXEL_COUNT; j++){
//      
//          body.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/10,COLOR_MODIFIER));
//    
//          } break;}
//      case 2: {for (int j=0; j<LH_PIXEL_COUNT; j++){
//        handLeft.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/10,COLOR_MODIFIER));
//   
//          } 
//          for (int j=0; j<RH_PIXEL_COUNT; j++){
//        handRight.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/1,COLOR_MODIFIER));
//
//          }break;}
//      case 3: {for (int j=0; j<HE_PIXEL_COUNT; j++){
//         head.setPixelColor(j, pixelHSVtoRGBColor(huesForBasicFour[i], 1.0, intensity/1,COLOR_MODIFIER));
// 
//          } break;}
//    }
//    
//
//  } 
//	
//}
//handRight.show();
//  handLeft.show();
//  legRight.show();
//  legLeft.show();
//  body.show();
//  head.show();
//  
//}
//
//
//
