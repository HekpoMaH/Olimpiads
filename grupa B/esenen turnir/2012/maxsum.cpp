#include<iostream>
#include<algorithm>
using namespace std;
int it[2009];
int n;
int a[109],i,j,k,ans,curr;
int get(int idx){
   int re=0;
   while(idx>0)re=max(re,it[idx]),idx-=(idx&-idx);
   return re;
}
void upd(int idx,int what){
   while(idx<=2000){
      it[idx]=max(it[idx],what);
      idx+=(idx&-idx);
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(i=1;i<=n;i++){
      cin>>k;
      for(j=1;j<=k;j++)cin>>a[j];
      sort(a+1,a+k+1);
      a[k+1]=-2910;
      for(j=k;j>=1;j--){
         if(a[j]!=a[j+1]){
            curr=get(a[j])+a[j];
            upd(a[j],curr);
            ans=max(ans,curr);
         }
      }
   }
   cout<<ans<<endl;
}
