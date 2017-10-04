//finding all reverse elements in interval [1,m-1]
//notice that m should be prime
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int r[nmax],m;
int main(){
   cin>>m;
   r[1]=1;
   for(int i=2;i<m;i++){
      r[i]=(m-(m/i)*r[m%i]%m)%m;
   }
   for(int i=1;i<m;i++){
      cout<<r[i]<<" ";
   }
   cout<<"\n";
}
