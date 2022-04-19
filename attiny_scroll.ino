#include "TinyWireM.h"
#include "TinyOzOLEDlimpfish.h"

String message;

int fontcolumn =0;
int messagei = 0;
int message_char_index = 0;



void setup() {

  OzOled.init();
  OzOled.setDeactivateScroll();


  message = "HELLO@WORLD[[[@THIS@IS@A@SMOOTH@LONG@SCROLL@TEST@USING@AN@ATTINY>;@AND@A@SSD796<@I8C@OLED[@@@";

  // greatly reduced font set, caps ony
  // @ is space
  // [ is .
  //OzOled.printBiggerString("HELLO", 0, 0, 4);
  
  //OzOled.printString("HELLO", 0, 0, 5);

  //OzOled.printNumber((long)12345, 0, 0);
}


void loop() 
{

  // Setup scroll...
  OzOled.setDeactivateScroll(); 
  OzOled.setCursorXYPixel(0,0);
  OzOled.sendData(0); // blank first column for wrap
  OzOled.setCursorXYPixel(0,1);
  OzOled.sendData(0); // blank first column for wrap
  OzOled.setCursorXYPixel(126,0);
  OzOled.sendBiggerCharData(message[messagei],fontcolumn); // top half
  OzOled.setCursorXYPixel(126,1);
  OzOled.sendBiggerCharData(message[messagei],fontcolumn+12); // lower half
  fontcolumn++; fontcolumn%=12; // column

  if (fontcolumn==0)   // increment character index?
  {
    messagei++;
    messagei%=message.length(); // roll over
  }

  
  OzOled.scrollLeftPixel(0,1,8); // Perform hardware scroll
  OzOled.setDeactivateScroll();  // End... moved 1 pixel?
  
  delay(10); 

  //perform other functions while scrolling stopped





}
