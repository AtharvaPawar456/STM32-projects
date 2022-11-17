//Reflow STM32 - Main-Code

//Working-OK-tested...


//Testing with STM32:
#define analogInPin PB0
#define RelayPin PC14

//Testing with arduino-uno:
//#define analogInPin A0  // Analog input pin that the potentiometer is attached to
//#define RelayPin 3      //Digital Pin (Relay Pin)

int value1 = 2022;
String x ;
int r=0,t=0;
//String name = "P,Temp,24,Relay,True,";
String array1[150];

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int relayVal = 0;
String statusTemp = "B";

//int count = 0;
//P,Temp,24,Relay,True

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(RelayPin, OUTPUT);
  digitalWrite(RelayPin, LOW);  
}

void loop() {

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 4095, 0, 100);    //connect pot Or sensor to +3.3V...

    if ((20 < outputValue ) && (outputValue < 30 )){
      delay(100);   //some time relay ON to heat the plate
      relayVal = 0;
      digitalWrite(RelayPin, LOW);  
//      Serial.println("Temp in Range");
      statusTemp = "I";
    }
    else if (outputValue <= 20){
      relayVal = 1;
      digitalWrite(RelayPin, HIGH);  
//      Serial.println("Temp Below Range");
      statusTemp = "B";

    }
    else if(outputValue >= 30){
      relayVal = 0;
      digitalWrite(RelayPin, LOW);  
//      Serial.println("Temp Above Range");
      statusTemp = "A";

    }
//Serial.print(sensorValue);
//Serial Print for Python Code...

//P,Temp,24,Relay,True

//int relayVal = relayVal;
//int sensorValue = count;

String stringOne = "H,Temp,";
String stringTwo = ",Relay,";
String stringFour = ",";
String stringThree = stringOne + outputValue + stringTwo + relayVal + stringFour + statusTemp + stringFour;
Serial.println(stringThree);
//count ++;
  delay(500);

}
