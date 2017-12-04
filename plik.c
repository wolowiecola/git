// Algorytm WWN
// Data:   29.05.2008
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  string s,p;
  int i;

  srand((unsigned)time(NULL));

  // generujemy �a�cuch

  s = "";
  for(i = 0; i < 80; i++) s += char(65 + (rand() % 3));

  // generujemy wzorzec

  p = "";
  for(i = 0; i < 3; i++) p += char(65 + (rand() % 3));

  // wypisujemy wzorzec

  cout << p << endl;

  // wypisujemy �a�cuch

  cout << s;

  // szukamy wzorca w �a�cuchu

  for(i = 0; i < 78; i++)
    cout << (p == s.substr(i,3) ? "^" : " ");

  cout << endl << endl;
  return 0;
}

