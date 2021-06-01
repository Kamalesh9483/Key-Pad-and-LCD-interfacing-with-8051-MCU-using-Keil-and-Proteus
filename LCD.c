#define display_port P2
#define LCD_control_Port P1
#define curserCmd1 0x38				// Cursor line 1 position 3
#define curserCmd2 0x0F				// LCD ON, cursor ON
#define curserCmd3 0x01				// Clear display screen
#define curserCmd4 0x80				// Force cursor to beginning of first line 	

// LCD module connections 
sbit RS = LCD_control_Port^0; 
sbit RW = LCD_control_Port^1; 
sbit EN = LCD_control_Port^2; 

// Function to create delay
void msdelay(unsigned int msTime){
	int i, j;
	for(i =0; i<msTime; i++)
			for(j=0; j<1275; j++);
	}
	
// Function to call enable
void enCall(){
	EN = 1;
	msdelay(10);
	EN = 0; 
	}
	
// Function for lcd_command - this is to pass commands
void lcd_Cmd(unsigned char command){
	display_port = command; 		
	RS = 0;			 				        
	RW = 0;	
	enCall();							
	}
	
// Function for LCD Display
void lcd_data(unsigned char text){
		display_port = text;			
		RS = 1;										
		RW = 0;									
		enCall();							
		}
	
// Function to initialize the LCD 
void lcd_init(){
	char cmdList[] = {curserCmd1, curserCmd2, curserCmd3, curserCmd4};
	int l;
	for (l=0; l<sizeof(cmdList); l++){
		lcd_Cmd(cmdList[l]);
		msdelay(5); 
	}	
}

// Function for string read
void stringRead(unsigned char text){
	lcd_data(text);
}
