#include<bits/stdc++.h>
using namespace std;
const int nmax=5*1e5+9;
long long psum[nmax];
int a;
int n;
vector<int> idx;
vector<int> idx2;

int main(){
   ios_base::sync_with_stdio(false);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a;
      psum[i]=psum[i-1]+a;
   }
   if(psum[n]%3!=0){
      cout<<0<<"\n";
      return 0;
   }
   long long part1=psum[n]/3;
   int lb1,ub1,lb2,ub2;
   long long part2=part1*2;
   for(int i=1;i<n;i++){
      //cout<<i<<" "<<psum[i]<<" "<<part1<<" "<<part2<<"\n";
      if(psum[i]==part1)idx.push_back(i);
      if(psum[i]==part2)idx2.push_back(i);
   }
   long long ans=0;
   //cout<<idx2.size()<<"\n";
   //cout<<endl;
   //for(int i=0;i<idx2.size();i++)cout<<idx2[i]<<" ";
   //cout<<endl<<idx.size()<<"\n";
   //cout<<endl;
   //for(int i=0;i<idx.size();i++)cout<<idx[i]<<" ";
   //cout<<"\n";
   for(int i=0;i<idx.size();i++){
      //cout<<idx[i]<<" "<<idx2.end()-lower_bound(idx2.begin(),idx2.end(),idx[i]+1)<<"\n";
      ans+=idx2.end()-lower_bound(idx2.begin(),idx2.end(),idx[i]+1);
   }
   cout<<ans<<"\n";
}
