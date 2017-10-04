#include<bits/stdc++.h>
using namespace std;
const int nmax=300;
int b[nmax],bb[nmax];
int n;
string num;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>b[i];
      bb[i]=b[i];
   }
   string lastnum="";
   int lastsum=0;
   for(int i=1;i<=n;i++){
      num="";
      int sum=0;
      if(b[i]>bb[i-1])for(int j=0;j<(int)lastnum.size()-1;j++){
         ///cout<<j<<"\n";
         num+=lastnum[j],sum+=lastnum[j]-'0';
      }
      if(b[i]<bb[i-1]){
         num+='1';
         b[i]--;
      }
      if(b[i]%9!=0)num+=b[i]%9+'0',b[i]-=b[i]%9;
      b[i]-=sum;
      while(b[i]!=0){
         if(b[i]>=9){
            lastsum+=9;
            b[i]-=9;
            num+='9';
         }
         else{
            lastsum+=b[i];
            num+=char(b[i]+'0');
            b[i]=0;
         }
      }
      int l=0;
      while(num.size()<lastnum.size())num+='0',l=1;
      if(l==1)if(lastnum[lastnum.size()-1]>'0')num+='0';
      if(lastnum==num)num+='0';
      cout<<num<<"\n";
      lastnum=num;
   }
}
