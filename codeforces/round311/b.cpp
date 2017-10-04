#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
const int nmax=2*1e5+9;
const double eps=1e-7;
int n;
double w;
double a[nmax];
double lef=0.0,righ;
bool chek(double x){
   if(x>eps+w)return false;
   double grl=x/(3.0*n);
   double boy=2.0*grl;
   bool used[nmax];
   memset(used,0,sizeof(used));
   int br=0;
   for(int i=1;i<=2*n;i++){
      if(used[i]==0&&a[i]>grl+eps){
         used[i]=1;
         br++;
      }
      if(br==n)break;
   }
   if(br<n)return false;
   br=0;
   for(int i=1;i<=2*n;i++){
      if(used[i]==0&&a[i]>boy+eps){
         used[i]=1;
         br++;
      }
      if(br==n)break;
   }
   if(br<n)return false;
   return true;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin>>n>>w;
   for(int i=1;i<=2*n;i++){
      cin>>a[i];
   }
   sort(a+1,a+2*n+1);
   righ=w+eps;
   while(righ-lef>eps){
      double mid=(lef+righ)/2.0;
      if(chek(mid))lef=mid;
      else righ=mid;
   }
   cout<<lef<<"\n";
}

