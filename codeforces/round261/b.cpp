#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define push_back(a,b) pb(a,b)
using namespace std;
const int nmax=2*1e5+9;
typedef long long lli;
int n;

int a[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
   cout<<a[n]-a[1]<<" ";
   lli br1=0,br2=0;
   for(int i=1;i<=n;i++){
      if(a[i]==a[1])br1++;
      if(a[i]==a[n])br2++;
   }
   if(a[1]!=a[n])cout<<(long long)(br1*br2)<<"\n";
   if(a[1]==a[n])cout<<(lli)(br1*(br2-1)/2)<<"\n";
}

