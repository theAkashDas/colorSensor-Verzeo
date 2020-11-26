#define ldr A0 // pin where we connected the ldr and the resistor

int valueAnalog = 0;     // result of reading the analog pin new

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);// sets serial port for communication
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  digitalWrite(9,HIGH);
  valueAnalog = analogRead(ldr); // read the value from the LDR
  Serial.println(valueAnalog);      //this prints the result on the serial monitor
  delay(100); // wait a little
  analogWrite(13,LOW);
  analogWrite(12,LOW);
  analogWrite(8,LOW);
  
  //conditions for determination of color. The limiting values will change according to the intensity of the surrounding lights.
  //check it and change the values accordingly.
  if(valueAnalog>17 && valueAnalog<25)
  {
    Serial.println("RED");//prints in the serial monitor
    setColor(255,0,0);
  }
  
  else if(valueAnalog>12 && valueAnalog<16)
  {
     Serial.println("GREEN");//prints in the serial monitor
     setColor(0,255,0);
     
  }
  else if(valueAnalog>3 && valueAnalog<11){
       Serial.println("BLUE");//prints in the serial monitor
       setColor(0,0,255);
  }
  else
  Serial.println("Some Color Other than RGB");
}

void setColor(int red, int green, int blue)
{
  analogWrite(13, red);
  analogWrite(12,green);
  analogWrite(8,blue);
}
