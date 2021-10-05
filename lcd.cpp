#include<LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define inc(value, limit) { value = (value + 1) % limit; }

String names[10] =
{
  "Fabio",
  "Pedro",
  "Davi",
  "Joao",
  "Roberto",
  "Ana",
  "Beatriz",
  "Lucas",
  "Joaquim",
  "Carlos"
};

int currentIndex = 0;
int arrayNamesLength = sizeof(names)/sizeof(names[0]);

void setup()
{
  lcd.begin(16, 2); 
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);          
  lcd.print(names[currentIndex]); 
  lcd.setCursor(0,1);
  
  // Increment
  // inc(currentIndex, arrayNamesLength);
  // Or
  // currentIndex = (currentIndex + 1) % arrayNamesLength;
  
  // Decrement
  currentIndex = (currentIndex + arrayNamesLength - 1) % arrayNamesLength;
  
  // Another way
  // currentIndex++;
  // if (currentIndex >= arrayNamesLength)
  // 	currentIndex = 0;

  lcd.print(names[currentIndex]);  
  delay(1000);
}
