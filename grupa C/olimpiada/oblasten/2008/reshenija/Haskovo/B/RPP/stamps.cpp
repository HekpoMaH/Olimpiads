#include <iostream>

using namespace std;

int main()
{
    int s, n;
    int m[3000];
    int i, ii,z,zz[3001], ss[3001];
 // s=22;n=5;      m[0]=15; m[1]=1;m[2]=8;m[3]=4; m[4]=12;
   cin>>s>>n;  for (i=0; i<n; i++)         cin>>m[i];

for (i=0; i<31; i++)  {zz[i]=0; ss[i]=s;}

for(i=0; i<n; i++){   zz[n] = zz[n] + ss[n]/m[i];  ss[n] = ss[n]%m[i];}
  
    int x;     for(ii=0; ii<n; ii++)     for(i=0; i<n-1; i++)     if (m[i]<m[i+1])
  { x=m[i]; m[i]=m[i+1]; m[i+1]=x;} 
    


for (ii=0; ii<n; ii++)  for(i=ii; i<n; i++)
{
    zz[ii] = zz[ii] + ss[ii]/m[i];
    ss[ii] = ss[ii]%m[i];
}

 
    for(ii=0; ii<n; ii++)      for(i=0; i<n; i++)      if (zz[i]>zz[i+1])
  { x=zz[i]; zz[i]=zz[i+1]; zz[i+1]=x;} 

cout<<zz[0]<<endl;

    return 0;
}
