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
      kolovozi curr;
      while(!engaged.empty()&&x>engaged.top().mnt){
         curr=engaged.top();
         curr.mnt=0;
         free.push(curr);
         engaged.pop();
      }
      if(free.empty()){
         cout<<0<<" "<<i<<"\n";
         exit(0);
      }
      ans[i]=free.top().num;
      curr=free.top();
      free.pop();
      curr.mnt=y;
      engaged.push(curr);
   }
   for(int i=1;i<=n;i++){
      cout<<ans[i]<<"\n";
   }
}
