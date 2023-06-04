#include <LedControl.h> // library to control the LED matrix

int buttonPin = 2; // input wire is connected to DP 2 on Arduino
int buttonState = 0; // 0 or 1
int counter = 0; // starting at 0
int buzzerPin = 3;
int buzzerCounter = 0;
int DIN = 11; // pins on LED Matrix
int CS =  7;
int CLK = 13; 

// initialising all of the different numbers
byte z[8] = {0x00,0x18,0x24,0x24,0x24,0x24,0x18,0x00}; //zero
byte o[8] = {0x00,0x18,0x28,0x08,0x08,0x08,0x3C,0x00}; // one
byte w[8] = {0x18,0x24,0x44,0x08,0x10,0x20,0x7C,0x00}; // two
byte r[8] = {0x00,0x3C,0x04,0x3C,0x04,0x3C,0x00,0x00}; //three
byte f[8] = {0x00,0x08,0x18,0x28,0x7E,0x08,0x08,0x08}; //four
byte i[8] = {0x00,0x3C,0x20,0x3C,0x04,0x3C,0x00,0x00}; // five
byte x[8] = {0x00,0x00,0x18,0x20,0x38,0x24,0x18,0x00}; // six
byte v[8] = {0x00,0x7E,0x04,0x08,0x10,0x10,0x10,0x00}; // seven
byte g[8] = {0x00,0x38,0x28,0x38,0x28,0x38,0x00,0x00}; // eight
byte e[8] = {0x00,0x18,0x24,0x24,0x18,0x04,0x24,0x18}; // nine
byte n[8] = {0x00,0x2E,0x2A,0x2A,0x2A,0x2E,0x00,0x00}; // ten

LedControl lc=LedControl(DIN,CLK,CS,0);        

void setup() {
  Serial.begin(9600); // starting serial moniter
  pinMode(buttonPin, INPUT); // sertting the button to be input
  pinMode(buzzerPin, OUTPUT);
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      // Set the brightness to maximum value
 // lc.clearDisplay(0);
  displayNumber(0);

}

void loop() {
  buttonState = digitalRead(buttonPin); // reading if the button returns a 0 or 1
  delay(250);// perfect amount of time in orer to recognise just one push

  // Serial.println(buttonState);
  if (buttonState == 1) { // 1 means pushed
    counter ++; // incrementing counter
    displayNumber(counter); 
    buzzerCounter ++;
    tone(buzzerPin, 300); // making buzzer buzz
    delay(100); // buzer will bbuzz for 100 milliseconds
    noTone(buzzerPin); // stops buzzer
    Serial.println("Button pressed");
  }
  
  if (counter == 10 && buzzerCounter == 10) { // checks if there have been ten clicks
    Serial.println("Counter is at 10");
    
    for(int i = 1; i <= 3; i++){ // three buzzes at ten presses
      tone(buzzerPin, 300);
      delay(750);
      noTone(buzzerPin);
      delay(750);
      
    }
    
    counter = 0; // resetting
    buzzerCounter = 0;
    displayNumber(0);
  }
    
}

void printByte(byte character []) // displays the figure on the LED martix
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

void displayNumber(int counter){ // displaying the number of clicks using the counter and printByte
  if (counter == 1){
    printByte(o);
   } else if (counter == 2){
    printByte(w);
   } else if (counter == 3){
    printByte(r);
   } else if (counter == 4){
    printByte(f); 
   } else if (counter == 5){
    printByte(i);
   } else if (counter == 6){
    printByte(x);
   } else if (counter == 7){
    printByte(v);
   } else if (counter == 8){
    printByte(g);
   } else if (counter == 9){
    printByte(e); 
   } else if (counter == 10){
    printByte(n);
   } else if (counter == 0){
    printByte(z); 
   }
}

   
