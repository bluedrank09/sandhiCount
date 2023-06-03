int buttonPin = 2; // input wire is connected to DP 2 on Arduino
int buttonState = 0; // 0 or 1
int counter = 0; // starting at 0
int buzzerPin = 3;
int buzzerCounter = 0;

void setup() {
  Serial.begin(9600); // starting serial moniter
  pinMode(buttonPin, INPUT); // sertting the button to be input
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin); // reading if the button returns a 0 or 1
  delay(250);// perfect amount of time in orer to recognise just one push

  // Serial.println(buttonState);

  if (buttonState == 1) { // 1 means pushed
    counter ++; // incrementing counter
    buzzerCounter ++;
    tone(buzzerPin, 300);
    delay(100);
    noTone(buzzerPin);
    Serial.println("Button pressed");
}

    if (counter == 10 && buzzerCounter == 10) {
    Serial.println("Counter is at 10");

    for(int i = 1; i <= 3; i++){
        tone(buzzerPin, 300);
        delay(750);
        noTone(buzzerPin);
        delay(750);
    }
    
    counter = 0; 
    buzzerCounter = 0;
  }


}