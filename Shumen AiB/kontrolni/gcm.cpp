#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define mp make_pair
#define pb push_back
lli a,b,aa,bb;
lli nod,nok;
map<lli,lli> fa,fb;
set<lli> prim;
vector<pair<lli,pair<lli,lli> > >sleto;
int main(){
   cin>>a>>b;
   aa=a;
   bb=b;
   lli pr=2;
   while(a!=1){
      if(a%pr==0){
         fa[pr]++;
         a/=pr;
         prim.insert(pr);
      }
      else pr++;
      if(pr*pr>a){
         pr=a;
      }
      //cout<<a<<" "<<pr<<"\n";
   }
   pr=2;
   while(b!=1){
      if(b%pr==0){
         fb[pr]++;
         b/=pr;
         prim.insert(pr);
      }
      else pr++;
      if(pr*pr>b){
         pr=b;
      }
      //cout<<b<<" "<<pr<<"\n";
   }
   for(set<lli>::iterator it=prim.begin();it!=prim.end();it++){
      sleto.pb( mp(*it,mp(min(fa[*it],fb[*it]),max(fa[*it],fb[*it]))) );
   }
   //for(int i=0;i<sleto.size();i++){
   //   cout<<sleto[i].first<<" "<<sleto[i].second.first<<" "<<sleto[i].second.second<<"\n";
   //}
   int n=sleto.size();
   //assert(n<25);
   lli ax=0,ay=1e18;
   for(lli i=0;i<(1<<n);i++){
      lli x=1,y=1;
      for(int j=0;j<n;j++){
         if(i&(1<<j)){
            for(int k=1;k<=sleto[j].second.first;k++){
               x*=sleto[j].first;
            }
            for(int k=1;k<=sleto[j].second.second;k++){
               y*=sleto[j].first;
            }
         }
         else{
            for(int k=1;k<=sleto[j].second.second;k++){
               x*=sleto[j].first;
            }
            for(int k=1;k<=sleto[j].second.first;k++){
               y*=sleto[j].first;
            }
         }
      }
      //int y=(long long)(aa*bb/x);
      //cout<<x<<" "<<y<<"\n";
      if(x<=y){
         if(ay-ax>y-x){
            ay=y;
            ax=x;
         }
      }
      //assert(x*y==aa*bb);
   }
   cout<<ax<<" "<<ay<<"\n";
}
