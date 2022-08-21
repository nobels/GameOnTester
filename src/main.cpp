#include <Arduino.h>
#include "OneButton.h"

#define GAMEON_UP 39
#define GAMEON_DOWN 15
#define GAMEON_LEFT 26
#define GAMEON_RIGHT 00
#define GAMEON_BUTTON 34
#define GAMEON_SELECT 36
#define GAMEON_START 32
#define GAMEON_A 13
#define GAMEON_B 12
#define GAMEON_SHOULDERLEFT 27
#define GAMEON_SHOULDERRIGHT 14

enum gebeurtenis { None, SingleClick, DoubleClick, TripleClick };

enum btn {A, B, Start, Select, Omhoog, Omlaag, Links, Rechts, Center, BovenLinks, BovenRechts};

inline const char* NaarText(btn v)
{
    switch (v)
    {
        case A:   return "A";
        case B:   return "B";
        case Start: return "Start";
        case Select:   return "Select";
        case Omhoog:   return "Omhoog";
        case Omlaag:   return "Omlaag";
        case Links:   return "Links";
        case Rechts:   return "Rechts";
        case Center:   return "Center";
        case BovenLinks:   return "BovenLinks";
        case BovenRechts:   return "BovenRechts";
        default:      return "[Unknown Button]";
    }
}

// Setup a new OneButton on each button.
OneButton button_a(GAMEON_A);
OneButton button_b(GAMEON_B);
OneButton button_select(GAMEON_SELECT);
OneButton button_start(GAMEON_START);
OneButton button_ShoulderLeft(GAMEON_SHOULDERLEFT);
OneButton button_shoulderRight(GAMEON_SHOULDERRIGHT);
OneButton button_Up(GAMEON_UP);
OneButton button_Down(GAMEON_DOWN);
OneButton button_Left(GAMEON_LEFT);
OneButton button_Right(GAMEON_RIGHT);
OneButton button_center(GAMEON_BUTTON);

// string convertToenum (int val)
// {
//     string MyStr(enum_string[val]);
//     return MyStr;
// }

void click(){
  Serial.println ( "→ Eenmalige klik gebeurtenis");
}// single click

// this function will be called when the button was pressed 2 times in a short timeframe.
void doubleclick() { //btn knop

  //Serial.println ( NaarText(knop) + "→ Dubbelklik gebeurtenis");
  Serial.println ( "→ Dubbelklik gebeurtenis");
} // doubleclick

void multiclick() {
  Serial.println ( "→ Multiklik gebeurtenis");
} // doubleclick

// setup code here, to run once:
void setup() {
  Serial.begin (9600);
    
    pinMode (GAMEON_A, INPUT_PULLUP);
    pinMode (GAMEON_B, INPUT_PULLUP);

//Todo: Verder uitzoeken waarom deze 2 knoppen (start/select) niet werken.
    //pinMode (GAMEON_SELECT, INPUT);  //→ NEGATIEF
    //pinMode (GAMEON_SELECT, INPUT_PULLDOWN);  //→ NEGATIEF
    //pinMode (GAMEON_SELECT, INPUT_PULLUP); //→ NEGATIEF

    pinMode (GAMEON_START, INPUT); //→ NEGATIEF
    //pinMode (GAMEON_START, INPUT_PULLDOWN); //→ NEGATIEF
    //pinMode (GAMEON_START, INPUT_PULLUP);
  

    pinMode (GAMEON_SHOULDERLEFT, INPUT_PULLUP);
    pinMode (GAMEON_SHOULDERRIGHT, INPUT_PULLUP);
    pinMode (GAMEON_UP, INPUT_PULLUP);
    pinMode (GAMEON_DOWN, INPUT_PULLUP);
    pinMode (GAMEON_LEFT, INPUT_PULLUP);
    pinMode (GAMEON_RIGHT, INPUT_PULLUP);
    pinMode (GAMEON_BUTTON, INPUT_PULLUP);
  
  // link the doubleclick function to be called on a doubleclick event.
  button_a.attachDoubleClick(doubleclick);
  button_a.attachClick(click);
  button_a.attachMultiClick(multiclick);

  button_b.attachDoubleClick(doubleclick);
  button_b.attachClick(click);
  button_b.attachMultiClick(multiclick);
  
  button_select.attachDoubleClick(doubleclick);
  button_select.attachClick(click);
  button_select.attachMultiClick(multiclick);
  

  button_start.attachDoubleClick(doubleclick);
  button_start.attachClick(click);
  button_start.attachMultiClick(multiclick);

  button_ShoulderLeft.attachDoubleClick(doubleclick);
  button_ShoulderLeft.attachClick(click);
  button_ShoulderLeft.attachMultiClick(multiclick);

  button_shoulderRight.attachDoubleClick(doubleclick);
  button_shoulderRight.attachClick(click);
  button_shoulderRight.attachMultiClick(multiclick);

  button_Up.attachDoubleClick(doubleclick);
  button_Up.attachClick(click);
  button_Up.attachMultiClick(multiclick);

  button_Down.attachDoubleClick(doubleclick);
  button_Down.attachClick(click);
  button_Down.attachMultiClick(multiclick);

  button_Left.attachDoubleClick(doubleclick);
  button_Left.attachClick(click);
  button_Left.attachMultiClick(multiclick);

  button_Right.attachDoubleClick(doubleclick);
  button_Right.attachClick(click);
  button_Right.attachMultiClick(multiclick);

  button_center.attachDoubleClick(doubleclick);
  button_center.attachClick(click);
  button_center.attachMultiClick(multiclick);

} // setup
  
// main code here, to run repeatedly: 
void loop() {
  // keep watching the push button_a:
  button_select.tick();
  button_start.tick();
  button_a.tick();
  button_b.tick();
  button_ShoulderLeft.tick();
  button_shoulderRight.tick();
  button_Up.tick();
  button_Down.tick();
  button_Left.tick();
  button_Right.tick();
  button_center.tick();


  // You can implement other code in here or just wait a while 
  delay(10);
} // loop