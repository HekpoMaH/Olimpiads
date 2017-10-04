#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
   cin>>n;
   int sum=1;
   for(int i=1;;i++){
      n-=sum;
      sum+=(i+1);
      if(n<sum){
         cout<<i<<"\n";
         exit(0);
      }
   }
}
