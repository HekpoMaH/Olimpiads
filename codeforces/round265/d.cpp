#include<bits/stdc++.h>
using namespace std;
int a[9][9];
typedef long long lli;
lli b[8];
lli dis(int i,int j){
   lli x[3];
   for(int ih=0;ih<3;ih++){
      x[ih]=a[i][ih]-a[j][ih];
   }
   return x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
}
bool check(){
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
         if(i==j)continue;
         if(j<i)b[j]=dis(i,j);
         if(j>i)b[j-1]=dis(i,j);
      }
      sort(b,b+7);
      lli t1=b[0],t2=2*t1,t3=3*t1;
      if(t1==0||t1!=b[1]||t1!=b[2]||t2!=b[3]||t2!=b[4]||t2!=b[5]||t3!=b[6])return false;
   }
   return true;
}
bool possib(int i){
   if(i==8)return check();
   sort(a[i],a[i]+3);
   do{
      if(possib(i+1))return true;
   }while(next_permutation(a[i],a[i]+3));
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   for(int i=0;i<8;i++){
      for(int j=0;j<3;j++){
         cin>>a[i][j];
      }
   }
   if(!possib(0))cout<<"NO\n";
   else{
      cout<<"YES\n";
      for(int i=0;i<8;i++){
         for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
         }
         cout<<"\n";
      }
   }
}
