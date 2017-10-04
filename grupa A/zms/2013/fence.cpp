#include<bits/stdc++.h>
using namespace std;
const int nmax=3009;
typedef pair<int,int> pii;
int n;
map<int,int> brx,bry;
pii to4ki[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>to4ki[i].first>>to4ki[i].second;
      brx[to4ki[i].first]++;
      bry[to4ki[i].second]++;
   }
}
