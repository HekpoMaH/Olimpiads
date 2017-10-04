#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
bool qchek(lli x){
   int cnt=0;
   lli x2=x;
   while(x!=0){
      cnt++;
      x/=10;
   }
   x=x2;
   lli lbound=1;
   for(int i=1;i<cnt;i++){
      lbound*=10;
      lbound+=9;
   }
   lli ubound=0;
   for(int i=1;i<cnt;i++){
      ubound*=10;
      ubound+=3;
   }
   ubound*=10;
   ubound+=5;
   if(lbound<=x&&x<=ubound)return true;
   return false;
}
int main(){
   lli n;
   for(int i=1;i<=3;i++){
      cin>>n;
      cout<<qchek(n)<<"\n";
   }
}
