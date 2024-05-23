#include "SevSeg.h"
SevSeg sevseg;
int buttonpin = 10;
//int lastButtonstate = LOW;
int currenButtonState;
void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {3, 2, 8, 7, 6, 5, 4, 9};
  bool resistorsOnSegments = true;
  bool updateWithDelays = true;
  byte hardwareConfig = COMMON_ANODE; //
  sevseg.begin(hardwareConfig, numDigits, digitPins , segmentPins, resistorsOnSegments);
  pinMode(buttonpin, INPUT);
  sevseg.setBrightness(90);
}

void loop() {
  currenButtonState = digitalRead(buttonpin);
  if (currenButtonState == HIGH)
  {
    int randomNumber = random(1, 7); // put your main code here, to run repeatedly:
    sevseg.setNumber(randomNumber);
    sevseg.refreshDisplay();
    delay(500);
  }
//lastButtonstate = currenButtonState;
}
