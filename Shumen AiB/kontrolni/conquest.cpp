#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int nmax=1009;
pair<int,int> t[nmax];
pair<int,int> t2[nmax];
int n;
int sofs;
int sofs2;
int mnmoney=1e9;
int csol;
int psum[nmax];
void solve(){
   for(int i=1;i<=n;i++){
      psum[i]=psum[i-1]+t[i].first;
   }
   int money=0;
   int ve4ekupeni=0;
   for(int i=n;i>=1;i--){
      int zahvanati=psum[i-1]+ve4ekupeni;
      if(zahvanati>t[i].first)continue;
      int doljnipokupat=t[i].first-zahvanati;

      doljnipokupat=doljnipokupat/2+1;
      //cout<<zahvanati<<" "<<ve4ekupeni<<"+"<<psum[i-1]<<" "<<doljnipokupat<<"\n";
      money+=doljnipokupat*t[i].second;
      ve4ekupeni+=doljnipokupat;
   }
   cout<<money<<"\n";
   exit(0);
}
void solve2(){
   for(int i=1;i<=n;i++){
      t[i]=t2[i];
   }
   int money=0;
   sofs=sofs2;
   csol=0;
   while(sofs!=0){
      for(int i=1;i<=n;i++){
         if(t[i].first<csol){
            csol+=t[i].first;
            sofs-=t[i].first;
            t[i].first=0;
         }
         else{
            csol++;
            money+=t[i].second;
            t[i].first--;
            sofs--;
         }
         for(int j=1;j<=n;j++){
            if(t[j].first<csol){
               csol+=t[j].first;
               sofs-=t[j].first;
               t[j].first=0;
            }
         }
      }
   }
   mnmoney=min(mnmoney,money);
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>t[i].first>>t[i].second;
      sofs+=t[i].first;
      sofs2+=t[i].first;
   }
   sort(t+1,t+n+1);
   solve();
   solve2();
   cout<<mnmoney<<"\n";
}
