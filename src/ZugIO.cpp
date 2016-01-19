// ZugIO.cpp
#include <iostream>
#include "../inc/Zug.h"
Schienenfahrzeug eingabeSchienenfahrzeug() {
  unsigned int auswahl;
  Schienenfahrzeug fahrzeug;
  std::cout << "Eingabe eines Schienenfahrzeugs" << std::endl;
  std::cout << "Art des Schienenfahrzeugs: " << std::endl;
  std::cout << " [1] Triebfahrzeug" << std::endl;
  std::cout << " [2] Gueterwagen" << std::endl;
  std::cout << " [3] Personenwagen" << std::endl;
  std::cout << " [4] Bahndienstfahrzeug" << std::endl << "Eingabe: ";
  std::cin >> auswahl;
  int wert;

  switch (auswahl) {
  case 1:
    std::cout << "Nennantriebsleistung: ";
    std::cin >> fahrzeug.spezifischeDaten.triebfahrzeug.nennleistungPS;
    std::cout << "Traktionsart:" << std::endl;
    std::cout << " [0] Dampf" << std::endl;
    std::cout << " [1] Diesel" << std::endl;
    std::cout << " [2] Elektro" << std::endl << "Eingabe: ";
    std::cin >> wert;
    fahrzeug.spezifischeDaten.triebfahrzeug.antrieb = (Traktionsart)wert;
    break;

  case 2:
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

  case 3:
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

  case 4:
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
  return fahrzeug;
}
