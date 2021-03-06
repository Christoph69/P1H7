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
    if (current->fahrzeug.ArtDesFahrzeugs == 0) return position;

    position++;
    current = current->next;
  }
  return 0;
}

bool ankuppeln(Zug *zug, Schienenfahrzeug fahrzeug, Position pos) {
  // Zug noch leer
  if (zug->first == nullptr) {
    Wagen *pWagen = erstelleWagen(fahrzeug);

    // es konnte kein neuer Wagen auf dem Heap erstellt werden
    if (pWagen == nullptr) return false;

    zug->first = pWagen;
    zug->last  = pWagen;
    return true;
  }

  // Prüfen ob die Kupplungenart die gleiche ist, wen nicht abbruch
  if (zug->first->fahrzeug.kupplungsart != fahrzeug.kupplungsart) return false;

  // beschaffen des Speichers für den neuen Wagen
  Wagen *pWagen = erstelleWagen(fahrzeug);

  // es konnte kein neuer Wagen auf dem Heap erstellt werden
  if (pWagen == nullptr) return false;

  // mind. ein Zug vorhanden
  // vorne einkoppeln
  if (pos == VORN) {
    pWagen->next     = zug->first;
    zug->first->prev = pWagen;
    zug->first       = pWagen;
    return true;
  }

  // hinten einkoppeln
  if (pos == HINTEN) {
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
  if (pos == VORN) {
    *fahrzeug = zug->first->fahrzeug;

    if (zug->first->next != nullptr) {
      zug->first = zug->first->next;
      delete zug->first->prev;
      zug->first->prev = nullptr;
    }
    else {
      // wenn nach dem abkoppeln kein Wagen mehr vorhanden ist
      delete zug->first;
      initialisiereZug(zug);
    }
    return true;
  }

  // hinten entkoppeln
  if (pos == HINTEN) {
    *fahrzeug = zug->last->fahrzeug;

    if (zug->last->prev != nullptr) {
      zug->last = zug->last->prev;
      delete zug->last->next;
      zug->last->next = nullptr;
    }
    else {
      delete zug->last;
      initialisiereZug(zug);
    }
    return true;
  }
  return false;
}

bool trennen(Zug *zug1, Zug *zug2, int  nachPos) {
  if (zug1->first == nullptr) return false;

  Wagen *current = zug1->first;

  for (int i = 1; i < nachPos; i++) {
    if (current == nullptr) return false;

    current = current->next;
  }

  // testen ob nach der Position des letzen Wagen des ersten Zuges noch ein
  // Wagen folgt
  if (current->next == nullptr) return false;

  zug2->first       = current->next;
  zug2->last        = zug1->last;
  zug1->last        = current;
  current->next     = nullptr;
  zug2->first->prev = nullptr;
  return true;
}

bool verbinden(Zug *zug1, Zug *zug2) {
  // Test ob in beiden Zügen mind. ein Wagen vorhanden ist
  if ((zug1->first == nullptr) || (zug2->first == nullptr)) return false;

  // Test ob die Kupplungsart übereinstimmt
  if (zug1->first->fahrzeug.kupplungsart !=
      zug2->first->fahrzeug.kupplungsart) return false;

  zug1->last->next  = zug2->first;
  zug2->first->prev = zug1->last;
  zug1->last        = zug2->last;
  initialisiereZug(zug2);
  return true;
}
