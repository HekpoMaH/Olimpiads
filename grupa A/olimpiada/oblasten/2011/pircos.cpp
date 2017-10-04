#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
typedef long long lli;
lli arr[nmax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   lli xr=0;
   for(int i=1;i<=n;i++)cin>>arr[i],xr^=arr[i];
   lli setbitno=xr&~(xr-1);
   lli x=0,y=0;
   for(int i=1;i<=n;i++){
      if(arr[i]&setbitno){
         x^=arr[i];
      }
      else y^=arr[i];
   }
   cout<<min(x,y)<<" "<<max(x,y)<<"\n";
}

