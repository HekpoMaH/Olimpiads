#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+9;
int a,b,n;
long long mn=1e9;
vector<int> v[nmax];
long long price[nmax];
bool chek(int st,int en,int ro){
   int idx1=-1,idx2=-1;
   for(int i=0;i<(int)v[ro].size();i++){
      if(v[ro][i]==st){
         idx1=i;
         break;
      }
   }
   for(int i=0;i<(int)v[ro].size();i++){
      if(v[ro][i]==en){
         idx2=i;
         break;
      }
   }
   return idx1<idx2;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ifstream fin("cowroute.in");
   ofstream fout("cowroute.out");
   fin>>a>>b>>n;
   for(int i=1;i<=n;i++){
      int x;
      fin>>price[i];
      fin>>x;
      for(int j=1;j<=x;j++){
         int k;
         fin>>k;
         v[i].push_back(k);
      }
   }
   int used[10009];
   for(int i=1;i<=n;i++){
      int posofa=-1;
      for(int ii=0;ii<(int)v[i].size();ii++){
         if(v[i][ii]==a){
            posofa=ii;
            break;
         }
      }
      if(posofa==-1)continue;
      if(chek(a,b,i)){
         mn=min(mn,price[i]);
         continue;
      }
      for(int j=1;j<=n;j++){
         if(chek(a,b,j))continue;
         if(i==j){
            continue;
         }
         for(int ii=0;ii<(int)v[j].size();ii++){
            if(chek(a,v[j][ii],i)&&chek(v[j][ii],b,j)){
               mn=min(mn,price[i]+price[j]);
            }
         }
      }
   }
   if(mn!=1e9)fout<<mn<<"\n";
   else fout<<-1<<"\n";
}
