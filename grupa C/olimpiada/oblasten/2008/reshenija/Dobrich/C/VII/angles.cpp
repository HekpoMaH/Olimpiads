#include<iostream.h>

int main()
{
int a[700][700],n,l,m,k,i,j,summax,sum,kor1,kor2;
cin>>n>>k;
for(i=0;i<700;i++)
   for(j=0;j<700;j++){a[i][j]=0;}

for(i=0;i<n;i++){
   for(j=0;j<n;j++){
      cin>>a[i][j];
      }
   }
sum=0;
summax=-9999;
for(i=0;i<n;i++){
   for(j=0;j<n;j++){
      m=i+1;
      l=j;
      sum=0;
      while((m<n)&&(m<=i+k)){sum=sum+a[m][l];m++;}
      m=i;
      l=j+1;
      while((l<n)&&(l<=j+k)){
         sum=sum+a[m][l];
         l++;
         }
      sum=sum+a[i][j];
      if(sum>summax){summax=sum; kor1=i;kor2=j;}
      }
   }
cout<<kor1+1<<" "<<kor2+1;
}
