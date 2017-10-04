#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+9;
int a,b,n;
int mn=1e9;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ifstream fin("cowroute.in");
   ofstream fout("cowroute.out");
   fin>>a>>b>>n;
   for(int i=1;i<=n;i++){
      int x;
      int price;
      fin>>price;
      fin>>x;
      vector<int> v;
      while(v.size()>1)v.pop_back();
      for(int j=1;j<=x;j++){
         int k;
         fin>>k;
         v.push_back(k);
      }
      for(int j=0;j<v.size();j++){
         for(int jj=j+1;jj<v.size();jj++){
            if(v[j]==a&&v[jj]==b){
               mn=min(mn,price);
            }
            //cout<<"g["<<j<<"]["<<jj<<"]=min("<<price<<","<<g[j][jj]<<")\n";
         }
      }
   }
   if(mn!=1e9)fout<<mn<<"\n";
   else fout<<-1<<"\n";
}
