#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
typedef long long lli;
lli a,b,c;
vector<lli> ans;
bool chek(lli x,lli s){
   if(x>1e9)return false;
   int xx=x;
   int sx=0;
   while(x!=0){
      sx+=x%10;
      x/=10;
   }
   x=xx;
   int pr=1;
   for(int i=1;i<=a;i++)pr*=sx;
   cout<<x<<" "<<b*pr+c<<" "<<s<<" "<<sx<<"\n";
   if(x==b*pr+c)return true;
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>a>>b>>c;
   for(int i=0;i<=81;i++){
      lli x=0,pr=1;
      for(int j=1;j<=a;j++)pr*=i;
      x=b*pr+c;
      if(chek(x,i)==true)ans.pb(x);
   }
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   if(ans.size()!=0)cout<<endl;
}
