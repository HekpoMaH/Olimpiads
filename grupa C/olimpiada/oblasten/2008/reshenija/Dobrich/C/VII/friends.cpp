#include<iostream.h>

int main()
{
int a[2000],b[2000],c[2000],n,m,i,l,k,j,sum=0,maxsum=0;
cin>>n>>m;
for(i=0;i<2000;i++){a[i]=0;b[i]=0;c[i]=0;}
b[1]=1;
for(i=0;i<m;i++){
   cin>>k>>l;
   if(b[l]==0){b[l]=1;c[l]=k;a[k]++;}
   }
for(i=0;i<2000;i++){
   sum=0;
   for(j=0;j<2000;j++){
      if(c[i]==c[j]) sum=sum+a[j];
      }
   if(sum>maxsum) maxsum=sum;
   }
cout<<maxsum;

}
