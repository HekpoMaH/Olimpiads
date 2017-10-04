#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int perm[nmax];
int n,k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   int br=0;
   for(int i=1;i<=n;i++){
      if(perm[i]==0){
         int kk=k;
         for(int j=i;j<=n;j+=kk)perm[j]=++br,kk++;
      }
      cout<<perm[i]<<" ";
   }
   cout<<"\n";
}
