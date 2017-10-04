#include<bits/stdc++.h>
using namespace std;
const int nmax=59;
string tab[nmax];
int n;
int br[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>tab[i];
   }
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(tab[i][j]=='Y'){
            br[i]++;
            br[j]++;
            continue;
         }
         //cout<<i<<" "<<j<<"\n";
         for(int k=0;k<n;k++){
            if(k==i||k==j)continue;
            if(tab[i][k]=='Y'&&tab[k][j]=='Y'){
               br[i]++;
               br[j]++;
               break;
            }
         }
      }
   }
   int mx=0;
   for(int i=0;i<n;i++)mx=max(mx,br[i]);
   cout<<mx<<"\n";
}
