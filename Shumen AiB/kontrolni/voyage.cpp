#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
const lli inf=1e18;
lli a[13];
lli n,m,s1=0,i,s2=0,s3=0,s4=0,p,s,mi;
int main(){
   cin>>m>>n;
   for(i=0;i<n;i++){
      cin>>s>>p;
      s=s*100+p;
      if((5-(p%5))%5==1 && (s1==0|| s1>s))s1=s;
      if((5-(p%5))%5==2 && (s2==0 || s2>s))s2=s;
      if((5-(p%5))%5==3 && (s3==0|| s3>s))s3=s;
      if((5-(p%5))%5==4 && (s4==0 || s4>s))s4=s;
   }
   if(n!=0 && s1==0 && s2==0 && s3==0 && s4==0){
      cout<<-1<<endl;
      return 0;
   }
   for(i=1;i<=12;i++)
   a[i]=1e18;
   //for(i=1;i<=12;i++)cout<<a[i]<<" ";
   //cout<<endl;
   for(i=1;i<=12;i++)
   if(s1!=0)a[i]=s1+a[i-1];
   //for(i=1;i<=12;i++)cout<<a[i]<<" ";
   //cout<<endl;
   for(i=2;i<=12;i++)
   if((s2+a[i-2]<a[i]) && s2!=0 && a[i-2]!=inf)a[i]=s2+a[i-2];
   //for(i=1;i<=12;i++)cout<<a[i]<<" ";
   //cout<<endl;
   for(i=3;i<=12;i++)
   if((s3+a[i-3]<a[i]) && s3!=0 && a[i-3]!=inf)a[i]=s3+a[i-3];
   //for(i=1;i<=12;i++)cout<<a[i]<<" ";
   //cout<<endl;
   for(i=4;i<=12;i++)
   if((s4+a[i-4]<a[i]) && s4!=0 && a[i-4]!=inf)a[i]=s4+a[i-4];
   //for(i=1;i<=12;i++)cout<<a[i]<<" ";
   //cout<<endl;
   unsigned long long o=(m/12)*a[12];
   mi=inf;
   for(i=m%12;i<=12;i++)mi=min(mi,a[i]);
   if(m%12!=0)o+=mi;
   cout<<o/100<<" "<<o%100<<endl;
}
