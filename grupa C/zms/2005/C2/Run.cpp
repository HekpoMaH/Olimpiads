#include<iostream>
#include <math.h>
using namespace std;

int N;
const int Nmax=101;
int v[Nmax+1];
double s[Nmax+1];
double w[Nmax+1];
const double eps=1e-9;
const double ts=0.001;
const int kmax=200000;

int incr()
{
 int i;
 for(i=1;i<N;i++) 
  if(!(v[i]<=v[i+1])) return 0;
 return 1;
}

int exist(int k, double x)
{
  int i;
  for(i=1;i<=k;i++) 
   if(fabs(w[i]-x) < eps) return 1;
  return 0;
}

int number()
{
  int b,i;
  b=0;
 
  for(i=1;i<=N;i++)
  if(!exist(b,s[i])) {b++; w[b]=s[i];}
  return b;
}


void main()
{
 int i,k,c,cn,x;
 c=0;
 cin >> N;
 for(i=1;i<=N;i++) cin >> v[i];  

 for(i=1;i<=N;i++) s[i]=i;
 
 cn=number();
 for(k=1;k<=kmax;k++)
 { 
  c++;
  for(i=1;i<=N;i++) s[i] = s[i] + ts*v[i];
  for(i=N-1;i>=1;i--)
   if(s[i]>=s[i+1]) {s[i]=s[i+1]; v[i]=v[i+1];}

  x=number();
  if(cn !=x) cn=x; 
  if(incr()) break;
 }

cout << cn << "\n";

}

