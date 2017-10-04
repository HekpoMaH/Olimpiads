#include<bits/stdc++.h>
using namespace std;
const int nmax=100009;
#define pb push_back
vector<int> pr;
int lp[nmax];
int n;
int s[nmax];
int main(){
   cin>>n;
   for(int i=2;i<nmax;i++){
      if(lp[i]==0){
         lp[i]=i;
         pr.pb(i);
      }
      for(int j=0;j<(int)pr.size()&&pr[j]<=lp[i]&&i*pr[j]<nmax;j++){
         lp[i*pr[j]]=pr[j];
         //cout<<"lp["<<i<<"*"<<pr[j]<<"]="<<pr[j]<<"\n";
      }
   }
   //cout<<"primes are:\n";
   //for(int i=0;i<(int)pr.size();i++){
   //   cout<<pr[i]<<" ";
   //   if(pr[i+1]>n)break;
   //}
   //cout<<"\n";
   int p=-1;
   //for(int i=0;i<(int)pr.size();i++){
   //   if(pr[i]>n){
   //      p=pr[i];
   //      break;
   //   }
   //}
   p=*upper_bound(pr.begin(),pr.end(),n);

   assert(p!=-1);
   s[0]=1;
   for(int j=0;j<(int)pr.size();j++){
      for(int i=pr[j];i<=n;i++){
         s[i]=(s[i]+s[i-pr[j]])%p;
      }
   }
   //for(int i=0;i<=n;i++)cout<<s[i]<<" ";
   //cout<<"\n";
   s[n]=(s[n]+p-(lp[n]==n))%p;
   cout<<s[n]<<"\n";
}
