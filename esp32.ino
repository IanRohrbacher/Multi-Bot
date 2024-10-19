int orangeLivePin = 32; // GIOP32
int yellowLivePin = 33; // GIOP33
int greenLivePin = 25; // GIOP25
int blueLivePin = 26; // GIOP26
int purpleLivePin = 27; // GIOP27
int greenPin = 16; // GIOP16
int yellowPin = 17; // GIOP17
int orangePin = 5; // GIOP5
int bluePin = 18; // GIOP18
int purplePin = 19; // GIOP19

int switchPin = 35; // GIOP35

int pwmPins[] = {orangeLivePin, yellowLivePin, greenLivePin, blueLivePin, purpleLivePin, greenPin, yellowPin, orangePin, bluePin, purplePin};


void setup() {
  Serial.begin(115200);
  while(!Serial){}

  pinMode(switchPin, INPUT);
  for(int pin : pwmPins) {
    pinMode(pin, OUTPUT);
  }
  for(int pin : pwmPins) {
    analogWrite(pin, (255*3.3)/5);
  }

  while(switchState()) { // needs to return false to move on
      Serial.println("waiting on switch");
      
  }
}

void loop() {
  Serial.println("loop");
  Serial.println(switchState());
  delay(3000);
}

bool switchState() {
  return (digitalRead(switchPin) == HIGH);
}