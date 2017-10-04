#include<bits/stdc++.h>
using namespace std;
short v[2][900];
int br,a,b;
map<int,bool> ma;
inline void chek(int x){
   if(x<a||x>b||ma.find(x)!=ma.end())return;
   ma[x]=1;
   for(int i=2;i*i<=x;i++){
      if(x%i==0)return;
   }
   br++;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int m=0,p1,p2=0;
   cin>>a>>b;
   for(int i=1;i<=26;i++){//2^26>50e6
      p1=0;
      for(int j=1<<((i>>1)+(i&1));j<(1<<((i>>1)+(i&1)+1));j++){
         int k;
         for(k=2;k*k<=j;k++){
            if(j%k==0)break;
         }
         if(k*k==j)v[i&1][p1++]=j;
      }
      for(int j=0;j<p1;j++){
         for(int k=0;k<p2;k++){
            chek((v[(i+1)&1][k]<<((i>>1)+(i%2))+1)+v[i&1][j]);
            chek((v[i&1][j]<<((i>>1)+1))+v[(i+1)&1][k]);
         }
      }
      swap(p1,p2);
   }
   cout<<br<<"\n";
}
