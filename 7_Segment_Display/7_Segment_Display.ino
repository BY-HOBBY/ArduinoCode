#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
    //Set to 1 for single digit display
    byte numDigits = 1;

    //Defines pin connections in order: A, B, C, D, E, F, G, DP
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {11, 12, 8, 7, 6, 10, 9, 5};
    bool resistorsOnSegments = true;

    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop()
{ 
   //Display numbers one by one with 1 seconds delay
   for(int i = 0; i < 10; i++)
   {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(1000);
   }
}
