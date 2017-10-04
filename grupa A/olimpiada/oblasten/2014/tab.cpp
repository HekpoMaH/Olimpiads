#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
pair<int,int> era[nmax];
int n;
void precompute(){
   era[1].first=1;era[1].second=1;
   for(int i=2;i<=n;i++){
      era[i].second=i;
      if(era[i].first==0){
         for(int j=i;j<=n;j+=i){
            era[j].first++;
         }
      }
   }
}

int main(){
   int r,c;
   cin>>n>>r>>c;
   int nn=n;
   n*=n;
   precompute();
   sort(era+1,era+n+1);
   cout<<era[(r-1)*nn+c].second<<"\n";
}
