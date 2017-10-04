#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
   cin>>n;
   int br=0;
   for(long long i=1;i<=n;i++){
      if(!(n%i))br++;
   }
   cout<<br<<"\n";
}
