#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
const int tmax=2e7+9;

int idle_A[tmax],idle_B[tmax];
int a[nmax];
int b[nmax];
int n,n2;
int k;
void update_idle(int idle[],int pos,int val){
   int j=n2+pos-1;
   idle[j]=val;
   j>>=1;
   while(j!=0){
      idle[j]=max(idle[j*2],idle[j*2+1]);
      j>>=1;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      cin>>b[i];
   }
   n2=log2(n);
   n2=1<<n2;
   if(n2<n)n2*=2;
   int sum=0;
   for(int i=1;i<=n;i++){
      sum+=max(a[i-1],a[i-1]+b[i-1]-a[i]);
      if(i>1){
         update_idle(idle_A,i-1,max(0,b[i-1]-a[i]));
      }
      update_idle(idle_B,i,max(0,b[i-1]-a[i])+a[i]-b[i-1]);
   }
   sum+=a[n]+b[n];
   update_idle(idle_A,n,b[n]);
   cout<<sum<<" "<<idle_A[1]<<" "<<idle_B[1]<<"\n";
   for(int i=1;i<k;i++){
      int p1,p2;
      cin>>p1>>p2;
      sum-=max(a[p1],a[p1]+b[p1]-a[p1+1]);
      sum-=max(a[p1-1],a[p1-1]+b[p1-1]-a[p1]);
      if(p2>p1+1){
         //sum-=max(a[p2],a[p2]+b[p2]-a[p2+1]);
         sum-=max(a[p2-1],a[p2-1]+b[p2-1]-a[p2]);
      }
      if(p2==n){
         //sum-=max(a[p2-1],a[p2-1]+b[p2-1]-a[p2]);
         sum-=a[p2]+b[p2];
      }
      else{
         sum-=max(a[p2],a[p2]+b[p2]-a[p2+1]);
      }
      swap(a[p1],a[p2]);
      swap(b[p1],b[p2]);
      sum+=max(a[p1],a[p1]+b[p1]-a[p1+1]);
      sum+=max(a[p1-1],a[p1-1]+b[p1-1]-a[p1]);
      if(p2>p1+1){
         //sum-=max(a[p2],a[p2]+b[p2]-a[p2+1]);
         sum+=max(a[p2-1],a[p2-1]+b[p2-1]-a[p2]);
      }
      if(p2==n){
         //sum-=max(a[p2-1],a[p2-1]+b[p2-1]-a[p2]);
         sum+=a[p2]+b[p2];
      }
      else{
         sum+=max(a[p2],a[p2]+b[p2]-a[p2+1]);
      }


      update_idle(idle_A,p1-1,max(0,b[p1-1]-a[p1]));
      update_idle(idle_A,p1,max(0,b[p1]-a[p1+1]));
      update_idle(idle_A,p2-1,max(0,b[p2-1]-a[p2]));
      if(p2<n){
         update_idle(idle_A,p2,max(0,b[p2]-a[p2+1]));
      }
      else{
         update_idle(idle_A,n,b[n]);
      }


      update_idle(idle_B,p1,max(0,b[p1-1]-a[p1])+a[p1]-b[p1-1]);
      update_idle(idle_B,p1+1,max(0,b[p1]-a[p1+1])+a[p1+1]-b[p1]);
      update_idle(idle_B,p2,max(0,b[p2-1]-a[p2])+a[p2]-b[p2-1]);
      if(p2<n){
         update_idle(idle_B,p2+1,max(0,b[p2]-a[p2+1])+a[p2+1]-b[p2]);
      }
      cout<<sum<<" "<<idle_A[1]<<" "<<idle_B[1]<<"\n";
   }
}
