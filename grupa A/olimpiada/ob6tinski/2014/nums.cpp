#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n;
int main(){
   cin>>n;
   int br=0;
   for(lli i=1;i*i<=2*n;i++){
      if(2*n%i==0){
         if(i%2==1||(2*n/i)%2==1){
            br++;
         }
      }
   }
   cout<<br<<"\n";
}
