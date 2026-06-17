/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int ledred = 16;
int ledyellow = 12;
int ledgreen = 13;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  Serial.begin(115200); 

}

// the loop routine runs over and over again forever:
void loop() {
  turn_on(ledred);
  turn_on(ledyellow);
  turn_on(ledgreen);
}
void turn_on(int lightnum){
  brightness = 0;
  for(int i=0;i<=101;i++){
    analogWrite(lightnum, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    delay(10);
    Serial.println(brightness);
    //Serial.println("--------");
  }
  Serial.println("---------");
}
  

  // change the brightness for next time through the loop:
  //brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  //if (brightness <= 0 || brightness >= 255) {
    //fadeAmount = -fadeAmount;
  //}
  // wait for 30 milliseconds to see the dimming effect
  //delay(10);
  




  //123

