#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define se second
#define fi first
#define pb push_back
long long n;
vector<long long> lcky;
void go(long long num){
   if(num>(long long)(1e9)){
      return;
   }
   lcky.pb(num);
   go(num*10+4);
   go(num*10+7);
}
int main(){
   cin>>n;
   go(4);
   go(7);

   sort(lcky.begin(),lcky.end());
   cout<<lower_bound(lcky.begin(),lcky.end(),n)-lcky.begin()+1<<"\n";
}
