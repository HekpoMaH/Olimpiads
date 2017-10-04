#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
lli sum;
const int nmax=3*1e3+9;
int n,k;
int a[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   sort(a+1,a+n+1);
   queue<int> q;
   int uk=n;
   while(uk>=1){
      sum+=2*(a[uk]-1);
      uk-=k;
   }
   cout<<sum<<"\n";
}
