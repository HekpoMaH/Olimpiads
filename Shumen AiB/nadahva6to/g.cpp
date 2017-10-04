#include<bits/stdc++.h>
using namespace std;
struct forma{
   int sum;
   char name;
};
forma f[9];
bool cmp(forma fi,forma se){
   return fi.sum<se.sum;
}
int main(){
   int a,b,c;
   cin>>a>>b;
   f[1].sum=a+b;
   f[1].sum*=2;
   f[1].name='P';
   cin>>a>>b>>c;
   f[2].sum=a+b+c;
   f[2].name='T';
   cin>>a;
   f[3].sum=4*a;
   f[3].name='K';
   sort(f+1,f+4,cmp);
   for(int i=1;i<=2;i++){
      if(f[i].sum==f[i+1].sum){
         cout<<"NO\n";
         exit(0);
      }
   }
   cout<<f[1].name<<" "<<f[2].name<<" "<<f[3].name<<"\n";
}
