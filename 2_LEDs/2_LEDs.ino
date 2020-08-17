//Switching on & off two leds with arduino programming using digitalWrite method
//digitalWrite method we define the ON and OFF states of the LEDs by HIGH and LOW commands respectively.

const int redLED = 9, blueLED = 10;  //Declaring and Initialising pins for both LEDs
const int roffTime = 100, ronTime = 100;  //Off and On time for red LED in milliseconds
const int boffTime = 100, bonTime = 100;  //Off and On time for blue LED in milliseconds

void setup() {
  
  pinMode(redLED,OUTPUT);  //Output states the final outcome as from the arduino
  pinMode(blueLED,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {

  digitalWrite(13,LOW);

  //Blinking red led using for loop
  for (int i=1; i<=4; i=i+1){
    digitalWrite(redLED,HIGH);  //HIGH = ON
    delay(ronTime);
    digitalWrite(redLED,LOW);  //LOW = OFF
    delay(roffTime);
  }

  //Blinking blue led using for loop
  for (int i=1; i<=4; i=i+1){
    digitalWrite(blueLED,HIGH);
    delay(bonTime);
    digitalWrite(blueLED,LOW);
    delay(boffTime);
  }
}
