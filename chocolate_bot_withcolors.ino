/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 28 May 2015
 by Michael C. Miller
 modified 8 Nov 2013
 by Scott Fitzgerald

 http://arduino.cc/en/Tutorial/Sweep
*/ 
#define BLYNK_PRINT Serial  
#include <Servo.h> 
#include <BlynkSimpleEsp8266.h>                         // Include library to use Blynk app functionalities
#include <ESP8266WiFi.h>       
#include <Adafruit_NeoPixel.h>                                                        // Include the library to work with RGB ring

Servo myservo_m1;

int motor_1=4;
int control_input;

char auth[] = "f92540d7b8df477e8683d44a82aa4d17";        // Variable to store auth token from Blynk 
char ssid[] = "iBrain_FF";                               // Variables to store network credentials
char pass[] = "lemons@iB";

uint32_t red_colour;                                                                  // Variables for storing the colour values.
uint32_t green_colour;
uint32_t blue_colour;
uint32_t off_colour;

/* Declare instances */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 4, NEO_GRB + NEO_KHZ800);           // Initialising a Adafruit_Nopixel instance-strip


/* Define functions */   

/*Function definition to turn ON the Red colour */
void red()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first RGB pixel, loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, red_colour );                                              // To set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn ON the Green colour */
void green()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, green_colour );                                            // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn ON the Blue colour */
void blue()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, blue_colour );                                             // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn OFF colour */
void off()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, off_colour );                                              // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}


BLYNK_WRITE(V0)                                                                       // Function that is called when device receives an update of virtual Pin value from the server                      
{
  control_input= param.asInt();   
  Serial.print("Recieved value: ");
  Serial.println(control_input);
  if(control_input==1)
  {
       myservo_m1.write(90);
       delay(1000);
       myservo_m1.write(180);
       delay(1000);     
    
  if(control_input==1)
  blue();     
  } 
   
}

void setup() 
{ 
  Serial.begin(115200);  
  strip.begin();                                                                      // Initialize the Adafruit neopixel library
  strip.setBrightness(128);                                                           // Set the brightness of RGB ring

  //strip.Color returns an integer according to a spcific color set in its arguements
  red_colour = strip.Color(255, 0, 0);                                                 // 255,0,0 for Red                                                                                              
  green_colour = strip.Color(0, 255, 0);                                               // 0,255,0 for Green
  blue_colour = strip.Color(0, 0, 255);                                                // 0,0,255 for Blue
  off_colour = strip.Color(0, 0, 0);    // Initialize the serial library
  Blynk.begin(auth, ssid, pass);     
  myservo_m1.attach(motor_1);  // attaches the servo on GIO2 to the servo object 
 } 
 
void loop() 
{                                                                                        // waits 15ms for the servo to reach the position     
  Blynk.run();                                                                          // To process incoming commands and perform housekeeping of Blynk connection
} 


