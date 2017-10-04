#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAXNUM=100;

char s[MAXNUM], s2[MAXNUM];
int a[MAXNUM], b[MAXNUM], c[MAXNUM], d[MAXNUM], d1[MAXNUM];
int s1, s3;



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
     
     cin >> s >> s1;
     cin >>s2 >> s3 ;
          
     n=strlen(s);
     n1=strlen(s2);
      for(i=0; i<n; i++) a[i]=s[n-i-1]-'0';
     for(i=0; i<n1; i++) b[i]=s2[n1-i-1]-'0'; 
     
     
     
      //multiply superlong*digit
      p=0;
     for(i=0; i<=n; i++) 
     {
         d[i]=a[i]*s1+p;
         if(d[i]>9) 
         { 
           p=d[i]/10;
           d[i]%=10;
         }
         else p=0;
     }
     if(p!=0) {d[i+1]=p; i=i+1;}
     //multiply superlong*digit
     p=0;
     for(j=0; j<=n1; j++) 
     {
         d1[j]=b[j]*s3+p;
         if(d1[j]>9) 
         { 
           p=d1[j]/10;
           d1[j]%=10;
         }
         else p=0;
     }
    if(p!=0) {d1[j+1]=p; j=j+1;} 
   
     if (j>i) nmax=j;
     else nmax=i;
     //sum of superlong int
       p=0;
   for(i=0; i<=nmax; i++) 
     {
         c[i]=d[i]+d1[i]+p;
         if(c[i]>9) 
         { 
           p=1;
           c[i]-=10;
         }
         else p=0;
               
     }
     
     
   //  print_superlong(c, nmax);
     if(p) { c[i]=p; nmax++; }
     print_superlong(c, nmax-1);
     return 0;  
}
             
