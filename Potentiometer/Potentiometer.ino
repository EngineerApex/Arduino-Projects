/*Code to vary potential by altering the variable resistance
of the potentiometer*/
int potPen = A0;  //This is where the potentiometer pin will be inserted
int readValue;
float voltage;

void setup() {
  pinMode(potPen,INPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(potPen);  //AnalogRead will display the v value on the monitor
  voltage = (5./1023.) * readValue;  
  Serial.println(voltage);
  delay(1000);
}
