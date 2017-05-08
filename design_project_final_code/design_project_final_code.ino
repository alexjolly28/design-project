#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int hour = 0;
int mint = 0;
int sec = 0;
int relay = 10;
int s = 0;
int m = 0;
int f = 0;
int k = 0;
int l = 0;
int a = 0;
int b = 0;
int c = 0;
int q = 0;
int x = 0;
int y = 0;
int z = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(relay, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  lcd.clear();
  lcd.print("TIME::");
  lcd.setCursor(6, 0);
  lcd.print("00:");
  lcd.setCursor(9, 0);
  lcd.print("00:");
  lcd.setCursor(12, 0);
  lcd.print("00");
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  lcd.setCursor(10, 1);
  lcd.print("START");

}

void loop()
{
  if (q == 0)
  {
    s = digitalRead(8);
    m = digitalRead(9);
    a = digitalRead(6);
  }

  f = digitalRead(7);

  delay(100);

  if (s == HIGH)
  {
    secf();
  }

  else if (m == HIGH)
  {
    mintf();
  }
  else if (f == HIGH)
  {
    fun();
  }
  else if (a == HIGH)
  {
    fun1();
  }
}

void start()
{

  lcd.setCursor(6, 0);
  lcd.print(hour);
  lcd.setCursor(8, 0);
  lcd.print(":");

  if (mint < 10)
  {
    lcd.setCursor(10, 0);
    lcd.print(mint);
  }
  else
  {
    lcd.setCursor(9, 0);
    lcd.print(mint);
  }

  lcd.setCursor(11, 0);
  lcd.print(":");

  if (sec < 10)
  {
    lcd.setCursor(13, 0);
    lcd.print(sec);
  }
  else
  {
    lcd.setCursor(12, 0);
    lcd.print(sec);
  }
  {
    if (y == 1)
    {
      lcd.setCursor(0, 1);
      lcd.print("ON");
      c = 0;
      z = 1;
    }
    else if (y == 0)
    {
      lcd.setCursor(0, 1);
      lcd.print("OFF");
      c = 1;
      z = 0;
    }
  }

  if (x == 0)
  {
    lcd.setCursor(10, 1);
    lcd.print("START");
  }

  else if (x == 1)
  {
    lcd.setCursor(10, 1);
    lcd.print("STOP");

    out();

  }

}

void secf()
{
  s = digitalRead(8);

  if (s == LOW)
  {
    sec++;
    if (sec == 60)
    {
      sec = 0;
      lcd.setCursor(12, 0);
      lcd.print("00");
    }
    if ( sec < 10)
    {
      lcd.setCursor(13, 0);
      lcd.print(sec);
    }
    else
    {
      lcd.setCursor(12, 0);
      lcd.print(sec);
    }

  }
}
void mintf()
{
  m = digitalRead(9);

  if (m == LOW)
  {
    mint++;
    if (mint == 60)
    {
      mint = 0;
      lcd.setCursor(9, 0);
      lcd.print("00");
    }
    if (mint < 10)
    {
      lcd.setCursor(10, 0);
      lcd.print(mint);
    }
    else
    {
      lcd.setCursor(9, 0);
      lcd.print(mint);
    }

  }
}


void fun()
{
  f = digitalRead(7);

  if (f == LOW)
  {
    if (k == 0)
    {
      l = 1;
      k = 1;
    }
    if (l == 0)
    {
      x = 0;

      lcd.clear();
      screen();

      sec = 0;
      mint = 0;
      start();
      lcd.setCursor(10, 1);
      lcd.print("START");
      l = 1;
      q = 0;

    }
    else if (l == 1)
    {
      x = 1;
      l = 0;
      q = 1;

      lcd.clear();
      screen();
      start();
    }
  }
}

void fun1()
{
  a = digitalRead(6);

  if (a == LOW)
  {
    if (b == 0)
    {
      c = 1;
      b = 1;
    }

    if (c == 1)
    {
      y = 1;
      lcd.clear();
      screen();
      start();
      lcd.setCursor(0, 1);
      lcd.print("ON");
      c = 0;
      digitalWrite(relay, LOW);


    }
    else if (c == 0)
    {
      y = 0;
      start();
      lcd.setCursor(0, 1);
      lcd.print("OFF");
      digitalWrite(relay, LOW);
      c = 1;
    }

  }
}

void screen()
{
  lcd.print("TIME::");
  lcd.setCursor(6, 0);
  lcd.print("00:");
  lcd.setCursor(9, 0);
  lcd.print("00:");
  lcd.setCursor(12, 0);
  lcd.print("00");
  lcd.setCursor(0, 1);

}

void out()
{
  while (sec >= 0)
  {
    if (z == 0)
    {
      digitalWrite(relay, HIGH);

    }
    else
    {
      digitalWrite(relay, LOW);
    }
    f = digitalRead(7);

    if (f == HIGH)
    {
      digitalWrite(relay, LOW);

      break;
    }
    if (mint < 10)
    {
      lcd.setCursor(10, 0);
      lcd.print(mint);

    }
    else
    {
      lcd.setCursor(9, 0);
      lcd.print(mint);
    }
    if (sec >= 0)
    {

      delay(1000);

      if (sec < 10)
      {

        lcd.setCursor(12, 0);
        lcd.print("0");
        lcd.setCursor(13, 0);
        lcd.print(sec);

      }
      else
      {

        lcd.setCursor(12, 0);
        lcd.print(sec);
      }


      if (sec == 0)
      {
        if (mint == 0 && sec == 0)
        {
          x = 0;
          if (z == 0)
          {
            digitalWrite(relay, LOW);
          }
          else
          {
            digitalWrite(relay, HIGH);

          }
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("TASK COMPLETED..");

          delay(2000);

          lcd.clear();

          screen();

          sec = 0;
          mint = 0;
          start();
          lcd.setCursor(10, 1);
          lcd.print("START");
          l = 1;
          q = 0;
        }
        else
        {

          if (mint < 10)
          {
            lcd.setCursor(10, 0);
            lcd.print(mint);

          }
          else
          {
            lcd.setCursor(9, 0);
            lcd.print(mint);
          }
          sec = 60;
          mint--;
        }
      }
      sec--;
    }
  }
}


