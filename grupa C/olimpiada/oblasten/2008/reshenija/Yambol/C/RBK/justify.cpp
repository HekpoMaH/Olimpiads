#include<iostream>
using namespace std;

int main()
{
int i,j,l,r,z,n,uk[31],ukuk,vsi,k,p;
char a[61],b[61],x;
uk[0]=0;
cin>>n;
cin.get(x);

for(i=1;i<=n;i++)
 { 
  for(j=1;j<=60;j++)
   b[j]='0';          
  ukuk=1;    
  j=1;
  do
  {
   cin.get(a[j]);
   if(   (b[j]=='0') && ( (a[j]==' ')||(a[j]=='\n') )   )
    {
     uk[ukuk]=j-1;
     ukuk++;
    }  
   if(a[j]!=' ') 
    j++;    
   else
    b[j]='1';    
  }
  while(a[j-1]!='\n');
  
  ukuk=ukuk-2;
  vsi=62-j;
  k=vsi/ukuk;
  p=vsi-ukuk*k;
  for(l=0;l<p;l++)
   {
    for(r=uk[l]+1;r<=uk[l+1];r++)
     cout<<a[r];
    for(z=1;z<=k+1;z++)
     cout<<' '; 
   }
  for(l=p;l<ukuk;l++)
   {
    for(r=uk[l]+1;r<=uk[l+1];r++)
     cout<<a[r];
    for(z=1;z<=k;z++)
     cout<<' ';
   }
  for(r=uk[ukuk]+1;r<=uk[ukuk+1];r++)
   cout<<a[r];
  cout<<endl;     
 }
 
 
return 0;
}
