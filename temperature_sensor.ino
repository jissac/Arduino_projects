const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600); // open a serial port
  // set output pins
  for(int pinNumber=2; pinNumber<5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);  
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) *5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) *100;
  Serial.println(temperature);
  
  // Turn off LEDs for temperatures below threshold
  if(temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  
  // Turn on one LED for low temperatures
  else if (temperature >= baselineTemp+2 && 
              temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    } 
  
  // Turn on two LEDs for low temperatures 
  else if (temperature >= baselineTemp+4 && 
              temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
              }
  // Turn on all three LEDs for low temperatures
  else if (temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    }
  // Make sure values aren't erratic
  delay(1);
              
}
