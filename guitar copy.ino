boolean guitarLit = false;
boolean button1Toggle = false;
boolean button2Toggle = false;
boolean button3Toggle = false;
boolean button5Toggle = false;
boolean button6Toggle = false;
boolean button7Toggle = false;
int knob2 = A0;
int knob3 = A1;
int knob4 = A2;

int prevVal = 0;
void guitar() {

  for (int i = 0; i < 8; i++) {

    //Serial.println(buttonStates[2]);
  }
  if (!guitarLit) {
    pixelGuitar();
    guitarLit = true;
  }
  /*  boolean guitarArray[] = {false, false, false, false, false,false};
      for (int i = 0; i < 8; i++) {
      if (buttonStates[i] == 1 && i == !0 && i != 4) {
        guitarArray[i] = !guitarArray[i];
        if (guitarArray[i]) {
          usbMIDI.sendControlChange(i, 127, 1);
        }
        else {
          usbMIDI.sendControlChange(i, 0, 1);
        }

      }
      }*/
  if (buttonStates[1]) {
    button1Toggle = !button1Toggle;
    if (button1Toggle) {
      usbMIDI.sendControlChange(1, 127, 1);
      Serial.print(buttonStates[1]);
    } else {
      usbMIDI.sendControlChange(1, 0, 1);

    }
  }
  if (buttonStates[2]) {
    button2Toggle = !button2Toggle;
    if (button2Toggle) {
      usbMIDI.sendControlChange(2, 127, 2);
    } else {
      usbMIDI.sendControlChange(2, 0, 2);

    }
  }
  if (buttonStates[3]) {
    button3Toggle = !button3Toggle;
    if (button3Toggle) {
      usbMIDI.sendControlChange(3, 127, 3);
    } else {
      usbMIDI.sendControlChange(3, 0, 3);

    }
  }
  if (buttonStates[5]) {
    button5Toggle = !button5Toggle;
    if (button5Toggle) {
      usbMIDI.sendControlChange(5, 127, 5);
    } else {
      usbMIDI.sendControlChange(5, 0, 5);

    }
  }
  if (buttonStates[6]) {
    button6Toggle = !button6Toggle;
    if (button6Toggle) {
      usbMIDI.sendControlChange(6, 127, 6);
    } else {
      usbMIDI.sendControlChange(6, 0, 6);

    }
  }
  if (buttonStates[7]) {
    button7Toggle = !button7Toggle;
    if (button7Toggle) {
      usbMIDI.sendControlChange(7, 127, 7);
    } else {
      usbMIDI.sendControlChange(7, 0, 7);

    }
  }


  if (buttonStates[0] == 1 ) {
    state = 2;
    guitarLit = false;
  }
  if (buttonStates[4] == 1 ) {
    state = 3;
    guitarLit = false;
  }
    if (buttonStates[2] == 1 && buttonStates[1]==1 ) {
       state = 0;
    guitarLit = false;
    }

  /*for (int i = 0; i < 4; i++) {
    int thisPot = analogRead(potPins[i]);

    if (abs(thisPot - lastKnob) > knobTol) {

      int thisPot = potStates[i];
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
    }
  }*/



 int thisKnob = analogRead(knob);
     Serial.println(thisKnob);

  if (abs(thisKnob - lastKnob) > knobTol) {
    int knobOut = map(thisKnob, 0, 1023, 0, 127);
    usbMIDI.sendControlChange(2, knobOut, 51);
    lastKnob = thisKnob;
  }
  while (usbMIDI.read()) {

  }
   int thisKnob2 = analogRead(knob2);

  if (abs(thisKnob - lastKnob) > knobTol) {
    int knobOut = map(thisKnob, 0, 1023, 0, 127);
    usbMIDI.sendControlChange(2, knobOut, 51);
    lastKnob = thisKnob;
    Serial.println("moved");
  }
  while (usbMIDI.read()) {

  }
   int thisKnob3 = analogRead(knob3);
  if (abs(thisKnob - lastKnob) > knobTol) {
    int knobOut = map(thisKnob, 0, 1023, 0, 127);
    usbMIDI.sendControlChange(2, knobOut, 52);
    lastKnob = thisKnob;
  }
  while (usbMIDI.read()) {

  }
   int thisKnob4 = analogRead(knob4);
  if (abs(thisKnob - lastKnob) > knobTol) {
    int knobOut = map(thisKnob, 0, 1023, 0, 127);
    usbMIDI.sendControlChange(2, knobOut, 53);
    lastKnob = thisKnob;
  }
  while (usbMIDI.read()) {

  }
}

void pixelGuitar() {
  boolean isState = false;

  for (int i = 0; i <= 8; i++) {

    strip.setPixelColor(i, 255, 0, 0);
  }
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(4, 0, 255, 0);
  strip.show();

}
