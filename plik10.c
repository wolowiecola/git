// Wyszukiwanie wzorca pe³nym algorytmem BM
// Data:  10.06.2008
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N  = 80;  // d³ugoœæ ³añcucha s
const int M  =  5;  // d³ugoœæ wzorca p
const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 66;  // kod ostatniego znaku alfabetu

int main()
{
  string s,p;
  int Last[zk-zp + 1],BMNext[M+1],Pi[M+1],b,i,j,pp;

  srand((unsigned)time(NULL));

// generujemy ³añcuch s

  s = "";
  for(i = 0; i < N; i++)
    s += zp + rand() % (zk - zp + 1);

// generujemy wzorzec p

  p = "";
  for(i = 0; i < M; i++)
    p += zp + rand() % (zk - zp + 1);

// wypisujemy wzorzec

  cout << p << endl;

// wypisujemy ³añcuch

  cout << s;

// dla wzorca obliczamy tablicê Last[]

  for(i = 0; i <= zk - zp; i++) Last[i] = -1;
  for(i = 0; i < M; i++) Last[p[i] - zp] = i;

// Etap I obliczania tablicy BMNext[]

  for(i = 0; i <= M; i++) BMNext[i] = 0;
  i = M; b = M + 1; Pi[i] = b;
  while(i > 0)
  {
    while((b <= M) && (p[i - 1] != p[b - 1]))
    {
      if(BMNext[b] == 0) BMNext[b] = b - i;
      b = Pi[b];
    }
    Pi[--i] = --b;
  }

// Etap II obliczania tablicy BMNext[]

  b = Pi[0];
  for(i = 0; i <= M; i++)
  {
    if(BMNext[i] == 0) BMNext[i] = b;
    if(i == b) b = Pi[b];
  }

// szukamy pozycji wzorca w ³añcuchu

  pp = i = 0;
  while(i <= N - M)
  {
    j = M - 1;
    while((j > -1) && (p[j] == s[i + j])) j--;
    if(j == -1)
    {
      while(pp < i)
      {
        cout << " "; pp++;
      }
      cout << "^"; pp++;
      i += BMNext[0];
    }
    else i += max(BMNext[j+1],j-Last[s[i+j]-zp]);
  }
  cout << endl;
  return 0;
}
