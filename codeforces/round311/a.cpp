#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
int n;
int mn[4];
int mx[4];
int main(){
   cin>>n;
   for(int i=1;i<=3;i++){
      cin>>mn[i]>>mx[i];
   }
   int numof_1st_deg=max(min(mx[1],n-mn[2]-mn[3]),mn[1]);
   cout<<numof_1st_deg<<" ";
   n-=numof_1st_deg;
   int numof_2nd_deg=max(min(mx[2],n-mn[3]),mn[2]);
   cout<<numof_2nd_deg<<" ";
   n-=numof_2nd_deg;
   assert(mn[3]<=n&&n<=mx[3]);
   cout<<n<<"\n";
}
