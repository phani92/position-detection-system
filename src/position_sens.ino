#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN     13

const int analog_Inpin = A1; // The voltage divider circuit output is connected to A1 pin of Aurdino
int sensor_value = 0;        // Initalising the variables
int output_value = 0;
int pos = 0;
int v =0;

LiquidCrystal_I2C lcd(0x20);          // Set the LCD I2C address

void setup()
{
pinMode ( BACKLIGHT_PIN, OUTPUT );    // Setting backlight pin and making it high to get a bright display
digitalWrite (BACKLIGHT_PIN, HIGH );
lcd.begin(16,2);                      // setting the start point of 16 bit LCD screen

lcd.home ();
lcd.print ("Position =");
lcd.setCursor (0,1);
delay(200);
}
                                     // Main logic to be executed for calculation and display of values
void loop()
{
  lcd.home ();
  sensor_value = analogRead(analog_Inpin);
  output_value = map(sensor_value, 0, 1023, 0, 255);
  float v = ( output_value * 5.0 )/255 ;
  double pos = ((0.01306)*(v*v*v*v))+((-0.09572)*(v*v*v))+((0.04809)*(v*v))+((-1.479)*v)+(9.96) ;
  lcd.setCursor(5,1);
  lcd.print(pos);
  delay(1000);
}

  //double pos = (( -0.01191 ) * (v * v * v * v )) + (( 0.1439 ) * (v * v * v) ) + (( -0.3773 ) * (v * v )) + ( ( -2.222 ) * v ) + 10.03;
  //double pos = (( 0.0001428 ) * (v * v * v * v )) + (( -0.005604 ) * (v * v * v) ) + (( -0.0482 ) * (v * v )) + ( ( -0.5646 ) * v ) + 5.015;
  //double pos = (( -0.002749 ) * (v * v * v) ) + (( 0.03036 ) * (v * v )) + ( ( -0.5289 ) * v ) + 5.004;
  //double pos = ((8.076)*(v*v*v*v*v*v*v*v))+((-71.66)*(v*v*v*v*v*v*v))+((262.6)*(v*v*v*v*v*v))+((-512.9)*(v*v*v*v*v))+((573.8)*(v*v*v*v))+((-366)*(v*v*v))+((124.1)*(v*v))+((-14.1)*v)+0.1289;
