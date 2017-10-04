#include<bits/stdc++.h>
using namespace std;
const int amax=109;
const int nmax=1e5+9;
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long lli;
int si4ki[amax][amax][amax];
int a[nmax],b[nmax],c[nmax];
int bra[amax],brb[amax],brc[amax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   //freopen("input","r",stdin);
   //freopen("output","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i]>>b[i]>>c[i];
      bra[a[i]]++;
      brb[b[i]]++;
      brc[c[i]]++;
      si4ki[a[i]][b[i]][c[i]]++;
   }
   lli ans=0;
   for(int i=1;i<=n;i++){
      lli aa=a[i];
      lli bb=b[i];
      lli cc=c[i];
      int cnt=bra[a[i]];
      for(int j=1;j<=100;j++){
         cnt-=si4ki[a[i]][bb][j];
         cnt-=si4ki[a[i]][j][cc];
      }
      cnt+=si4ki[aa][bb][cc];
      ans+=cnt;
      cnt=brb[b[i]];
      for(int j=1;j<=100;j++){
         cnt-=si4ki[aa][bb][j];
         cnt-=si4ki[j][bb][cc];
      }
      cnt+=si4ki[aa][bb][cc];
      ans+=cnt;
      cnt=brc[c[i]];
      for(int j=1;j<=100;j++){
         cnt-=si4ki[aa][j][cc];
         cnt-=si4ki[j][bb][cc];
      }
      cnt+=si4ki[aa][bb][cc];
      ans+=cnt;
      //pesho bi kazal: "CODE DUPLICATION!!!"
   }
   cout<<ans/2<<"\n";
}
