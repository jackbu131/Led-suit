#define ARM_MATH_CM4
#include <arm_math.h>
#include <Adafruit_NeoPixel.h>


////////////////////////////////////////////////////////////////////////////////
// MAIN SKETCH FUNCTIONS
////////////////////////////////////////////////////////////////////////////////


void complexMusicLoop() {
  // Calculate FFT if a full sample is available.
  if (samplingIsDone()) {
    // Run FFT on sample data.
    arm_cfft_radix4_instance_f32 fft_inst;
    arm_cfft_radix4_init_f32(&fft_inst, FFT_SIZE, 0, 1);
    arm_cfft_radix4_f32(&fft_inst, samples);
    // Calculate magnitude of complex numbers output by the FFT.
    arm_cmplx_mag_f32(samples, magnitudes, FFT_SIZE);
  
    if (LEDS_ENABLED == 1){
      complexSpectrumLoop();
    }
  
    // Restart audio sampling.
    samplingBegin();
  }
}


////////////////////////////////////////////////////////////////////////////////
// SPECTRUM DISPLAY FUNCTIONS
///////////////////////////////////////////////////////////////////////////////

void complexSpectrumSetup() {
  
  // Set the frequency window values by evenly dividing the possible frequency
  // spectrum across the number of neo handRight.
  float windowSize = (SAMPLE_RATE_HZ / 2.0) / float(NUM_OF_WINDOWS_FOR_COMPLEX);
  for (int i = 0; i < NUM_OF_WINDOWS_FOR_COMPLEX+1; ++i) {
    frequencyWindowForComplex[i] = i*windowSize;
  }
  // Evenly spread huesForComplex across all handRight.
  delay(100);
  for (int i = 0; i < NUM_OF_WINDOWS_FOR_COMPLEX; ++i) {
    huesForComplex[i] = 360.0*(float(i)/float(NUM_OF_WINDOWS_FOR_COMPLEX-1));
  }
}


void complexSpectrumLoop() {
// Update each LED based on the intensity of the audio
// in the associated frequency window.
    float intensity = 0;
    float otherMean = 0;
    for (int i = 0, j = NUM_OF_WINDOWS_FOR_COMPLEX; i < NUM_OF_WINDOWS_FOR_COMPLEX; ++i, --j) {
        intensity = getIntensity(i, otherMean, intensity);
        uint32_t rgb = pixelHSVtoRGBColor(huesForComplex[i], 1.0, intensity, COMPLEX_COLOR_MODIFIER);
        set_color_all_strips(j, rgb);
//        Serial.println(rgb);
    }
    show_all();
//    delay(100);
}


float getIntensity(int i, float otherMean, float intensity){
    windowMean(
        magnitudes,
        frequencyToBin(frequencyWindowForComplex[i]),
        frequencyToBin(frequencyWindowForComplex[i+1]),
        &intensity,
        &otherMean
    );
    // Convert intensity to decibels.
    intensity = 20.0*log10(intensity);
    // Scale the intensity and clamp between 0 and 1.0.
    intensity -= SPECTRUM_MIN_DB;
    intensity = intensity < 0.0 ? 0.0 : intensity;
    intensity /= (SPECTRUM_MAX_DB-SPECTRUM_MIN_DB);
    intensity = intensity > 1.0 ? 1.0 : intensity;
    return intensity;
}
