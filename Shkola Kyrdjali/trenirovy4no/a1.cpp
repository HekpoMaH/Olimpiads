#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
lli a,b;
lli x,y;
int main(){
   scanf("%lld %lld",&a,&b);
   if(a%2LL!=b%2LL||a<b){
      cout<<-1<<"\n";
      return 0;
   }
   x=((lli)a-(lli)b)/2LL;
   y=(lli)x+(lli)b;
   if( (x^y) !=b){
      cout<<-11<<"\n";
      return 0;
   }
   cout<<x<<" "<<y<<"\n";
}
