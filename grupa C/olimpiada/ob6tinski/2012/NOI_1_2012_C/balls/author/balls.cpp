#include<iostream>
using namespace std;

long long int n,k;
long long int a[101];


int main()
{
  cin >> n >> k;
  int p=-1;
  for(int i=1;i<=k;i++) 
   {
     long long int t; 
     cin >> t;
     bool b=false;
     for(int j=0;j<=p;j++) if(a[j]==t) {b=true; break;}
     if(b) continue;
     p++;
     a[p]=t;
   }
   p++;
   cout << n-p << endl;    
}

