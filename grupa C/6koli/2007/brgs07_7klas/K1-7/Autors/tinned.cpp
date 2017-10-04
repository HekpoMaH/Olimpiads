#include <iostream>
#include <string>
using namespace std;

const int MAXNUM=100;

char s[MAXNUM], s1[MAXNUM];
int a[MAXNUM], b[MAXNUM], c[MAXNUM], d[MAXNUM];
int s2;

void print_superlong(int c[], int nmax)
{
     int i,p;
     if (c[nmax]) cout << c[nmax];
     for(i=--nmax; i>=0; i--) cout << c[i];
     cout << endl;
}

int main()
{
     int i,j,n,n1,nmax, p;
    
     cin >> s;
     cin >> s1;
     cin >> s2;         
     n=strlen(s);
     n1=strlen(s1);    
     for(i=0; i<n; i++) a[i]=s[n-i-1]-'0';
     for(i=0; i<n1; i++) b[i]=s1[n1-i-1]-'0';     
     if (n1>n) nmax=n1;
     else nmax=n;
     p=0;
     for(i=0; i<=nmax; i++) 
     {
         c[i]=a[i]+b[i]+p;
         if(c[i]>9) 
         { 
           p=1;
           c[i]-=10;
         }
         else p=0;              
     }
     p=0;
     for(i=0; i<=nmax; i++) 
     {
         d[i]=c[i]*s2+p;
         if(d[i]>9) 
         { 
           p=d[i]/10;
           d[i]%=10;
         }
         else p=0;
     }
     if(p) { d[i]=p; nmax++; }   
     print_superlong(d, nmax);
      
     return 0;  
}
             
