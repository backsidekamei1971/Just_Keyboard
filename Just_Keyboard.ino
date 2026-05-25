#include <font.h>
#include <SSD1306ASCII.h>
// ^ - modified for faster SPI
#include <PS2Keyboard.h>
#include <EEPROM.h>

#define OLED_DATA 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RST 13
SSD1306ASCII oled(OLED_DATA, OLED_CLK, OLED_DC, OLED_RST, OLED_CS);

// Keyboard
const int DataPin = 8;
const int IRQpin =  3;
PS2Keyboard keyboard;

//PS2Keyboard keyboard;
//int incomingByte = 0; // for incoming serial data

String c;
int row;

void setup(){
    keyboard.begin(DataPin, IRQpin);
    oled.ssd1306_init(SSD1306_SWITCHCAPVCC);
    oled.clear();
    oled.print("Hello World!");

 // keyboard.begin(DataPin, IRQpin);
}

void loop(){
row=row+1;
String c;
if(keyboard.available()){
char c = keyboard.read();
oled.setCursor(0,row);
oled.print(c);
oled.println("\n");
}
}

