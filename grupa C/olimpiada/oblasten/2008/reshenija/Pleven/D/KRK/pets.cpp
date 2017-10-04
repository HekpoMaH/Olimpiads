#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{ long br1,br2,br3,br4,br5,br6,n,i,x,y,r,j;
    
 string m,z;  
  br1=0;
  br2=0;
  br3=0;
  br4=0;
  br5=0;
  br6=0;
  cin>>n;
  for(j=1;j<=n;j++)
  {cin>>m;
  r=m.size();
  for(i=0;i<=r-1;i++)
  {if(m[i]=='C') {br1++;}
   if(m[i]=='A') {br2++;}
   if(m[i]=='T') {br3++;}
   if(m[i]=='G') {br4++;}
   if(m[i]=='P') {br5++;}
   if(m[i]=='I') {br6++;}
}
  x=br1+br2+br3;
  y=br4+br5+br6;
  br1=0;
  br2=0;
  br3=0;
  br4=0;
  br5=0;
  br6=0;
   if(x>y) {cout<<"CAT"<<endl;}
   else
   if(x<y) {cout<<"GPI"<<endl;}
   else
   if(x==y && x!=0) {cout<<"CAT-GPI"<<endl;}
   else
   if(x==y && x==0) {cout<<"UFO"<<endl;}}

return 0;
}
