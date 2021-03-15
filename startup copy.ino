int p = 0;
long startTime = millis();
long endTime;
long interval= 5000;

void dimmer(){
p=p+5;
if(p>=200){
p=p-20;  
}else if(p == 0){
p=p+20;  
}
}
void startup(){
  endTime = millis();
    for(int i=0; i<=8; i++) { 
    strip.setPixelColor(i, random(0,255),random(0,255),random(0,255));        
    strip.show();                          
    delay(80);
  }

  strip.show();
  dimmer();
 strip.setBrightness(p) ;
 for (int i = 0; i < 8; i++){

   if(endTime - startTime >= interval){
      state = 1;

    }
 }
}
