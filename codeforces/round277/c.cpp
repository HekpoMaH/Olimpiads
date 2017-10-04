#include<bits/stdc++.h>
using namespace std;
int m,s;
int a[109];
int amin[109];
int amax[109];
int main(){
   cin>>m>>s;
   if(s==0&&m>1){
      cout<<"-1 -1\n";
      exit(0);
   }
   if(s==0&&m==1){
      cout<<"0 0\n";
      exit(0);
   }
   int li=m+1,sum=0,sum2=0;
   a[1]=0;
   for(int i=2;i<=m;i++)a[i]=0;
   for(int i=m;i>=1;i--){
      if(abs(s-sum)<=9){
         break;
      }
      li=i;
      a[i]=9;
      sum+=9;
   }
   sum2=sum;
   for(int i=1;i<=m;i++)
      amin[i]=a[i],amax[i]=a[i];
   if(a[1]==9&&sum<s){
      cout<<"-1 -1\n";
      exit(0);
   }
   if(li-1>1){amin[1]=1;
   sum++;}
   if(li-1>=1)amin[li-1]=s-sum;
   //for(int i=li-1;i>=1;i--){
   //   //cout<<i<<"\n";
   //   if(sum<s)amin[i]=1,sum++;
   //   else break;
   //}
   for(int i=1;i<=m;i++)
      cout<<amin[i];
   cout<<" ";
   sum=sum2;
   amax[li-1]=s-sum;
   sort(amax+1,amax+m+1);
   reverse(amax+1,amax+m+1);
   for(int i=1;i<=m;i++)
      cout<<amax[i];
   cout<<"\n";
}
