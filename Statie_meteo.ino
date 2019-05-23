#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display (7, 6, 5, 4, 3); 
#define DHTPIN 8   
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

int t1, decimal , h;


const unsigned char termometru [] PROGMEM = {
  B00000000, B01000000, B00000000,
  B00000000, B01100111, B00000000,
  B00000000, B01101000, B10000000,
  B00011000, B00001000, B10011100,
  B00011100, B11101010, B10000000,
  B00001001, B00001010, B10011000,
  B00000010, B00001010, B10000000,
  B00000100, B00001010, B10011100,
  B00001000, B00001010, B10000000,
  B00001000, B00001010, B10011000,
  B11101000, B00001010, B10000000,
  B11101000, B00001010, B10011100,
  B00001000, B00001010, B10000000,
  B00001000, B00001010, B10000000,
  B00000100, B00011010, B11000000,
  B00000010, B00110111, B01100000,
  B00001001, B00101111, B10100000,
  B00011100, B11101111, B10100000,
  B00011000, B00110111, B01100000,
  B00000000, B00011111, B11000000,
};
  

const unsigned char umiditate [] PROGMEM = {
 B00000000, B10000000, B00000000,
 B00000001, B11000000, B00000000,
 B00000001, B01000000, B00000000,
 B00000011, B01100000, B00000000,
 B00000010, B00100000, B00000000,
 B00000110, B00110000, B00000000,
 B00000100, B00010000, B00000000,
 B00001100, B00011000, B00000000,
 B00001000, B00001000, B00000000,
 B00011000, B00001100, B00000000,
 B00010000, B00001100, B00000000,
 B00110000, B00000100, B00000000,
 B00111111, B00000110, B00000000,
 B00111111, B10000110, B00000000, 
 B00111111, B11000110, B00000000,
 B00111111, B11111110, B00000000,
 B00111111, B11111110, B00000000,
 B00011111, B11111100, B00000000,
 B00001111, B11111000, B00000000,
 B00000111, B11110000, B00000000,
 B00000001, B11000000, B00000000,
};

 
void setup(){
  Serial.begin(9600);
   display.begin();
   dht.begin();
   display.clearDisplay();
   display.display();
   delay(250);
}
 
void loop(){
   display.clearDisplay();
   display.setTextColor(BLACK, WHITE);
   display.setCursor(31,5);//(x,y)- position 
   float t = dht.readTemperature();
   display.setTextSize(2);
   display.print(t,0);
   t1 = t ;
   decimal = 10*t - 10*t1;
   display.setCursor(59,12); 
   display.setTextSize(1);
   display.print(decimal);
   display.setCursor(53,12);
   display.setTextSize(1);
   display.print(".");
   display.drawRect(65, 5, 4, 4,BLACK );
   display.setCursor(72,5);
   display.setTextSize(2);
   display.print( "C" ) ;
   display.setCursor(31, 30);
   display.setTextSize(2);
   h = dht.readHumidity();
   display.print(h);
   display.setCursor(53, 37);
   display.setTextSize(1);
   display.print( " % " ) ; 
   display.drawBitmap( 3, 1,  termometru , 22, 21, 1); // (x,  y, bitmap, w,  h, color)
   display.drawBitmap( 8, 25, umiditate , 21, 20, 1);
   display.display();
   delay(500);    
  
}
