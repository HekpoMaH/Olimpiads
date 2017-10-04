#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long lli;
const int nmax=1e5;
int girls[109];
int boys[109];
int g,b;
int main(){
   cin>>g;
   cin>>b;
   for(int i=1;i<=g;i++){
      cin>>girls[i];
   }
   for(int i=1;i<=b;i++){
      cin>>boys[i];
   }
   sort(girls+1,girls+g+1);
   sort(boys+1,boys+b+1);
   int ukg=1,ukb=1;
   int pairs=0;
   while(ukg<=g&&ukb<=b){
      if(abs(girls[ukg]-boys[ukb])<=1){
         ukg++;
         ukb++;
         pairs++;
      }
      else if(girls[ukg]>boys[ukb]){
         ukb++;
      }
      else ukg++;
   }
   cout<<pairs<<"\n";
}
