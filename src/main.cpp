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

//enum naar text weergave (enum → string)
String NaarText(btn v)
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

// Maak een nieuwe OneButton voor elke knop.
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

// »»————-　Knop functies　————-««
void click(btn knop){
  Serial.println ( "Knop '"+ NaarText(knop) + "' → Eenmalige klik gebeurtenis");
}

// this function will be called when the button was pressed 2 times in a short timeframe.
void doubleclick(btn knop) { //btn knop
  //Serial.println ( NaarText(knop) + "→ Dubbelklik gebeurtenis");
  Serial.println ( "Knop '"+ NaarText(knop) + "' → Dubbelklik gebeurtenis");
}

void multiclick(btn knop) {
  Serial.println ( "Knop '"+ NaarText(knop) + "' →  Multiklik gebeurtenis");
}


// »»————-　setup code hier, om eenmaal te draaien　————-««
void setup() {
  //Serial output weergave
  Serial.begin (9600);
    
    pinMode (GAMEON_A, INPUT_PULLUP);
    pinMode (GAMEON_B, INPUT_PULLUP);

//Todo: Verder uitzoeken waarom deze 2 knoppen (start/select) niet werken.
    pinMode (GAMEON_SELECT, INPUT);  //→ NEGATIEF
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
  
// »»————-　Linken van het gedrag aan de knop + parrameter (knopnaam)　————-««
  button_a.attachClick([] { click(A); });
  button_a.attachDoubleClick([] { doubleclick(A); });
  button_a.attachMultiClick([] { multiclick(A); });
  
  button_b.attachClick([] { click(B); });
  button_b.attachDoubleClick([] { doubleclick(B); });
  button_b.attachMultiClick([] { multiclick(B); });
      
  button_select.attachClick([] { click(Select); });
  button_select.attachDoubleClick([] { doubleclick(Select); });
  button_select.attachMultiClick([] { multiclick(Select); });

  button_start.attachClick([] { click(Start); });
  button_start.attachDoubleClick([] { doubleclick(Start); });
  button_start.attachMultiClick([] { multiclick(Start); });

  button_ShoulderLeft.attachClick([] { click(BovenLinks); });
  button_ShoulderLeft.attachDoubleClick([] { doubleclick(BovenLinks); });
  button_ShoulderLeft.attachMultiClick([] { multiclick(BovenLinks); });

  button_shoulderRight.attachClick([] { click(BovenRechts); });
  button_shoulderRight.attachDoubleClick([] { doubleclick(BovenRechts); });
  button_shoulderRight.attachMultiClick([] { multiclick(BovenRechts); });

  button_Up.attachClick([] { click(Omhoog); });
  button_Up.attachDoubleClick([] { doubleclick(Omhoog); });
  button_Up.attachMultiClick([] { multiclick(Omhoog); });

  button_Down.attachClick([] { click(Omlaag); });
  button_Down.attachDoubleClick([] { doubleclick(Omlaag); });
  button_Down.attachMultiClick([] { multiclick(Omlaag); });

  button_Left.attachClick([] { click(Links); });
  button_Left.attachDoubleClick([] { doubleclick(Links); });
  button_Left.attachMultiClick([] { multiclick(Links); });
  
  button_Right.attachClick([] { click(Rechts); });
  button_Right.attachDoubleClick([] { doubleclick(Rechts); });
  button_Right.attachMultiClick([] { multiclick(Rechts); });
  
  button_center.attachClick([] { click(Center); });
  button_center.attachDoubleClick([] { doubleclick(Center); });
  button_center.attachMultiClick([] { multiclick(Center); });

} 
  
// »»————-　hoofdcode hier, om herhaaldelijk te draaien　————-««  
void loop() {
  // blijf de knoppen controleren
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
  // Je kunt hier andere code implementeren of gewoon even wachten 
  delay(10);
} 