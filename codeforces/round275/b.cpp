#include<bits/stdc++.h>
using namespace std;
int x,y,cnt1,cnt2;
int main(){
   cin>>cnt1>>cnt2>>x>>y;
   int l=1,r=1e9+9;
   int mid;
   while(l+1<r){
      mid=(l+r)/2;
      cout<<l<<" "<<r<<" "<<mid<<" ne se |x "<<mid-mid/x<<" ne se |y "<<mid-mid/x-mid/y+mid/(x*y)<<"\n";
      if(mid-min(x,mid/x)>=cnt1&&mid-min(x,mid/x)-mid/y>=cnt2){
         //cout<<"less\n";
         r=mid;
      }
      else l=mid;//,cout<<"more\n";
   }
   cout<<r<<"\n";
}
