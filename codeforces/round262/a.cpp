#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pb(a,b) push_back(a,b)
typedef long long lli;
int main(){
   lli n,m;
   cin>>n>>m;
   int br=0;
   while(n!=0){
      br++;
      n--;
      if(br%m==0)n++;
   }
   cout<<br<<"\n";
}
