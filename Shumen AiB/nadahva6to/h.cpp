#include<bits/stdc++.h>
using namespace std;
struct forma{
   int sum;
   int name;
};
forma f[9];
bool cmp(forma fi,forma se){
   if(fi.sum>se.sum)return true;
   if(fi.sum<se.sum)return false;
   return fi.name<se.name;
}
int main(){
   int a,b,c;
   int m,n,q;
   cin>>a>>b>>c;
   cin>>m>>n>>q;
   f[1].sum=a+m;
   f[1].name=1;
   f[2].sum=b+n;
   f[2].name=2;
   f[3].sum=c+q;
   f[3].name=3;
   sort(f+1,f+4,cmp);
   f[0].sum=f[1].sum;
   for(int i=1;i<=3;i++){
      if(f[i].sum==f[i-1].sum){
         cout<<f[i].name<<" ";
      }
      else break;
   }
   cout<<"\n";
}
