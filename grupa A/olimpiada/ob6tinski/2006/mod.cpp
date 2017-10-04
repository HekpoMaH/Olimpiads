#include<bits/stdc++.h>
using namespace std;
int B;
string A;
int main(){
   cin>>A;
   cin>>B;
   int mod=0;
   //1234567
   //19
   //123/19=mod(9)
   //94/19
   for(int i=0;i<A.size();i++){
      mod=mod*10+A[i]-'0';
      mod%=B;
   }
   cout<<mod<<"\n";
}
