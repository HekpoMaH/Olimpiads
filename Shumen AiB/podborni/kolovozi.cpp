#include<bits/stdc++.h>
using namespace std;
struct kolovozi{
   int mnt,num;
   kolovozi(){}
   kolovozi(int _mnt,int _num){
      mnt=_mnt;
      num=_num;
   }
   bool operator < (const kolovozi &kol) const{
      if(mnt<kol.mnt)return false;
      if(mnt>kol.mnt)return true;
      if(num<kol.num)return false;
      return true;
   }
};
int n,k;
int ans[100009];
int main(){
   cin>>k>>n;
   priority_queue<kolovozi> free,engaged;
   for(int i=1;i<=k;i++){
      free.push(kolovozi(0,i));
   }
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      kolovozi bahti;
      while(!engaged.empty()&&x>engaged.top().mnt){
         bahti=engaged.top();
         bahti.mnt=0;
         free.push(bahti);
         engaged.pop();
      }
      if(free.empty()){
         cout<<0<<" "<<i<<"\n";
         exit(0);
      }
      ans[i]=free.top().num;
      bahti=free.top();
      free.pop();
      bahti.mnt=y;
      engaged.push(bahti);
   }
   for(int i=1;i<=n;i++){
      cout<<ans[i]<<"\n";
   }
}
