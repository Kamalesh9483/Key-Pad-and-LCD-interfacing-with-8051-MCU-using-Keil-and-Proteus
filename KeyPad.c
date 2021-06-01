#include "reg51.h"
#include "LCD.c"

#define switchPort P3
sbit col1 = switchPort^0;
sbit col2 = switchPort^1;
sbit col3 = switchPort^2;
sbit row1 = switchPort^4;
sbit row2 = switchPort^5;
sbit row3 = switchPort^6;
sbit row4 = switchPort^7;

// Function prototype of LCD
void msdelay(unsigned int msTime);
void enCall();
void lcd_Cmd(unsigned char command);
void lcd_data(unsigned char text);
void lcd_init();
void stringRead(unsigned char text);
void switchPress();

// Function to print character
void printChar(int firstDigit)
{
	unsigned char numArray[] = "123456789*0#";
	int i = firstDigit;
			if (col1 == 0){stringRead(numArray[i]);}
			else if (col2 ==0){stringRead(numArray[i+1]);}
			else if (col3 ==0){stringRead(numArray[i+2]);}
}

// Function for switch press
void switchPress()
{		
		row1 = 0;
		printChar(0);	// Activating row 1
		
		row1 = 1;
		row2 = 0;
		printChar(3);	// Activating row 2

		row2 = 1;
		row3 = 0;
		printChar(6);	// Activating row 3
		
		row3 = 1;
		row4 = 0;
		printChar(9);	// Activating row 4
	
		row4 = 1;		
}	
void main()
{
// Initialization
	row1 = row2 = row3 = row4 = 0;	
  col1 = col2 = col3 = 1;
	
	while(1){
		lcd_init();
		switchPress();
	}
}
