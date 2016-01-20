// main.cpp zu P1H7
#include "../inc/Zug.h"
#include "../inc/ZugIO.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Schienenfahrzeug test;
  Zug zugtest;

  test = eingabeSchienenfahrzeug();
  ankuppeln(&zugtest, test, VORN);
  ausgabeZug(&zugtest);

  return 0;
}
