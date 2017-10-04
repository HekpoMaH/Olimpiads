#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long lli;

const int nmax=1e5+9;
lli a;
bool ispr(lli x){
   for(int i=2;i*i<=x;i++){
      if(x%i==0)return true;
   }
   return false;
}
int main(){
   cin>>a;
   for(int i=4;i<=a;i++){
      if(ispr(i)==true&&ispr(a-i)==true){
         cout<<i<<" "<<a-i<<"\n";
         exit(0);
      }
      
   }
}
