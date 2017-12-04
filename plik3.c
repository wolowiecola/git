// Wyznaczanie maksymalnego PS
// Data:   1.06.2008
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  string s;
  int i,n;

  srand((unsigned)time(NULL));

  // generujemy �a�cuch

  s = "";
  for(i = 0; i < 40; i++) s += 65 + rand() % 2;

  // wypisujemy �a�cuch

  cout << s << endl;

  // szukamy prefikso-sufiksu

  n = s.length();
  for(i = n - 1; i > 0; i--) if(s.substr(0,i) == s.substr(n - i,i)) break;
  cout << i << endl << endl;
  return 0;
}


