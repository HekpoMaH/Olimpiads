#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
const int nmax=15009;
lli tod(lli x,lli base){
   lli p=1,ans=0;
   while(x!=0){
      ans+=(x%10)*p;
      p*=base;
      x/=10;
   }
   return ans;
}
void solve(){
   lli a,b;
   cin>>a>>b;
   set<lli> nn;
   map<lli,lli> basn;
   basn.clear();
   nn.clear();
   for(int i=10;i<=15000;i++){
      lli an=tod(a,i);
      nn.insert(an);
      basn[an]=i;
   }
   for(int i=10;i<=15000;i++){
      lli bn=tod(b,i);
      if(nn.find(bn)!=nn.end()){
         cout<<basn[bn]<<" "<<i<<"\n";
         return;
      }
   }
}
int main(){
   int k;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ifstream fin("whatbase.in");
   ofstream fout("whatbase.out");
   fin>>k;
   while(k--){
      lli a,b;
      fin>>a>>b;
      set<lli> nn;
      map<lli,lli> basn;
      basn.clear();
      nn.clear();
      for(int i=10;i<=15000;i++){
         lli an=tod(a,i);
         nn.insert(an);
         basn[an]=i;
      }
      for(int i=10;i<=15000;i++){
         lli bn=tod(b,i);
         if(nn.find(bn)!=nn.end()){
            fout<<basn[bn]<<" "<<i<<"\n";
            break;
         }
      }
   }

}
