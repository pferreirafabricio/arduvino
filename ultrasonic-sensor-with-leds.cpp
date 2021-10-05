#define pinTrigger 9
#define pinEcho 10

const int ledsColors[] = { 7, 6, 5 };

const int red = ledsColors[0];
const int blue = ledsColors[1];
const int green = ledsColors[2];

int readDistance()
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  
  unsigned long echoTime = pulseIn(pinEcho, HIGH);
  
  return round(echoTime * 0.01717);
}

void setup()
{
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  for (int index = 0; index < 4; index++)
    pinMode(ledsColors[index], OUTPUT);
}

void loop()
{
  int distance = readDistance();
  
  digitalWrite(red, distance >= 0.1 && distance < 100 ? HIGH : LOW);
  digitalWrite(blue, distance >= 100 && distance < 200 ? HIGH : LOW);
  digitalWrite(green, distance >= 200 ? HIGH : LOW);
 
  delay(100);
}
