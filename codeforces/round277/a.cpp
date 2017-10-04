#include<bits/stdc++.h>
using namespace std;
const int nmax=3009;
long long n;
int main(){
   cin>>n;
   if(n%2==0){
      cout<<n/2<<"\n";
   }
   else{
      cout<<-(n+1)/2<<"\n";
   }
}
