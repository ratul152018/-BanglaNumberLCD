/*
*     Arduino skech for printing Bangla character in LCD
*     Created by Md. Raisul Alam Ratul 
*     Email: ratul152018@gmail.com
*/

#include <LiquidCrystal.h> // importing library for lcd

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // creating a lcd object

/*******************************  Creating the design of Bangla digits  *******************************/

byte one[8]={
  B10000,
  B11111,
  B00001,
  B00001,
  B11001,
  B11001,
  B11111
};

byte two[8]={
  B10000,
  B11111,
  B00001,
  B00001,
  B11111,
  B10000,
  B11111
};

byte three[8]={
  B01111,
  B01101,
  B00001,
  B10001,
  B10001,
  B10001,
  B11111
};


byte five[8]={
  B10010,
  B11110,
  B10010,
  B10011,
  B10001,
  B10001,
  B11111
};

byte six[8]={
  B10100,
  B10100,
  B10100,
  B10111,
  B10001,
  B10001,
  B11111
};

byte seven[8]={
  B11111,
  B10001,
  B10001,
  B11111,
  B00001,
  B00001,
  B00001
};

byte eight[8]={
  B10000,
  B10001,
  B10110,
  B11111,
  B10001,
  B10001,
  B11111
};

byte nine[8]={
  B10000,
  B11111,
  B00001,
  B00001,
  B11111,
  B11001,
  B11001
};


void setup() {
  lcd.begin(16, 2);
  
  lcd.createChar(1,one);  
  lcd.createChar(2,two);
  lcd.createChar(3,three);
  lcd.createChar(5,five);
  lcd.createChar(6,six);
  lcd.createChar(7,seven);
  lcd.createChar(8,eight);
  lcd.createChar(4,nine); // don't worry. only 8 custom character can be created. So I used 'O' as Bangla zero and '8' as Bangla four. In the place of four I used to create Bangla nine. You don't need to think.

  lcd.setCursor(0,0);
  lcd.print(" BANGLA DIGITS ");
  lcd.setCursor(0,1);
  lcd.print("    BY RATUL");
  delay(4000);
  lcd.clear();
  
  int value= 1952;
  lcd.setCursor(0,0);
  BanglaNumber(value); // Call this function to print BanglaNumber. It takes int type  as input.
}

void loop() {
  // loop is empty in this case
}

void BanglaDigit(int digit){  // function for printing a single Bangla digit
  if(digit==0)lcd.print("O");
  else if (digit==4)lcd.print("8");
  else if (digit==9)lcd.write(4);
  else{
      for(int i = 1;i<=8;i++){
        if(digit==i){
          lcd.write(i);
          break;
        }
    }
  }
}

void BanglaNumber(int num){  // it is the main function for Bangla number printing
  int temp;
  int c=0;
  int store=0;
  if (num<0){
    lcd.print("-");
    num=num*-1; 
  }
  while(num!=0){
    temp=num%10;
    num=num/10;
    store=(store*10)+temp;
    c++;
  }
  while(c>0){
    temp=store%10;
    store=store/10;
    BanglaDigit(temp);
    c--;
  }
}
