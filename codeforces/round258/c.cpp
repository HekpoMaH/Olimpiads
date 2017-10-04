#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool solve(ll n,ll k,ll d1,ll d2){
   if(n%3!=0)return false;
   for(int i=-1;i<=1;i++){
      for(int j=-1;j<=1;j++){
         if(j==0||i==0)continue;
         ll dd1=i*d1;
         ll dd2=j*d2;
         ll x2=(k-dd1+dd2);
         if(x2%3!=0)continue;
         x2/=3;
         if(x2>=0&&x2<=k){
            ll x1=dd1+x2;
            ll x3=x2-dd2;
            if(x1>=0&&x1<=k&&x3<=k&&x3>=0){
               if(x1<=n/3&&x2<=n/3&&x3<=n/3)return true;
            }
         }
      }
   }
   return false;
}
int main(){
   ll n,k,d1,d2;
   ll tests;
   ios_base::sync_with_stdio(false);
   cin>>tests;
   while(tests--){
      cin>>n>>k>>d1>>d2;
      if(solve(n,k,d1,d2)==true)cout<<"yes\n";
      else cout<<"no\n";
   }
}
