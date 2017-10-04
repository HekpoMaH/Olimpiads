#include<bits/stdc++.h>
using namespace std;
string t,p;
int base[3]={0,109,131};
unsigned basepow[3]={1,1,1};
unordered_map<string,int> m;
int main(){
   cin>>t;
   cin>>p;
   unsigned hp[3]={0,0,0};
   for(int i=0;i<p.size();i++){
      for(int j=1;j<=2;j++)hp[j]=hp[j]*base[j]+p[i];
   }
   unsigned ht[3]={0,0,0};
   int br=0;
   for(int i=0;i<p.size()-1;i++){
      for(int j=1;j<=2;j++)basepow[j]*=base[j];
   }
   for(int i=0;i<p.size();i++){
      for(int j=1;j<=2;j++)ht[j]=ht[j]*base[j]+t[i];
   }
   for(int i=0;i<t.size()-p.size()+1;i++){
      int fl=1;
      for(int j=1;j<=2;j++){
         if(hp[j]!=ht[j])fl=0;
         ht[j]-=t[i]*basepow[j];
         ht[j]*=base[j];
         ht[j]+=t[i+p.size()];
      }
      if(fl)br++;
   }
   cout<<br<<endl;
}
