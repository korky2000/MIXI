boolean bassLit = false;
boolean bass1Toggle = false;
boolean bass2Toggle = false;

boolean bass3Toggle = false;
boolean bass5Toggle = false;
boolean bass6Toggle = false;
boolean bass7Toggle = false;
void bass() {
  if (!bassLit) {
    pixelBass();
    bassLit = true;
  }
  /* boolean bass[] = {false, false, false, false, false, false};
    for (int i = 0; i < 8; i++) {
     if (buttonStates[i] == 1 && i == !0 && i != 4) {
       bass[i] = !bass[i];
       if (bass[i]) {
         usbMIDI.sendControlChange(i + 40, 127, 1);
       }
       else {
         usbMIDI.sendControlChange(i + 40, 0, 1);

       }

     }
    }*/
  if (buttonStates[1]) {
    bass1Toggle = !bass1Toggle;
    if (bass1Toggle) {
      usbMIDI.sendControlChange(1, 127, 21);
      Serial.print(buttonStates[1]);
    } else {
      usbMIDI.sendControlChange(1, 0, 21);

    }
  }
  if (buttonStates[2]) {
    bass2Toggle = !bass2Toggle;
    if (bass2Toggle) {
      usbMIDI.sendControlChange(2, 127, 22);
    } else {
      usbMIDI.sendControlChange(2, 0, 22);

    }
  }
  if (buttonStates[3]) {
    bass3Toggle = !bass3Toggle;
    if (bass3Toggle) {
      usbMIDI.sendControlChange(3, 127, 23);
    } else {
      usbMIDI.sendControlChange(3, 0, 23);

    }
  }
  if (buttonStates[5]) {
    bass5Toggle = !bass5Toggle;
    if (bass5Toggle) {
      usbMIDI.sendControlChange(5, 127, 25);
    } else {
      usbMIDI.sendControlChange(5, 0, 25);

    }
  }
  if (buttonStates[6]) {
    bass6Toggle = !bass6Toggle;
    if (bass6Toggle) {
      usbMIDI.sendControlChange(6, 127, 26);
    } else {
      usbMIDI.sendControlChange(6, 0, 26);

    }
  }
  if (buttonStates[7]) {
    bass7Toggle = !bass7Toggle;
    if (bass7Toggle) {
      usbMIDI.sendControlChange(7, 127, 27);
    } else {
      usbMIDI.sendControlChange(7, 0, 27);

    }
  }
   int thisKnob7 = analogRead(knob);
     //Serial.println(thisKnob7);

  if (abs(thisKnob7 - lastKnob) > knobTol) {
    int knobOut = map(thisKnob7, 0, 1023, 0, 127);
    usbMIDI.sendControlChange(2, knobOut, 71);
    lastKnob = thisKnob7;
  }
  while (usbMIDI.read()) {

  }
    if (buttonStates[0] == 1) {
      state = 3;
      bassLit = false;
    }
    if (buttonStates[4] == 1 ) {
      state = 3;
      bassLit = false;
    }

    /* for (int i = 0; i < 4; i++) {
       int thisPot = potStates[i];
       usbMIDI.sendControlChange(i + 70, thisPot, 1);
      }*/

  }
  void pixelBass() {
    boolean isState = false;

    for (int i = 0; i <= 8; i++) {
      strip.setPixelColor(i, 0, 0, 255);
    }
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(4, 0, 255, 0);
    strip.show();

  }
