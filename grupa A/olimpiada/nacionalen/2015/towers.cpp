#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int m;
int p[nmax];
void reassign(){
   for(int i=0;i<m-1;i++){
      if(p[i]>=p[m-1])p[i]++;
   }
}
void add(int l){
   int k=0;
   int i=m-1;
   while(l){
      if(p[i]>k){
         k=p[i];
         l--;
      }
      i--;
   }
   p[m++]=k+1;
   reassign();
}
int main(){
   int n,l;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>l;
      add(l);
   }
   for(int i=0;i<m;i++){
      cout<<p[i]<<"\n";
   }
}
