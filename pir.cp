int calibrationTime = 30;

long unsigned int lowIn;

long unsigned int pause = 5000;

boolean lockLow = true;

boolean takeLowTime;

int piroutpin = 3;

int ledPin = 13;

/////////////////////////////

//SETUP

void setup(){

Serial.begin(9600);

pinMode(piroutpin, INPUT);

pinMode(ledPin, OUTPUT);

digitalWrite(piroutpin, LOW);

Serial.print("calibrating sensor ");

for(int i = 0; i < calibrationTime; i++){

Serial.print(".");

delay(1000);

}

Serial.println(" done");

Serial.println("SENSOR ACTIVE");

delay(50);

}

////////////////////////////

//LOOP

void loop(){

if(digitalRead(piroutpin) == HIGH){

digitalWrite(ledPin, HIGH);

if(lockLow){

lockLow = false;

Serial.println("---");

Serial.print("motion detected at ");

Serial.print(millis()/1000);

Serial.println(" sec");

delay(50);

}

takeLowTime = true;

}

if(digitalRead(piroutpin) == LOW){

digitalWrite(ledPin, LOW);

if(takeLowTime){

lowIn = millis();

takeLowTime = false;

}

if(!lockLow && millis() - lowIn > pause){

lockLow = true;

Serial.print("motion ended at ");

Serial.print((millis() - pause)/1000);

Serial.println(" sec");

delay(50);

}

}

}