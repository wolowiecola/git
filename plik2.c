// Algorytm WWN z wartownikami
// Data:   30.05.2008
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  string s,p;
  int i,j;

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

  // dodajemy wartownik�w

  s += "X"; p += "Y";

  // szukamy wzorca w �a�cuchu

  for(i = 0; i < 78; i++)
  {
    for(j = 0; s[i + j] == p[j]; j++) ;
    cout << (j == 3 ? "^" : " ");
  }

  cout << endl << endl;
  return 0;
}

