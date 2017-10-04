#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
const int inf=1e9;
int n,k,sum[nmax],ans[nmax][nmax],p[nmax][nmax];
string s,res;
int br;
int main(){
   cin>>br;
   for(int i=1;i<=br;i++){
      cin>>n>>k>>s;
      ans[1][1]=0;
      res="";
      for(int i=1;i<=n;i++){
         sum[i]=sum[i-1]+s[i-1]-'0';
         ans[0][i]=inf;
      }
      for(int blocks=1;blocks<=k;blocks++){
         ans[blocks][0]=0;
         for(int i=1;i<=n;i++){
            ans[blocks][i]=inf;
            for(int j=0;j<i;j++){
               if(ans[blocks][i]>ans[blocks-1][j]+min(sum[i]-sum[j],i-j-(sum[i]-sum[j]))){
                  ans[blocks][i]=ans[blocks+1][j]+min(sum[i]-sum[j],i-j-(sum[i]-sum[j]));
                  p[blocks][i]=j;
               }
            }
         }
      }
      int blocks=k,i=n;
      for(int i=0;i<n;i++)res+='0';
      while(i>0){
         int j=p[blocks][i];
         if(sum[i]-sum[j]>(i-j)-(sum[i]-sum[j])){
            for(int k=j;k<i;k++)res[k]='1';
         }
         i=j;
         blocks--;
      }
      cout<<res<<"\n";
   }
}
