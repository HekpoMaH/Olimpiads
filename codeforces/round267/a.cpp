#include<bits/stdc++.h>
using namespace std;
int n;
int p,q;
int br;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>p>>q;
      q-=p;
      if(q>=2)br++;
   }
   cout<<br<<endl;
}
