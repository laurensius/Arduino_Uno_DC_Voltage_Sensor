/*
 * Wiring :
 *    Sensor Pin      |   Arduino Pin
 * ====================================
 *    +               |   VCC
 *    -               |   GND
 *    S               |   A4
 *    
 */

int analogInput = A4;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; 
float R2 = 7500.0;
int value = 0;

void setup(){
  pinMode(analogInput, INPUT);
  Serial.begin(115200);
  Serial.print("DC VOLTMETER");
}

void loop(){
  value = analogRead(analogInput);
  vout = (value * 5) / 1024.0;
  vin = vout / (R2/(R1+R2));
  
  Serial.print("INPUT V= ");
  Serial.println(vin,2);
  delay(500);
}
