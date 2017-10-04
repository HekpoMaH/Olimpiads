#include<bits/stdc++.h>
using namespace std;
int r[3],c[3];
int main(){
   cin>>r[1]>>c[1]>>r[2]>>c[2];
   int brook=2;
   if(r[1]==r[2])brook--;
   if(c[1]==c[2])brook--;
   cout<<brook<<" ";
   //bishop
   if((r[1]+c[1])%2!=(r[2]+c[2])%2){
      cout<<0<<" ";
   }
   else{
      if(abs(r[2]-r[1])==abs(c[2]-c[1]))cout<<1<<" ";
      else cout<<2<<" ";
   }
   cout<<abs(r[1]-r[2])+abs(c[1]-c[2])-min(abs(r[1]-r[2]),abs(c[1]-c[2]))<<"\n";
}
