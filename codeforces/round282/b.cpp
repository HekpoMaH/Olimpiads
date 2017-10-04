#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long fa,fb;
vector<long long> dv;
void fdif(long long x){
   for(long long i=1;i*i<=x;i++){
      if(x%i==0)dv.push_back(i);
      if(x%i==0)if(i!=x/i)dv.push_back(x/i);
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>a>>b;
   fa=a;fb=b;
   if(a==b){
      cout<<"infinity\n";
      exit(0);
   }
   if(a<b){
      cout<<0<<"\n";
      exit(0);
   }
   b=a-b;
   fdif(b);
   long long br=0;
   for(long long i=0;i<dv.size();i++){
      //cout<<a<<" "<<b<<" "<<dv[i]<<"\n";
      if(fa/dv[i]==b/dv[i])br++;//,cerr<<dv[i]<<"\n";
   }
   cout<<br<<"\n";
}
