#include<iostream>
#include<algorithm>
using namespace std;
int n,a[12],ans=0,l,r;
void go(int se){
   if(se==n+1){
      ans++;return;
   }
   if(l+a[se]<=r){
      l+=a[se],go(se+1),l-=a[se];
   }
   r+=a[se];
   go(se+1);
   r-=a[se];
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
   do{
      l=0;r=0;
      go(1);
   }while(next_permutation(a+1,a+n+1));
   //go(0,0,0);
   cout<<ans<<endl;
}
