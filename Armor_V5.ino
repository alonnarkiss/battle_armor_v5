#include <time.h>       /* time */
//TODO
//1. animation when stating the armor                 V
//2. blue / pink coolor when bluetooth conacting      V
//3. change time in the counter from bluetooth user. 
//4. make fack in when play in response time          V
//5.

/*
 * bluetooth
 * rx -> tx
 * tx -> rx
 */
 
// buzzer
#define buzzer  13


//     ARGB
#include <FastLED.h>
#define LED_PIN     6 // argb pin in arduino
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];


//   pressure plat 
#define POWER_PIN 3
#define POWER_PIN2 4
// const
int counter = 0;



void setup() {
  randomSeed(analogRead(0)); //nitializes the pseudo-random number generator,
  Serial.begin(9600);
  pinMode(POWER_PIN, INPUT);
  pinMode(POWER_PIN2, INPUT);
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 
  pinMode(buzzer, OUTPUT); // Set buzzer
}

void loop() {
  
  light_color(25 ,0 , 25); //purple
    if(Serial.available()>0)
   {     
      
      char data= Serial.read(); // reading the data received from the bluetooth module
//      Serial.println(data);
      switch(data)
      {
        case 'a': {// when a is pressed on the app on your smart phone "speed mode"
                  responsetime();
                  break; 
        }
        case 'b':{// when b is pressed on the app on your smart phone "speed mode"
                  lighton_blue();
                  break; 
        }
        case 'c':{// when c is pressed "counter mode "
                  countermode();
                  break; 
        }
        case 'd':{
          battlemode();
          break;
        }

        case 'e':{
           Serial.println("what delta time do you want? 0.1 is the recommended.");
           delay(1000);
           String delta_cyclone;
            while(!Serial.available())
             { 
              delay(100);
             }
            while(Serial.available())
             {   
                char delta_1= Serial.read(); // reading the data received from the bluetooth module
                delta_cyclone = delta_cyclone + delta_1; //+= delta_1
            //Serial.println(delta_cyclone);       
             }
             float delta1= delta_cyclone.toFloat();
             Serial.println(delta1);
             cyclone(delta1);
             break;
          
        }

        case 'f':{
          responsetime_sound();
          break;
        }
        case 'g':{
          cyclone(0.1);
          break;
        }
        case 'h':{
//          String delta_combo = "";
//          while(Serial.available()>0)
//             {   
//              Serial.println(Serial.read());
//              if(Serial.read() == "," )
//                break;
//                char delta_1= Serial.read(); // reading the data received from the bluetooth module
//                delta_combo = delta_combo + delta_1; //+= delta_1
//                
//             }
//            int level = (delta_combo.toInt()); //from char to int
//          Serial.print("beginne from level : ");
//          Serial.println(level);
//          delta_combo = "";
//          while(Serial.available())
//             {   
//              Serial.println(Serial.read());
//                char delta_1= Serial.read(); // reading the data received from the bluetooth module
//                delta_combo = delta_combo + delta_1; //+= delta_1
//             }
//             float delta1= delta_combo.toFloat();
//             Serial.print("with delta time : ");
//            Serial.println(delta1);
//          combo_mode(level,delta1); // combo_mode(level,delta_time); int , float
          combo_mode(1,5); // combo_mode(level,delta_time); int , float
          break;
        }
        case 'i':{
          combo_easy();
          break;
        }
        case 'j':{
          combo_gorila();
          break;
        }
        
        case 'z':{
          lightoff();
        }
        //default : break;
      }
//      Serial.println(data);
   }
   delay(50);

}



//-----------------------------------------------------------------------------------------------------------------------------------

void lightoff(){
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(100);  
   }
}


//----------------------------------------------lightoff fast-------------------------------------------------------------------------------------

void lightoff_fast(){
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(10);  
   }
}
//-----------------------------------------choose color to light--------------------------------------------------------------------------

void light_color(int red ,int green , int blue){
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(red, green,blue);
    FastLED.show();
    delay(100);  
   }
}

//-----------------------------------------choose color to light--------------------------------------------------------------------------

void light_color_faster(int red ,int green , int blue){
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(red, green,blue);
    FastLED.show();
    delay(20);  
   }
}
//-----------------------------------------animation for start--------------------------------------------------------------------------
void lighton_animation(){
  for(int i=0; i<NUM_LEDS; i++){ //green led is of
      lighton_right();
      delay(80);
      lighton_left();
      delay(80);
      lightoff_fast();
   }
   lighton();
   delay(500);
   lightoff();
}
//-----------------------------light for combo mode  right-----------------------------------------------------------------------------------------------

void lighton_right(){
  int green = 45;
  int red   = 45;
  int blue  = 0;
  
   for(int i=0; i<3; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    //delay(100);  
   }
}

//-----------------------------light for combo mode  left-----------------------------------------------------------------------------------------------

void lighton_left(){
  int green = 45;
  int red   = 0;
  int blue  = 45;
  
   for(int i=NUM_LEDS; i>6; i--){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    //delay(100);  
   }
}

//-----------------------------light green on-----------------------------------------------------------------------------------------------

void lighton(){
  int green = 45;
  int red   = 0;
  int blue  = 0;
  
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    //delay(100);  
   }
}

//-----------------------------light green on  middle-----------------------------------------------------------------------------------------------

void lighton_middle(){
  int green = 45;
  int red   = 0;
  int blue  = 0;
  
   for(int i=4; i<7; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    delay(10);  
   }
}

//-----------------------------light off  middle-----------------------------------------------------------------------------------------------

void lightoff_middle(){
  int green = 0;
  int red   = 0;
  int blue  = 0;
  
   for(int i=4; i<7; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    delay(10);  
   }
}
//-----------------------------------------animation for battle------------------------------------------------------------------------------------
void battle_animation(){
  int green = 0;
  int red   = 45;
  int blue  = 0; // not in use here but it global value so i need to  0 it
  
  for(int x = 0 ; x<3 ; x++){
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    delay(100);  
   }
   if(x == 0)
   green = 40;
   else if (x == 1)
  red = 0;
  }
  
}
//------------------------------------------Blue-----------------------------------------------------------------------------------

void lighton_blue(){
  int green = 0;
  int red   = 0;
  int blue  = 45;
  
   for(int i=0; i<NUM_LEDS; i++){ //green led is of
    leds[i] = CRGB(red, green, blue);
    FastLED.show();
    delay(10);  
   }
}


//--------------------------------responsetime from light------------------------------------------------------------------------------------

void responsetime(){
  Serial.println("kick fast as you can!!");
  for(int i=0; i<NUM_LEDS; i++){ //green led is on
  leds[i] = CRGB(0, 45, 0);
  FastLED.show();
    
 }
  float currentMillis = millis(); 
  while(digitalRead(POWER_PIN) == LOW ){
    continue;
    
  }
  float endMillis = millis();// start time
  lightoff();
 
  float delta = (endMillis - currentMillis)/1000; //giving the response time
  
  Serial.print("your time is :");// the app geting data from serial.print (maybe need to delet these line)
  Serial.println(delta);
}


//--------------------------------responsetime from sound------------------------------------------------------------------------------------

void responsetime_sound(){
  Serial.println("kick fast as you can!!");
  tone(buzzer, 3000);
  float currentMillis = millis(); 
  while(digitalRead(POWER_PIN) == LOW ){
    continue;
    
  }
  float endMillis = millis();// start time
  
 noTone(buzzer);     // Stop sound...
  float delta = (endMillis - currentMillis)/1000; //giving the response time
  
  Serial.print("your time is :");// the app geting data from serial.print (maybe need to delet these line)
  Serial.println(delta);
}
//-------------------------counter mode-----------------------------------------------------------------------------------------------

void countermode(){
    //animation();
    Serial.println("counter mode is on!!!");
    lighton();
    int counter_hit =0;
    float currentMillis = millis();
    while((millis()-currentMillis)/1000 <30){// <<<<<< 30 need to change to const
    if(digitalRead(POWER_PIN) == HIGH){
      counter_hit++;
      Serial.println(counter_hit);
      delay(150); // delay here will slow the sampling of hits
      }
                            // arbitrary delay to limit data to serial port 
    }
    Serial.print("The number of hit is :");
    Serial.println(counter_hit);
    lightoff();
}


//-----------------------------------------------------------------------------------------------------------------------------------


void battlemode(){
    
    int counter = 0;
//    char color = 'g' ;
    int green = 45;
    int red   = 45;
    float start_comb = 0; // random number >3
     battle_animation(); //animation the led  red yellow gren
    Serial.println("Battle mode is on!!");
    for(int i = 0 ; i<3 ; i++){
      int life=10 ; //number of led ON : "life"
    while(life>=0){
      while(digitalRead(POWER_PIN) == LOW){
        delay(10);
      }
      leds[life] = CRGB(red, green, 0);
      FastLED.show();
      life--;
      if((millis()-start_comb)/1000 < 3){
        leds[life] = CRGB(red, green, 0);
      FastLED.show();
      life--;
      }
      start_comb =millis();
      
      delay(150);
    }
    delay(10);    // arbitrary delay to limit data to serial port 
      if(green == 45)
      green = 0 ;
      else
      red = 0;
    }
  
}

void cyclone(float delta_c){ // move green dot in the row , the purpose is to punch when the red touch the green 
  //add random
  lightoff();
  int point = 5; //red dot location
  int green =45 ; //
  bool game = true; // stop the game when you success
  //float delta_cyclone = 0;
 
  
  leds[point] = CRGB(45, 0, 0);
      FastLED.show();
  while(Serial.read()!= 'z'){ // stop from bluetooth
    
    for(int i=0; i<NUM_LEDS; i++){
      leds[i-1] = CRGB(0, 0, 0); // delet the previous stat
      leds[point] = CRGB(45, 0, 0); // light the red
      leds[i] = CRGB(0, green, 0);// light the green in the new location
      FastLED.show();
      float currentMillis = millis();
      while((millis()-currentMillis)/1000 <delta_c){ //delta time  between each move
        if(digitalRead(POWER_PIN) == HIGH){ // if punch the sensor
          if(i==point){ // if win
            lighton();
            delay(1000);
            lightoff();
            Serial.print("good mannnn");
            return;
          }
          else{ // if lose
            light_color(45,0,0);
            Serial.print("pice of shit! try again!");
            delay(1000);
            lightoff();
            delay(1000);
            break;
          }
          
        }
      }
      leds[i] = CRGB(0, 0, 0);
      }
    }
  lightoff();
}


void combo_mode(int level ,float delta_time){
  int hitit = 0; //hit point
//  int level = 1; //start level
//  float delta_time = 5.0;
  lightoff();
  lighton_animation();
  delay(500);//delay after light of (more smooth game)
  while(Serial.read()!= 'z'){  // if you want to get aou use z
    int arryOfCombo[level]; // make array of number
    for(int i =0 ; i < level ; i ++){ //this loop make the sequence of the right left 
        arryOfCombo[i] = random(1,3); //generate the sequence numer 1 or 2
        
        if(arryOfCombo[i] == 1){ //right light
          lighton_right();
          tone(buzzer, 5000);
          delay(200);
          noTone(buzzer);
          delay(300);
          lightoff();
      }
      else{ //left light
        lighton_left();
        tone(buzzer, 2000);
        delay(200);
        noTone(buzzer);
        delay(300);
        lightoff();
      }
    }
    
    
    // probably can use the hitit and i for the sam one...
    hitit = 0;
    int i = 0;
    Serial.print("arry : "); 
    for(int i =0 ; i < level ; i ++){ //print the array
      Serial.print(arryOfCombo[i]);
      Serial.print(",");
    }
    Serial.println(" .");
    
    light_color_faster(25 ,25 , 25); //white color

    
    float currentMillis = millis();
    while(hitit < level ){
      
      if(digitalRead(POWER_PIN) == HIGH){ // if the right sensor is on
            if(arryOfCombo[i] ==1){ // if the right sensor is on and its should be
              hitit ++;
              Serial.println("good hit!");
              lighton();
              delay(200);
              lightoff_fast();
              i++;
              currentMillis = millis(); // initial the time for delta
            }
            else{
              level = 0;
              light_color(25 ,0 , 0);
              Serial.println("Looosssseeerrrrrr");
            }
      }
      if(digitalRead(POWER_PIN2) == HIGH){ // if the left sensor is on and its should be
            if(arryOfCombo[i] ==2){
              hitit ++;
              Serial.println("good hit!");
              lighton();
              delay(200);
              lightoff_fast();
              i++;
              currentMillis = millis(); // initial the time for delta
            }
            else{
              level = 0;
              Serial.println("Looosssseeerrrrrr");
              light_color(25 ,0 , 0);
            }
      }
      if((millis()-currentMillis)/1000 >delta_time){
        Serial.println((millis()-currentMillis)/1000);
        Serial.println(delta_time);
        level = 0;
        Serial.println("time up");
        light_color(25 ,0 , 0);
      }
        
      
    }
    level++;
    light_color(25 ,25 , 0); //green for finsih the level
    light_color(0 ,25 , 0); //green for finsih the level
    lightoff();
    Serial.print("level : ");
    Serial.println(level);
    delay(1000);
  }
}

void combo_easy(){
  int size_array = 20;
  int mycombo[size_array] ={1,1,2,1,2,2,1,2,1,1,1,2,1,2,1,2,1,2,2,2};
  
  int level = 1; //start level
  
  lightoff();
  lighton_animation();
  delay(500);//delay after light of (more smooth game)
  while(Serial.read()!= 'z'){  // if you want to get aou use z

    for(int i =0 ; i < level ; i ++){ //this loop make the sequence of the right left         
        if(mycombo[i] == 1){ //right light
          lighton_right();
          tone(buzzer, 5000);
          delay(200);
          noTone(buzzer);
          delay(300);
          lightoff();
      }
      else{ //left light
        lighton_left();
        tone(buzzer, 2000);
        delay(200);
        noTone(buzzer);
        delay(300);
        lightoff();
      }
    }

    light_color_faster(25 ,25 , 25); //white color
    int hitit = 0; //hit point
    while(hitit < level ){
        
        if(digitalRead(POWER_PIN) == HIGH){ // if the right sensor is on
              if(mycombo[hitit] ==1){ // if the right sensor is on and its should be
                hitit ++;
                Serial.println("good hit!");
                lighton();
                delay(200);
                lightoff_fast();
//                i++;
                
              }
              else{
                level = 0;
                light_color(25 ,0 , 0);
                Serial.println("Looosssseeerrrrrr");
              }
        }
        if(digitalRead(POWER_PIN2) == HIGH){ // if the left sensor is on and its should be
              if(mycombo[hitit] ==2){
                hitit ++;
                Serial.println("good hit!");
                lighton();
                delay(200);
                lightoff_fast();
//                i++;
              }
              else{
                level = 0;
                Serial.println("Looosssseeerrrrrr");
                light_color(25 ,0 , 0);
              }
        }        
      }
      level++;
      light_color(25 ,25 , 0); //green for finsih the level
      light_color(0 ,25 , 0); //green for finsih the level
      lightoff();
      Serial.print("level : ");
      Serial.println(level);
      delay(1000);
      
    }
  
}

void combo_gorila(){
  lightoff();  
  lighton_animation();
  int hitit = 0;
  int randomnumber = 0 ;
  int delta_time = 5;
  delay(500);//delay after light of (more smooth game)
  while(Serial.read()!= 'z'){  // if you want to get aou use z
    lightoff(); 
     randomnumber = random(1,3); //generate the sequence numer 1 or 2
     if(randomnumber == 1){ //right light
          lighton_right();
          delay(30);          
      }
      else{ //left light
        lighton_left();
        delay(30);
      }
      float currentMillis = millis(); 
      while((millis()-currentMillis)/1000 <delta_time){// time limt for punch  >>>  ( can change to random time?!?! )
        if(digitalRead(POWER_PIN) == HIGH){ // if the right sensor is on
              if(randomnumber ==1){ // if the right sensor is on and its should be
                lighton_middle();
                hitit ++;
                Serial.println(hitit);
                delay(200);
                lightoff_middle();
              }
              else{
                light_color(25 ,0 , 0);
                Serial.println("Looosssseeerrrrrr");
              }
        }
        if(digitalRead(POWER_PIN2) == HIGH){ // if the left sensor is on and its should be
              if(randomnumber ==2){
                lighton_middle();
                hitit ++;
                Serial.println(hitit);               
                delay(200);
                lightoff_middle();
              }
              else{
                Serial.println("Looosssseeerrrrrr");
                light_color(25 ,0 , 0);
              }

        
      }
    }
  } 
}
