#include <iostream>
using namespace std;
typedef long long lli;
lli no(int lev, lli offs){
   if (!lev) return 0;
   lli size=(1LL<<lev);
   lli start=size-1;
   if (offs&1) start+=(size>>1);
   return start+(offs>>1);
}
void coord(lli n,int &lev,lli &offs){
   lli one=1;
   lli m=1;
   lev=-1;
   while (n>=m-1){m<<=1;lev++;}
   lli size=(one<<lev);
   lli start=size-1;
   offs=0;
   if (n>=start+(size>>1)){offs++;n-=(size>>1);}
   offs+=((n-start)<<1);
}
void solve(lli n,lli &prev,lli &nextL,lli &nextR){
   int lev;
   lli offs;
   coord(n,lev,offs);
   prev=no(lev-1,offs>>1);
   nextL=no(lev+1,2LL*offs);
   nextR=no(lev+1,2LL*offs+1);
}
int main(){
   lli n,prev,nextL,nextR;
   cin>>n;
   solve(n,prev,nextL,nextR);
   cout<<prev<<endl;
   cout<<nextL<<' '<<nextR<<endl;
}
