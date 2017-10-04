#include<bits/stdc++.h>
using namespace std;
const int prime[20]={0,3,29,17,7,5,2,19,31,13,11,17,881,101,97};
const int nmax=200009;
const int offset=0;
typedef unsigned long long lli;
int n,m;
lli a[nmax],b[nmax];
lli aa[nmax],bb[nmax];
unsigned long long st[20][nmax],hash[20];
void read(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      aa[i-1]=offset+a[i-1]-a[i];
   }
   for(int i=1;i<=m;i++){
      cin>>b[i];
      bb[i-1]=offset+b[i-1]-b[i];
   }
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   if(m==1){
      cout<<n<<"\n";
      return 0;
   }
   if(n==1){
      cout<<0<<"\n";
   }
   m--;
   n--;
   for(int i=1;i<=14;i++)st[i][0]=1;
   for(int k=1;k<=14;k++)for(int i=1;i<=n;i++)
      st[k][i]=(st[k][i-1]*(lli)prime[k]);
   unsigned long long hash2[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   for(int k=1;k<=14;k++)for(int i=1;i<=m;i++)
      hash[k]=hash[k]*(lli)prime[k]+bb[i];
   for(int k=1;k<=14;k++)for(int i=1;i<m;i++){
      hash2[k]=hash2[k]*(lli)prime[k]+aa[i];
   }
   int ans=0;
   for(int i=m;i<=n;i++){
      for(int k=1;k<=14;k++)hash2[k]=hash2[k]*(lli)prime[k]+aa[i];
      int fl=1;
      for(int k=1;k<=14;k++)if(hash[k]!=hash2[k])fl=0;
      if(fl==1)ans++;
      for(int k=1;k<=14;k++)hash2[k]=hash2[k]-aa[i-m+1]*st[k][m-1];
   }
   cout<<ans<<"\n";
}
