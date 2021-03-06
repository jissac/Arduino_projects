const int switchPin=8;
unsigned long previousTime=0;
int switchState=0;
int prevSwitchState=0;
int led=2;
long interval=6000;

// set output pins
void setup() {
  for(int x =2;x<8;x++){
    pinMode(x,OUTPUT);
  }
  pinMode(switchPin,INPUT);
}

//get start time
void loop(){
  unsigned long currentTime = millis();
  
  //check if time interval is reached
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    if (led == 7) {
      
    }
  }
  
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState){
    for(int x =2; x<8; x++) {
      digitalWrite(x,LOW);
    }
  led = 2;
  previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
