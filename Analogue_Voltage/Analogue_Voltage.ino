//Analog volatage writing on the arduino serial monitor

const int redLED = 9, blueLED = 10;  //Red and Blue LED
const int roffTime = 1000, ronTime = 1000;  //Red off and on time
const int boffTime = 1000, bonTime = 1000;  //Blue off and on time
int bBlinks, rBlinks;  //Red and blue blinks input to take from user

void setup() {

  Serial.begin(9600);
  pinMode(redLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(13,OUTPUT);

  //Taking input for red led from the user
  Serial.println("Enter the times you want the red LED to blink");
  while(Serial.available()==0){}  //waiting till the user inputs a value
  rBlinks = Serial.parseInt();  //scanf like c which accepts the input value

  //Taking input for blue led from the user
  Serial.println("Enter the times you want the blue LED to blink");
  while(Serial.available()==0){}
  bBlinks = Serial.parseInt();
}
void loop() {

  digitalWrite(13,LOW);

  //Blinking red led using for loop
  Serial.println("Red led:-");
  for (int i=1; i<=rBlinks; i=i+1){    
    Serial.print("Blink : ");
    Serial.println(i);
    
    analogWrite(redLED,5);  //ANALOG WRITE = 51 X INPUT VALUE 
    delay(ronTime);
    analogWrite(redLED,0);
    delay(roffTime);
  }
  
  Serial.println(" ");

  //Blinking blue led using for loop
  Serial.println("Blue led:-");
  for (int i=1; i<=bBlinks; i=i+1){
    Serial.print("Blink :");
    Serial.println(i);
    
    analogWrite(blueLED,2);
    delay(bonTime);
    analogWrite(blueLED,0);
    delay(boffTime);
  }  
  Serial.println(" ");
}
