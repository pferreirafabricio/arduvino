#define LEDS_QUANTITY 4
#define ANALOGIC_VALUE 1023

int leds[4] = { 2, 3, 4, 5 };
int powerByLed = ANALOGIC_VALUE / LEDS_QUANTITY;

void setup()
{
  for (int index = 0; index < 5; index++)
  	pinMode(leds[index], OUTPUT);
}

void loop()
{
  int analogicPort = analogRead(A0);
  
  for (int index = 0; index < 5; index++)
  	digitalWrite(
    	leds[index],
    	(analogicPort >= powerByLed * index + 1) ? HIGH : LOW
  	);
}
