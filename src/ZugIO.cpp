// ZugIO.cpp
#include <iostream>
#include "../inc/Zug.h"

////////////////////////////////////////////////////
// Eingabe eines Schienenfahrzeug über die Konsole
////////////////////////////////////////////////////

Schienenfahrzeug eingabeSchienenfahrzeug() {
  unsigned int auswahl;
  int wert;
  Schienenfahrzeug fahrzeug;
  std::cout << "Eingabe eines Schienenfahrzeugs" << std::endl;
  std::cout << "Art des Schienenfahrzeugs: " << std::endl;
  std::cout << " [0] Triebfahrzeug" << std::endl;
  std::cout << " [1] Gueterwagen" << std::endl;
  std::cout << " [2] Personenwagen" << std::endl;
  std::cout << " [3] Bahndienstfahrzeug" << std::endl << "Eingabe: ";
  std::cin >> auswahl;

  fahrzeug.ArtDesFahrzeugs = (Fahrzeugart)auswahl;

  switch (auswahl) {
  case TRIEBFAHRZEUG:
    std::cout << "Nennantriebsleistung: ";
    std::cin >> fahrzeug.spezifischeDaten.triebfahrzeug.nennleistungPS;
    std::cout << "Traktionsart:" << std::endl;
    std::cout << " [0] Dampf" << std::endl;
    std::cout << " [1] Diesel" << std::endl;
    std::cout << " [2] Elektro" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.triebfahrzeug.antrieb = (Traktionsart)wert;
    break;

  case GUETERWAGEN:
    std::cout << "Ladungsart: " << std::endl;
    std::cout << " [0] Schuettgut" << std::endl;
    std::cout << " [1] Stueckgut" << std::endl;
    std::cout << " [2] Fluessigkeiten" << std::endl;
    std::cout << " [3] Gefriergut" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.gueterwagen.ladungsart = (Ladungsart)wert;
    std::cout << "Gefahrgutklasse: ";
    std::cin >> fahrzeug.spezifischeDaten.gueterwagen.gefahrgutklasse;
    break;

  case PERSONENWAGEN:
    std::cout << "Sitzplaetze: ";
    std::cin >> fahrzeug.spezifischeDaten.personenwagen.sitzplaetze;
    std::cout << "Art des Decks: " << std::endl;
    std::cout << " [0] Normal" << std::endl;
    std::cout << " [1] Doppelstock" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.personenwagen.deck = (Decks)wert;
    std::cout << "Preisklassen:" << std::endl;
    std::cout << " [0] 1. Klasse" << std::endl;
    std::cout << " [1] 2. Klasse" << std::endl;
    std::cout << " [2] 1. und 2. Klasse" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.personenwagen.preisklassen = (Preisklassen)wert;
    std::cout << "Klimaanlage:" << std::endl;
    std::cout << " [0] Nein" << std::endl;
    std::cout << " [1] Ja" << std::endl << "Eingabe: ";
    std::cin >> fahrzeug.spezifischeDaten.personenwagen.klimaanlage;
    break;

  case BAHNDIENSTWAGEN:
    std::cout << "Art des Bahndienstfahrzeugs:" << std::endl;
    std::cout << " [0] Materialwagen" << std::endl;
    std::cout << " [1] Messwagen" << std::endl;
    std::cout << " [2] Kranwagen" << std::endl;
    std::cout << " [3] Schneeflug" << std::endl;
    std::cout << " [4] Werkstattwagen" << std::endl;
    std::cout << " [5] Gleisstopfmaschine" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.bahndienstwagen.wagenart = (Art)wert;
    break;
  }
  std::cout << "Anzahl der Achsen: ";
  std::cin >> fahrzeug.AnzahlAchsen;
  std::cout << "Laenge über den Puffer: ";
  std::cin >> fahrzeug.langeUeberPuffer;
  std::cout << "Leermasse: ";
  std::cin >> fahrzeug.leermasse;
  std::cout << "Maximale Fahrzeugmasse: ";
  std::cin >> fahrzeug.maxFahrzeugmasse;
  std::cout << "Kupplungsart: " << std::endl;
  std::cout << " [0] Hakenkupplung" << std::endl;
  std::cout << " [1] Mittelpufferkupplung" << std::endl << "Eingabe: ";
  std::cin >> wert;
  fahrzeug.kupplungsart = (Kupplungsart)wert;
  std::cout << "Zielbahnhof: ";
  std::cin >> fahrzeug.zielbahnhof;
  std::cout << "Heimatbahnbetriebswerk: ";
  std::cin >> fahrzeug.heimatbahnbetriebswerk;
  std::cout << std::endl;
  return fahrzeug;
}

///////////////////////////////////
// Ausgabe eines kompletten Zuges
///////////////////////////////////

// Hilfsfunktion zur Ausgabe eines Schienenfahrzeugs
static void ausgabeSchienenfahrzeug(Schienenfahrzeug fahrzeug) {
  std::cout << "Art des Schienenfahrzeugs: ";

  switch (fahrzeug.ArtDesFahrzeugs) {
  case TRIEBFAHRZEUG:
    std::cout << "Triebfahrzeug" << std::endl;
    std::cout << "Nennleistung: " <<
      fahrzeug.spezifischeDaten.triebfahrzeug.nennleistungPS << std::endl;
    std::cout << "Traktionsart: ";

    switch (fahrzeug.spezifischeDaten.triebfahrzeug.antrieb) {
    case DAMPF:
      std::cout << "Dampf" << std::endl;
      break;

    case DIESEL:
      std::cout << "Diesel" << std::endl;
      break;

    case ELEKTRO:
      std::cout << "Elektro" << std::endl;
      break;
    }
    break;

  case GUETERWAGEN:
    std::cout << "Gueterwagen" << std::endl;
    std::cout << "Ladungsart: ";

    switch (fahrzeug.spezifischeDaten.gueterwagen.ladungsart) {
    case SCHUETTGUT:
      std::cout << "Schuettgut" << std::endl;
      break;

    case STUECKGUT:
      std::cout << "Stueckgut" << std::endl;
      break;

    case FLUESSIGKEITEN:
      std::cout << "Fluessigkeiten" << std::endl;
      break;

    case GEFRIERGUT:
      std::cout << "Gefriergut" << std::endl;
      break;
    }
    std::cout << "Gefahrgutklasse: " <<
      fahrzeug.spezifischeDaten.gueterwagen.gefahrgutklasse << std::endl;
    break;

  case PERSONENWAGEN:
    std::cout << "Personenwagen" << std::endl;
    std::cout << "Sitzplaetze: " <<
      fahrzeug.spezifischeDaten.personenwagen.sitzplaetze << std::endl;
    std::cout << "Deckart: ";

    switch (fahrzeug.spezifischeDaten.personenwagen.deck) {
    case NORMAL:
      std::cout << "Normal" << std::endl;
      break;

    case DOPPELSTOCK:
      std::cout << "Doppelstock" << std::endl;
      break;
    }
    std::cout << "Preisklasse: ";

    switch (fahrzeug.spezifischeDaten.personenwagen.preisklassen) {
    case ersteKLASSE:
      std::cout << "1. Klasse" << std::endl;
      break;

    case zweiteKLASSE:
      std::cout << "2. Klasse" << std::endl;
      break;

    case erste_zweiteKLASSE:
      std::cout << "1. und 2. Klasse" << std::endl;
      break;
    }
    std::cout << "Klimaanlage: ";

    if (fahrzeug.spezifischeDaten.personenwagen.klimaanlage) std::cout << "Ja" <<
        std::endl;
    else  std::cout << "Nein" << std::endl;
    break;

  case BAHNDIENSTWAGEN:
    std::cout << "Bahndienstwagen" << std::endl;
    std::cout << "Art des Wagen: ";

    switch (fahrzeug.spezifischeDaten.bahndienstwagen.wagenart) {
    case MATERIALWAGEN:
      std::cout << "Materialwagen" << std::endl;
      break;

    case MESSWAGEN:
      std::cout << "Messwagen" << std::endl;
      break;

    case KRANWAGEN:
      std::cout << "Kranwagen" << std::endl;
      break;

    case SCHNEEFLUG:
      std::cout << "Schneeflug" << std::endl;
      break;

    case WERKSTATTWAGEN:
      std::cout << "Werkstattwagen" << std::endl;
      break;

    case GLEISSTOPFMASCHINE:
      std::cout << "Gleisstopfmaschine" << std::endl;
      break;
    }
    break;
  }
  std::cout << "Anzahl der Achsen: " << fahrzeug.AnzahlAchsen << std::endl;
  std::cout << "Laenge ueber Puffer: " << fahrzeug.langeUeberPuffer << std::endl;
  std::cout << "Leermasse: " << fahrzeug.leermasse << std::endl;
  std::cout << "Maximale Fahrzeugmasse: " << fahrzeug.maxFahrzeugmasse <<
    std::endl;
  std::cout << "Kupplungsart: ";

  switch (fahrzeug.kupplungsart) {
  case HAKENKUPPLUNG:
    std::cout << "Hakenkupplung" << std::endl;
    break;

  case MITTELPUFFERKUPPLUNG:
    std::cout << "Mittelpufferkupplung" << std::endl;
    break;
  }
  std::cout << "Zielbahnhof: " << fahrzeug.zielbahnhof << std::endl;
  std::cout << "Heimatbahnbetriebswerk: " << fahrzeug.heimatbahnbetriebswerk <<
    std::endl;
}

void ausgabeZug(Zug *zug) {
  // Test ob ein Wagen in der Zug-Liste vorhanden ist
  if (zug->first != nullptr) {
    Wagen *current     = zug->first;
    int    WagenNummer = 1;

    while (current != nullptr) {
      std::cout << "Wagennummer: " << WagenNummer << std::endl;
      WagenNummer++;
      ausgabeSchienenfahrzeug(current->fahrzeug);
      std::cout << std::endl;
      current = current->next;
    }
  }

  // Ausgabe wenn kein Wagon vorhanden ist
  else std::cerr << "Keine Wagen vorhanden!" << std::endl;
}
