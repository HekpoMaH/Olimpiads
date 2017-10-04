#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;

ULL K;

int A, B, P;

bool used[30000000];

int main()
{
 cin >> A >> B;
 cin >> K >> P;
 
 if (K <= 10000000)
 {
  int curl = A * 10;
  for (int i = 1; i < K; i++) curl = (curl % B) * 10;
  for (int i = 1; i <= P; i++) { cout << curl / B; curl = (curl % B) * 10; }
  cout << endl;
  return 0;
 } 
 else
 { 
  int curl = A * 10, savest = 0, saveen = 0, r = -1, saver = -1, q = -1;
 
  for (int i = 1; ;i++)
  {
   r = curl % B; 
   if (used[r]) { q = curl; saver = r; saveen = i - 1; break; } else 
                                                                used[r] = true;
   curl = r * 10;
  }
  
  curl = A * 10;
  
  for (int i = 1; ;i++)
  {
   r = curl % B; curl = r * 10;
   if (r == saver) { savest = i; break; }
  }
    
  K -= (savest - 1);
  
  int len = saveen - savest + 1;
  
  int ost = K % len;
  
  if (!ost) ost = len;
  
  curl = q;
  for (int i = 1; i < ost; i++) curl = (curl % B) * 10; 
  for (int i = 1; i <= P; i++) { cout << curl / B; curl = (curl % B) * 10; }
  
  cout << endl;
 } 
 
 return 0;
}
