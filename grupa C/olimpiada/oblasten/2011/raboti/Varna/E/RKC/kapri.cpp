#include<iostream>
using namespace std;
int main(){
unsigned long long int k=0,m,i,j,a[100],f=0,p;
int l,t=1,br=0,r,x,n,br1=0,y;
scanf("%u",&n);
for(i=1;i<=n;i++)
{
scanf("%u",&a[i]);
}


for(i=1;i<=n;i++)
{
    m=a[i]*a[i];
for(j=1;j<=m;j*=10)
 {
l++;
 }
 while(br<=l)
 {

 r=m%10;
 m=m/10;
 br++;
 k=k+r*t;
 t=t*10;
}
t=(l-br)*(l-br)*10;
 while(m>0)
 {
x=m%10;
m=m/10;
f=f+x*t;
t=t/10;
 }
if(k+f==a[i])br++;
}
printf("%d\n",br1);
return 0;
}
