#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int n,p,k;
int a[nmax];
int wtf[nmax];
int col,me;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>p>>k;
   int rest=n-1;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   col=0;
   for(int i=1;i<=n;i++){
      if((a[i]>a[p])||((a[i]==a[p])&&(i>=p))){
         col++;
         wtf[col]=i;
      }
      if(i==p){
         me=col;
      }
   }
   string res="";
   int dist=wtf[1];
   for(int i=1;i<me;i++){
      dist+=wtf[i+1]-wtf[i]-1;
      res+='-';
      rest--;
   }
   wtf[col+1]=n+1;
   int i=me;
   while(rest!=0){
      if(k>=rest){
         k--;
         res+='+';
      }
      else{
         res+='-';
         if(i<col)
            dist+=wtf[i+1]-wtf[i]-1;
         i++;
      }
      rest--;
   }
   cout<<dist<<"\n";
   cout<<res<<"\n";
}
