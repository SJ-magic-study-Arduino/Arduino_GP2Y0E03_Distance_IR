/************************************************************
************************************************************/
#define PLOTTER

/************************************************************
************************************************************/
#include <Wire.h>
#include "GP2Y0E03.h"

/************************************************************
************************************************************/
const int GP2Y0E03_I2C_ADDR = 0x40;

GP2Y0E03 gp2y0e03( GP2Y0E03_I2C_ADDR );

/************************************************************
************************************************************/

/******************************
******************************/
void setup(){
	Serial.begin( 9600 );
	Wire.begin();
}

/******************************
******************************/
void loop(){
	float distance;
	distance = gp2y0e03.get_length();
#ifdef PLOTTER
	Serial.print( millis() / 1000 % 2 * 10 );
	Serial.print(",");
	
	if ( distance != -1 ){
		Serial.println( distance );
	} else {
		Serial.println( -1 );
	}
	
	delay(100);
	
#else

	if ( distance != -1 ){
		Serial.print("Distance:");
		Serial.print( distance );
		Serial.println("cm");
	} else {
		Serial.println("Out Range.");
	}
	
	delay(1000);

#endif
	
}

