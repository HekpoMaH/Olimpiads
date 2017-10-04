#include<bits/stdc++.h>
using namespace std;
int nmax=1e5;
set<int> nums;
set<int> rnums;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   srand(time(0));
   for(int i=1;i<=2*nmax;i++){
      nums.insert(i);
   }
   set<int>::iterator it;
   cout<<nmax<<"\n";
   for(int i=1;i<=nmax;i++){
      int op=rand()%3;
      if(rnums.size()==0){
         op=0;
      }
      if(nums.size()==0){
         op=rand()%2+1;
      }
      if(op==0){
         int elidx=rand()%nums.size();
         it=nums.begin();
         advance(it,elidx);
         cout<<op<<" "<<*it<<"\n";
         nums.erase(*it);
         rnums.insert(*it);
      }
      if(op==1){
         int elidx=rand()%rnums.size();
         it=rnums.begin();
         advance(it,elidx);
         cout<<op<<" "<<*it<<"\n";
         rnums.erase(*it);
         nums.insert(*it);
      }
      if(op==2){
         if(rand()%3){
            int elidx=rand()%rnums.size();
            it=rnums.begin();
            advance(it,elidx);
            cout<<op<<" "<<*it<<"\n";
         }
         else cout<<op<<" "<<rand()%(int)2e5<<"\n";
      }
   }
}
