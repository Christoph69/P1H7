#ifndef SCHIENENFAHRZEUG_H
#define SCHIENENFAHRZEUG_H

const unsigned int MAX_NAMENSLAENGE = 60;

enum Traktionsart { DAMPF, DIESEL, ELEKTRO };
enum Ladungsart { SCHUETTGUT, STUECKGUT, FLUESSIGKEITEN, GEFRIERGUT };
enum Decks { NORMAL, DOPPELSTOCK };
enum Preisklassen { ersteKLASSE, zweiteKLASSE, erste_zweiteKLASSE };
enum Art { MATERIALWAGEN, MESSWAGEN, KRANWAGEN, SCHNEEFLUG, WERKSTATTWAGEN,
           GLEISSTOPFMASCHINE };
enum Kupplungsart { HAKENKUPPLUNG, MITTELPUFFERKUPPLUNG };

struct Triebfahrzeuge {
  unsigned int nennleistungPS;
  Traktionsart antrieb;
};

struct Gueterwagen {
  Ladungsart   ladungsart;
  unsigned int gefahrgutklasse;
};

struct Personenwagen {
  unsigned int sitzplaetze;
  Decks        deck;
  Preisklassen preisklassen;
  bool         klimaanlage;
};

struct Bahndienstfahrzeuge {
  Art wagenart;
};

//////////////////////////////////////
// Hauptstruct für Schienenfahrzeuge
//////////////////////////////////////

struct Schienenfahrzeug {
  union {
    Triebfahrzeuge      triebfahrzeug;
    Gueterwagen         gueterwagen;
    Personenwagen       personenwagen;
    Bahndienstfahrzeuge bahndienstwagen;
  }            spezifischeDaten;
  unsigned int AnzahlAchsen;
  float        langeUeberPuffer;
  float        leermasse;
  float        maxFahrzeugmasse;
  Kupplungsart kupplungsart;
  char         zielbahnhof[MAX_NAMENSLAENGE];
  char         heimatbahnbetriebswerk[MAX_NAMENSLAENGE];
};


#endif /* ifndef SCHIENENFAHRZEUG_H */
