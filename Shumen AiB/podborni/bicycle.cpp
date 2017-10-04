#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const double eps=1e-9;
const double inf=1e9;
int n;
double x[nmax];
double v[nmax];
double xmax;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x[i]>>v[i];
      xmax=max(xmax,x[i]);
   }
}
bool chek(double vr){
   double spmn,mn=inf,spmx,mx=-1.0;
   for(int i=1;i<=n;i++){
      if(x[i]+v[i]*vr<mn){
         mn=x[i]+v[i]*vr;
         spmn=v[i];
      }
      if(x[i]+v[i]*vr>mx){
         mx=x[i]+v[i]*vr;
         spmx=v[i];
      }
   }
   if(spmn>spmx)return true;
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   double l,r,mid;
   l=0.0;
   r=2.0*xmax;
   int br=0;
   while(r-l>eps){
      mid=(l+r)/2.0;
      if(chek(mid))l=mid;
      else r=mid;
   }
   double mx=0.0,mn=inf;
   cout<<setiosflags(ios::fixed)<<setprecision(19)<<l<<"\n";
   for(int i=1;i<=n;i++){
      cout<<"i="<<i<<" "<<setiosflags(ios::fixed)<<setprecision(10)<<x[i]+v[i]*l<<" "<<mn<<" "<<mx<<"\n";
      if(x[i]+v[i]*l<mn){
         mn=x[i]+v[i]*l;
      }
      if(x[i]+v[i]*l>mx){
         mx=x[i]+v[i]*l;
      }
   }
   cout<<l<<" ";
   cout<<setiosflags(ios::fixed)<<setprecision(16)<<mx<<" "<<mn<<"\n";
}
