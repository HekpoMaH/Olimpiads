#include<bits/stdc++.h>
using namespace std;
void ans(int n,bool added=false){
   cout<<n<<"\n";
   int numg=added ? (n+1)/2 : n/2;
   for(int is=1;is<=n;is++){
      cout<<numg<<" ";
      int i=is;
      int j=1;
      while(j<=n){
         if(i<j)
            cout<<i<<"-"<<j<<" ";
         else if(i==j&&added)
            cout<<i<<"-"<<n+1<<" ";
         i--;
         j++;
         if(i<1)i+=n;
      }
      cout<<"\n";
   }
}
int main(){
   int n;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   if(n%2>0){
      ans(n);
   }
   else{
      ans(n-1,true);
   }
}
