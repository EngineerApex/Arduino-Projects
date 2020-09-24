//Include the lcd library:
#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,5,4,3,2);  //Declaring object lcd and pins connected

int trigPin = 13;  
int echoPin = 11;  //This is the pin that will send the signals to measure the distance
float pingTime;
float dist;
float speedofsound = 776.5;  //miles per hour

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16,2);  //This is the start code of the lcd
  lcd.setCursor(0,0);  //Sets the cursor
  lcd.print("Target Distance ");  
}

void loop() {
  //We are creating high and low waves which will detect the object
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);

  //Calculations and conversions
  pingTime = pulseIn(echoPin,HIGH);
  pingTime = pingTime/1000000.;
  pingTime = pingTime/3600.;

  dist = speedofsound * pingTime;
  dist = dist/2;
  dist = dist*63360.;

  lcd.setCursor(0,1);
  lcd.print("    ");
  lcd.setCursor(0,1);
  lcd.print(dist);
  Serial.print("The distance is ");
  Serial.print(dist);
  lcd.print(" Inches");
  delay(250);
  
}
