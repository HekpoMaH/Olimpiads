#include<iostream>
using namespace std;
const int nmax=1e4+9;
int n,k;
int a[nmax];
bool chek(int x){
   //cout<<"cheking for "<<x<<"\n";
   int br=1;
   int lasc=a[1];
   //cout<<"  we put cow at "<<lasc<<"\n";
   for(int i=2;i<=n;i++){
      if(a[i]-lasc>=x){
         br++;
         lasc=a[i];
         //cout<<"  we put cow at "<<lasc<<"\n";
      }
   }
   //cout<<"  cows all "<<br<<"\n";
   return br>=k;
}
int main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   int l=1,r=1e9+9;
   while(l+1<r){
      int mid=(l+r)/2;
      //cout<<"l,r,mid-> "<<l<<" "<<r<<" "<<mid<<"\n";
      //cout<<chek(mid)<<"\n";
      if(chek(mid))l=mid;
      else r=mid;
   }
   cout<<l<<"\n";
}
