#include <Bounce2.h>
int lastKnob = 0;
int knobTol = 10;
int knob = A3;

int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
int state = 0;
Bounce * buttons = new Bounce[8];

int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
  Serial.println("start");
  buttonStart();
  buttonUpdate();
}

void loop() {
  buttonUpdate();
  updatePots();
  for (int i = 0; i < 8; i++) {

    Serial.println(buttonStates[i]);
  }

  switch (state) {
    case 0: startup(); break;
    case 1: guitar(); break;
    case 2: bass(); break;
    case 3: drums(); break;
  }

}
void buttonStart() {
  for (int i = 0; i < 8; i++) {
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(25);
  }
}
void buttonUpdate() {
  for (int i = 0; i < 8; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      buttonStates[i] = 1;
      Serial.print(buttonStates[i]);

    }
    else {
      buttonStates[i] = 0;
    }
  }
}
void updatePots() {
  boolean isState = true;
  if (state == 1) {
    isState = !isState;
  }
  for (int i = 0; i < 4; i++) {
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}
