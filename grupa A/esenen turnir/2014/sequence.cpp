#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli a[1000009];
bool rem[1009];
lli x[10];
lli ans,mx1=0;
int n,current,br;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x[i];
      mx1=max(mx1,x[i]);
   }
   if(n==2){
      cout<<x[1]*x[2]-x[1]-x[2]<<"\n";
      return 0;
   }
   if(mx1<1000){
      for(int i=1;i<=n;i++){
         a[x[i]]=1;
      }
      current=1;
      br=0;
      while(br<x[1]){
         current++;
         if(a[current]){
            br++;
            for(int i=1;i<=n;i++){
               a[current+x[i]]=1;
            }
         }
         else br=0;
      }
      ans=current-x[1];
      cout<<ans<<"\n";
      return 0;
   }
   lli x12=x[2]*x[1]-x[2];
   br=0;
   if(n==3){
      for(int i2=0;x[2]*i2<=x12;i2++){
         for(int i3=0;x[2]*i2+x[3]*i3<=x12;i3++){
            a[br]=x[2]*i2+x[3]*i3;
            br++;
         }
      }
   }
   if(n==4){
      for(int i2=0;x[2]*i2<=x12;i2++){
         for(int i3=0;x[2]*i2+x[3]*i3<=x12;i3++){
            for(int i4=0;x[2]*i2+x[3]*i3+x[4]*i4<=x12;i4++){
               a[br]=x[2]*i2+x[3]*i3+x[4]*i4;
               br++;
            }
         }
      }
   }
   if(n==5){
      for(int i2=0;x[2]*i2<=x12;i2++){
         for(int i3=0;x[2]*i2+x[3]*i3<=x12;i3++){
            for(int i4=0;x[2]*i2+x[3]*i3+x[4]*i4<=x12;i4++){
               for(int i5=0;x[2]*i2+x[3]*i3+x[4]*i4+x[5]*i5<=x12;i5++){
                  a[br]=x[2]*i2+x[3]*i3+x[4]*i4+x[5]*i5;
                  br++;
               }
            }
         }
      }
   }
   sort(a,a+br);
   current=1;
   int numrem=x[1]-1;
   while(numrem>0){
      int rest=a[current]%x[1];
      if(rest&&!rem[rest]){
         rem[rest]++;
         numrem--;
      }
      current++;
   }
   current--;
   ans=a[current]-x[1];
   cout<<ans<<"\n";
}
