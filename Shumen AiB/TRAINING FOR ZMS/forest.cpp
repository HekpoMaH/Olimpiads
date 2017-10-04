#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
lli a,b,k,m,x;
int main(){
   lli lef=0;
   lli mid;
   cin>>a>>k>>b>>m>>x;
   lli righ=2*1e18/a;
   while(lef+1<righ){
      mid=(lef+righ)/2;
      lli fp=a*(k-1)*(mid/k)+a*(mid%k);
      lli sp=b*(m-1)*(mid/m)+b*(mid%m);
      if(fp+sp>=x){
         righ=mid;
      }
      else lef=mid;
   }
   cout<<righ<<"\n";
}
