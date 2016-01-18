#ifndef ZUG_H
#define ZUG_H
#include "Schienenfahrzeug.h"

enum Position { VORN, HINTEN };

////////////////////////////////////////////////
// doppelt verkettete List für Schienfahrzeuge
////////////////////////////////////////////////

struct Wagen {
  Schienenfahrzeug fahrzeug;
  Wagen           *next;
  Wagen           *prev;
};

struct Zug {
  Wagen *first;
  Wagen *last;
};

////////////////////////////////////////
// Funktionen für den Umgang mit 'Zug'
////////////////////////////////////////

// setzt bei einem erstelltem Zug die Pointer auf 'nullptr'
void initialisiereZug(Zug *zug);

// Kuppelt einen Wagen entweder vorn oder hinten ein, aber es dürfen nur
// Fahrzeuge mit der gleichen Kupplung zusammen geführt werden. Nur wenn dies
// erfüllt ist gibt die Funktion true zurück.
bool ankuppeln(Zug             *zug,      // Liste in welche der Wagen
                                          // eingehängt werden soll
               Schienenfahrzeug fahrzeug, // der Wagen welcher hinzugefügt wird
               Position         pos);     // wo eingehängt wird, 0=vorn,
                                          // 1=hinten

// Koppelt einen Wagen ab und speichert ihn in die angegebene Variable, sollte
// die Liste leer sein, also kein Zug vorhanden so wird 'false' zurückgeben.
bool abkuppeln(Zug              *zug,      // Liste wo ein Wagen entnommen
                                           // werden soll
               Schienenfahrzeug *fahrzeug, // Variable in welche der entkoppelte
                                           // Wagen gespeichert wird
               Position          pos);     // wo soll dieser Wagen entnommen
                                           // werden: 0=vorn, 1=hinten

// trennt einen Zug nach einem bestimmten Wagen ab, der hintere Teil bildet dann
// einen neuen Zug welcher der Funktion auch übergeben werden muss. Sollte der
// Zug nicht getrennt werden können, so gibt die Funktion ein 'false' zurück.
bool trennen(Zug *zug1,     // Liste des kompletten Zuges
             Zug *zug2,     // Liste in welche der hintere Teil des Zuges
                            // eingehangen wird. Dies sollte ein leerere Zug
                            // sein.
             int  nachPos); // hinter welchem Wagen soll der Zug getrennt werden

// verbindet zwei Züge miteinander, wo der zweite Zug an den ersten angehangen
// wird und der zweite Zug dann als leerer Zug gibt. Sollte dies nicht gelingen
// so wird 'false' zurückgeben.
bool verbinden(Zug *zug1,
               Zug *zug2);

// berechnet die Gesamtanzahl aller Achsen im Zug und gibt diese zurück.
unsigned int achsanzahl(Zug *zug);

// gibt die Postion des nächsten Triebfahrzeuges im Zug ab einschließlich einer
// vorgegebenen Fahrzeugnummer zurück. Sollte kein weiteres Triebfahrzeug
// vorhanden sein so wird '0' zurückgeben, da dies keine zulässige
// Fahrzeugnummer ist.
int triebfahrzeugposition(Zug *zug,
                          int  position); // Position ab welcher gesucht werden
                                          // soll

// verschrottet einen Zug und macht ihn zu einen leeren Zug, alle Wagen dabei
// aus dem Speicher gelöscht.
void verschrotteZug(Zug *zug);

#endif /* ifndef ZUG_H */
