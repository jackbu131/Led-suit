
/*
 * Black = 0.0
 * White = 1.0
 * Red = 2.0;
 * DeepPink = 2.1;
 * HotPink = 2.2;
 * Light pink = 2.3;
 * purple = 3.0
 * blue = 4.0
 * green = 5.0
 * yellow = 6.0
 * purple2 = 7.0
 * Gold = 8.0
 * 
 * 
 *//*
void setColorFunc(double* numOfColor , int* RED ,int* GREEN, int* BLUE){

   if(*numOfColor == 0.0){
      *RED = 0x00;
      *GREEN = 0x00;
      *BLUE = 0x00;
  }
  else if(*numOfColor == 1.0){
      *RED = 0xFF/(random(0,100));
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF;
  }
  
  else if(*numOfColor == 2.0){
      *RED = 0xFF;
      *GREEN = 0x00;
      *BLUE = 0x00;
  }
  else if(*numOfColor == 2.1){
      *RED = 0xFF;
      *GREEN = 0x14;
      *BLUE = 0x93;
  }
  else if(*numOfColor == 2.2){
      *RED = 0xFF;
      *GREEN = 0x69;
      *BLUE = 0xB4;
  }
   else if(*numOfColor == 2.3){
      *RED = 0xFF;
      *GREEN = 0xB6;
      *BLUE = 0xC1;
  }
  else if(*numOfColor == 3.0){
      *RED = 0x8B;
      *GREEN = 0x00;
      *BLUE = 0x8B;
  }
   else if(*numOfColor == 4.0){
      *RED = 0x00;
      *GREEN = 0x00;
      *BLUE = 0xEE;
  }
   else if(*numOfColor == 5.0){
      *RED = 0x00;
      *GREEN = 0xEE;
      *BLUE = 0x00;
  }
   else if(*numOfColor == 6.0){
      *RED = 0xEE;
      *GREEN = 0xEE;
      *BLUE = 0x00;
  }
   else if(*numOfColor == 7.0){
      *RED = 0x9B;
      *GREEN = 0x30;
      *BLUE = 0xEE;
  }
  else if(*numOfColor == 8.0){
      *RED = 0xEE;
      *GREEN = 0xD7;
      *BLUE = 0x00;
  }
 
}
*/
void setColorFunc(double* numOfColor , int* RED ,int* GREEN, int* BLUE){

   if(*numOfColor == 0.0){
      *RED = 0xFF;
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF/(random(0,100));
  }
  else if(*numOfColor == 1.0){
      *RED = 0xFF/(random(0,100));
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF;
  }
  
  else if(*numOfColor == 2.0){
      *RED = 0xFF/(random(0,100));
      *GREEN = 0xFF;
      *BLUE = 0xFF/(random(0,100));
  }
  else if(*numOfColor == 3){
      *RED = 0xFF/(random(0,100));
      *GREEN = 0xFF;
      *BLUE = 0xFF;
  }
  else if(*numOfColor == 4){
     *RED = 0xFF/(random(0,100));
     Serial.println(random(0,100));
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF;
  }
   else if(*numOfColor == 5){
      *RED = 0xFF;
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF;
  }
  else if(*numOfColor == 6){
      *RED = 0xFF;
      *GREEN = 0xFF;
      *BLUE = 0xFF/(random(0,100));
  }
 /*
   else if(*numOfColor == 7){
      *RED = 0xFF/(random(0,100));
      *GREEN = 0xFF/(random(0,100));
      *BLUE = 0xFF/(random(0,100));
  }
   else if(*numOfColor == 5.0){
      *RED = 0x00;
      *GREEN = 0xEE;
      *BLUE = 0x00;
  }
   else if(*numOfColor == 6.0){
      *RED = 0xEE;
      *GREEN = 0xEE;
      *BLUE = 0x00;
  }
   else if(*numOfColor == 7.0){
      *RED = 0x9B;
      *GREEN = 0x30;
      *BLUE = 0xEE;
  }
  else if(*numOfColor == 8.0){
      *RED = 0xEE;
      *GREEN = 0xD7;
      *BLUE = 0x00;
  }*/
 
}

