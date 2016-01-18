// Zug.cpp

#include "../inc/Zug.h"

////////////////////
// Hilfsfunktionen
////////////////////

static Wagen* erstelleWagen(Schienenfahrzeug fahrzeug) {
  Wagen *pWagen = new Wagen;

  if (pWagen == nullptr) return nullptr;

  pWagen->fahrzeug = fahrzeug;
  pWagen->next     = nullptr;
  pWagen->prev     = nullptr;
  return pWagen;
}

///////////////////////////
// Funktionen für den Zug
///////////////////////////

void initialisiereZug(Zug *zug) {
  zug->first = nullptr;
  zug->last  = nullptr;
}

void verschrotteZug(Zug *zug) {
  while (zug->first != nullptr) {
    Wagen *next = zug->first->next;
    delete zug->first;
    zug->first = next;
  }
  zug->last = nullptr;
}

unsigned int achsanzahl(Zug *zug) {
  unsigned int achsanzahl = 0;
  Wagen *next             = zug->first;

  while (next != nullptr) {
    achsanzahl += next->fahrzeug.AnzahlAchsen;
    next        = next->next;
  }
  return achsanzahl;
}

int triebfahrzeugposition(Zug *zug, int  position) {
  Wagen *current = zug->first;

  for (int i = 1; i < position; i++) {
    if (current == nullptr) return 0;

    current = current->next;
  }

  while (current != nullptr) {
    if (current->fahrzeug.spezifischeDaten.triebfahrzeug.nennleistungPS >
        0) return position;

    position++;
    current = current->next;
  }
  return 0;
}

bool ankuppeln(Zug *zug, Schienenfahrzeug fahrzeug, Position pos) {
  // Prüfen ob die Kupplungenart die gleiche ist
  if (zug->first->fahrzeug.kupplungsart != fahrzeug.kupplungsart) return false;

  Wagen *pWagen = erstelleWagen(fahrzeug);

  if (pWagen == nullptr) return false;

  // Zug noch leer
  if (zug->first == nullptr) {
    zug->first = pWagen;
    zug->last  = pWagen;
    return true;
  }

  // mind. ein Zug vorhanden
  // vorne einkoppeln
  if (pos == 0) {
    pWagen->next     = zug->first;
    zug->first->prev = pWagen;
    zug->first       = pWagen;
    return true;
  }

  // hinten einkoppeln
  if (pos == 1) {
    pWagen->prev    = zug->last;
    zug->last->next = pWagen;
    zug->last       = pWagen;
    return true;
  }
  return false;
}

bool abkuppeln(Zug *zug, Schienenfahrzeug *fahrzeug, Position pos) {
  // prüfen ob ein Wagen vorhanden ist
  if (zug->first == nullptr) return false;

  // vorne entkoppeln
  if (pos == 0) {
    *fahrzeug = zug->first->fahrzeug;
    Wagen *next = zug->first->next;
    delete zug->first;
    zug->first = next;

    if (next == nullptr) zug->last = nullptr;
    else next->prev = nullptr;
    return true;
  }

  // hinten entkoppeln
  if (pos == 1) {
    *fahrzeug = zug->last->fahrzeug;
    Wagen *prev = zug->last->prev;
    delete zug->last;
    zug->last = prev;

    if (prev == nullptr) zug->first = nullptr;
    else prev->next = nullptr;
    return true;
  }
  return false;
}
