#include<bits/stdc++.h>
using namespace std;
int main(){
   int a,b;
   cin>>a>>b;
   int p[900];
   int idx=b/2+1;
   int pos=1;
   for(int i=1;i<=b;i++){
      p[idx]=i;
      idx+=pos;
      if(pos>0)pos=-pos-1;
      else pos=-pos+1;
   }
   for(int i=1;i<=b;i++){
      if(i<b)cout<<p[i]<<" ";
      else cout<<p[i]<<"\n";
   }
}
