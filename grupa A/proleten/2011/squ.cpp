#include<iostream>
//#include<cmath>
#include<algorithm>
using namespace std;
const int nmax=1e5+9;
typedef long lli;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   lli a[nmax];
   cin>>n;
   lli k;
   lli sum1=0;
   int i;
   for(i=1;i<=n;i++){
      cin>>a[i];
      sum1+=a[i];
   }
   a[1]=0;
   k=sum1/n;
   for(i=2;i<=n;i++){
      a[i]=a[i-1]+k-a[i];
   }
   sort(a+1,a+n+1);
   //lli x=a[(n+1)/2];
   lli sum=0;
   int t=(n+1)/2;
   for(i=1;i<t;i++){
      sum-=a[i];
   }
   for(i=t+1;i<=n;i++){
      sum+=a[i];
   }
   if(!(n&1))sum-=a[t];
   cout<<sum<<"\n";
}
