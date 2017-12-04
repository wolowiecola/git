// Wyszukiwanie wzorca algorytmem MP.
// Data:  3.06.2008
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 80;  // d³ugoœæ ³añcucha s
const int M =  5;  // d³ugoœæ wzorca p

int main()
{
  string s,p;
  int PI[M + 1],i,b,pp;

  srand((unsigned)time(NULL));

  // generujemy ³añcuch s

  s = "";
  for(i = 0; i < N; i++) s += 65 + rand() % 2;

  // generujemy wzorzec

  p = "";
  for(i = 0; i < M; i++) p += 65 + rand() % 2;

  // dla wzorca obliczamy tablicê PI[]

  PI[0] = b = -1;
  for(i = 1; i <= M; i++)
  {
    while((b > -1) && (p[b] != p[i - 1])) b = PI[b];
    PI[i] = ++b;
  }

  // wypisujemy wzorzec

  cout << p << endl;

  // wypisujemy ³añcuch s

  cout << s;

  // poszukujemy pozycji wzorca w ³añcuchu

  pp = b = 0;
  for(i = 0; i < N; i++)
  {
    while((b > -1) && (p[b] != s[i])) b = PI[b];
    if(++b == M)
    {
      while(pp < i - b + 1)
      {
        cout << " "; pp++;
      }
      cout << "^"; pp++;
      b = PI[b];
    }
  }
  cout << endl;
  return 0;
}

