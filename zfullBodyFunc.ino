//#define ARM_MATH_CM4
//#include <arm_math.h>
//#include <Adafruit_NeoPixel.h>
//
//
//int RED = 0;
//int GREEN = 0;
//int BLUE = 0;
//double numOfColor = 2.0; // default color
//int bodyDelay = 1000; // delay time between colors
// 
//
//
//
//
//void fullBodyLoop() {
//  
//
//  
//
//    for (int j=0; j<RL_PIXEL_COUNT; j++){
//      numOfColor = 2.0;
//      setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//      
//          legRight.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//          legLeft.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//          
//          
//    }
//          legRight.show();
//          legLeft.show();
//          delay(bodyDelay);
//   
//           
//  
//      for (int j=0; j<B_PIXEL_COUNT; j++){
//          numOfColor = 2.1;
//          setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//          body.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//   
//          }
//          
//          body.show();
//          delay(bodyDelay); 
//
//          
//      for (int j=0; j<LH_PIXEL_COUNT; j++){
//         numOfColor = 2.2;
//         setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//     
//         handLeft.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//         handRight.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//      }
//      handRight.show();
//      handLeft.show();
//      delay(bodyDelay); 
//   
//         
//      for (int j=0; j<HE_PIXEL_COUNT; j++){
//         numOfColor = 2.3;
//         setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//         head.setPixelColor(j, colorClass.Color(RED,GREEN,BLUE));
//          }
//          head.show();
//          delay(bodyDelay);
//
//       for (int j=0; j<HE_PIXEL_COUNT; j++){
//         //numOfColor = 0;
//         setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//         head.setPixelColor(j, colorClass.Color(RED,GREEN,BLUE));
//          }
//          head.show();
//          delay(bodyDelay);
//
//        for (int j=0; j<LH_PIXEL_COUNT; j++){
//         numOfColor = 0;
//         setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//     
//         handLeft.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//         handRight.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//      }
//      handRight.show();
//      handLeft.show();
//      delay(bodyDelay); 
//  
//      for (int j=0; j<B_PIXEL_COUNT; j++){
//          numOfColor = 0;
//          setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//          body.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//   
//          }
//          
//          body.show();
//          delay(bodyDelay);         
//   for (int j=0; j<RL_PIXEL_COUNT; j++){
//      numOfColor = 0;
//      setColorFunc(&numOfColor, &RED , &GREEN , &BLUE);
//      
//          legRight.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//          legLeft.setPixelColor(j,colorClass.Color(RED,GREEN,BLUE));
//          
//          
//    }
//          legRight.show();
//          legLeft.show();
//          delay(bodyDelay);  
//}
