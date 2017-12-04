// Wyznaczanie maksymalnego PS.
// Data:  1.06.2008
// (C)2012 mgr Jerzy Wa³aszek
//------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  string s;
  int PI[41],i,b;

  srand((unsigned)time(NULL));

  // generujemy ³añcuch

  s = "";
  for(i = 0; i < 40; i++) s += 65 + rand() % 2;

  // wypisujemy ³añcuch

  cout << s << endl;

  // szukamy prefikso-sufiksu

  PI[0] = b = -1;
  for(i = 1; i <= 40; i++)
  {
    while((b > -1) && (s[b] != s[i - 1])) b = PI[b];
    PI[i] = ++b;
  }
  cout << b << endl << endl;
  return 0;
}


