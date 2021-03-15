boolean drumsLit = false;
boolean d1Toggle = false;
boolean d2Toggle = false;
boolean d3Toggle = false;
boolean d5Toggle = false;
boolean d6Toggle = false;
long startTime2 = millis();
long endTime2;
long interval2= 5000;
void drums() {
  if (!drumsLit) {
    pixelDrum();
    drumsLit = true;
  }
  /* boolean drums[] = {false, false, false, false, false, false};
    for (int i = 0; i < 8; i++) {
     if (drums[i] == 1 && i == !0 && i != 4) {
       drums[i] = !drums[i];
       if (drums[i]) {
         usbMIDI.sendControlChange(i + 20, 127, 1);
       }
       else {
         usbMIDI.sendControlChange(i + 20, 0, 1);

       }

     }
    }*/
  if (buttonStates[1]) {
    d1Toggle = !d1Toggle;
    if (d1Toggle) {
      usbMIDI.sendControlChange(1, 127, 41);
      Serial.print(buttonStates[1]);
    } else {
      usbMIDI.sendControlChange(1, 0, 41);

    }
  }
  if (buttonStates[2]) {
    d2Toggle = !d2Toggle;
    if (d2Toggle) {
      usbMIDI.sendControlChange(2, 127, 42);
    } else {
      usbMIDI.sendControlChange(2, 0, 42);

    }
  }
  if (buttonStates[3]) {
    d3Toggle = !d3Toggle;
    if (d3Toggle) {
      usbMIDI.sendControlChange(3, 127, 43);
    } else {
      usbMIDI.sendControlChange(3, 0, 43);

    }
  }
  if (buttonStates[5]) {
    d5Toggle = !d5Toggle;
    if (d5Toggle) {
      usbMIDI.sendControlChange(5, 127, 45);
    } else {
      usbMIDI.sendControlChange(5, 0, 45);

    }
  }
  if (buttonStates[6]) {
    d6Toggle = !d6Toggle;
    if (d6Toggle) {
      usbMIDI.sendControlChange(6, 127, 46);
    } else {
      usbMIDI.sendControlChange(6, 0, 46);

    }
  }
  /*if (buttonStates[7]) {
    d7Toggle = !d7Toggle;
    if (d7Toggle) {
      usbMIDI.sendControlChange(7, 127, 47);
    } else {
      usbMIDI.sendControlChange(7, 0, 47);

    }
    }  */
  if (buttonStates[0] == 1 ) {
    state = 1;
    drumsLit = false;
  }
  if (buttonStates[4] == 1 ) {
    state = 2;
    drumsLit = false;
  }
  if (buttonStates[7] == 1 ) {
      endTime2 = millis();
   if(endTime2 - startTime2 >= interval2){

     state = 0;
    drumsLit = false;
   }
  }

    /*for (int i = 0; i < 4; i++) {
       int thisPot = potStates[i];
       usbMIDI.sendControlChange(i+30, thisPot, 1);
      }*/
  }
  int thisKnob6 = analogRead(knob);
  //     Serial.println(thisKnob);

  /*  if (abs(thisKnob6 - lastKnob) > knobTol) {
      int knobOut = map(thisKnob6, 0, 1023, 0, 127);
      usbMIDI.sendControlChange(2, knobOut, 61);
      lastKnob = thisKnob6;
    }
    while (usbMIDI.read()) {

    }*/
  void pixelDrum() {
    boolean isState = false;

    for (int i = 0; i <= 8; i++) {
      strip.setPixelColor(i, 0, 255, 0);
    }
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(4, 0, 0, 255);
    strip.show();

  }
