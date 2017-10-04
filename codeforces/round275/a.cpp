#include<bits/stdc++.h>
using namespace std;
long long l,r;
long long nod(long long x,long long y){
   return y ? nod(y,x%y) : x;
}
int main(){
   cin>>l>>r;
   long long a,b,c;
   for(long long i=l;i<=r;i++){
      for(long long j=i+1;j<=r;j++){
         for(long long k=j+1;k<=r;k++){
            if(nod(i,j)==1&&nod(j,k)==1&&nod(i,k)!=1){
               cout<<i<<" "<<j<<" "<<k<<"\n";
               exit(0);
            }
         }
      }
   }
   cout<<-1<<"\n";
}
