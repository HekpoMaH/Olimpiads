#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=50050;
int eat[nmax];
int same[nmax];
int eatfun(int s){
   if(eat[s]!=s)eat[s]=eatfun(eat[s]);
   return eat[s];
}
int samefun(int s){
   if(same[s]!=s)same[s]=samefun(same[s]);
   return same[s];
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      int n;
      int cases;
      cin>>n;
      for(int j=1;j<=n;j++)same[j]=j,eat[j]=j;
      cin>>cases;
      int sum=0;
      for(int u=0;u<cases;u++){
         lli opt,x,y;
         cin>>opt>>x>>y;
         if(opt==1){
            if(x>n || y>n){
               sum++;
               continue;
            }
            if(x==y)continue;
            int kk=eatfun(x);
            int uu=eatfun(y);
            if(kk==uu){
               sum++;
               continue;
            }
            else same[kk]=uu;
         }
         else{
            if(x>n || y>n){
               sum++;
               continue;
            }
            if(x==y){
               sum++;
               continue;
            }
            int kk=samefun(x);
            int uu=samefun(y);  
            if(kk!=uu){
               eat[kk]=uu;
               continue;
            }    
            else{
               sum++;
            }    
         }
      }
      cout<<sum<<"\n";
   }
   return 0;
}
