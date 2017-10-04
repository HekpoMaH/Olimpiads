#include <iostream>
using namespace std;
int main()
 {
  int k, i, j, x, y, t, cb[50], z=0, z2=1;
  string a;
  cin>>a>>k;
  //a+="0";
  int mn, mx;
  bool ismn, ismx;
  for(i=0; i<a.size(); i++) cb[i]=i;
  t=0;
  bool fs=true, iss;
  bool edn=true;
  while(cb[0]!=a.size()-1)
   {
    x=1;
    t=0;
    edn=false;
    for(j=(k-1); j>=0; j--)
     {
      z=(a[cb[j]]-'0');
      if(z==z2) edn=true;
      t+=(a[cb[j]]-'0')*x;
      x*=10;
      z2=z;
      //cout<<"cb:";
      //for(y=0; y<k; y++) cout<<cb[y]<<' '; cout<<endl;
     }
    //cout<<t<<endl;
    if(fs) { mn=mx=t; fs=false; ismn=false; ismx=false; }
    else if(t%3==0 && t>mx && t!=0 && !edn) { mx=t; ismx=true; }
    else if(t%3==0 && t<mn && t!=0 && !edn) { mn=t; ismn=true; }
    if(cb[k-2]==cb[k-1]+1) cb[k-1]+=2;
    else cb[k-1]++;
    for(j=k-1; j>=1; j--) if(cb[j]>a.size()-1) { cb[j]=cb[0]+1; cb[j-1]++; }
   }
   if(ismn && ismx) cout<<mn<<' '<<mx;
   else cout<<"-1";
   cout<<endl;
   return 0;
 }
