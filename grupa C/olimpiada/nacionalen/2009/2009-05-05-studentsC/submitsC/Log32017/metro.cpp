/*
TASK: metro
LANG: C++
*/
#include<iostream>
using namespace std;
long n,i,j,k,s,br=-1,s1,a[1024],b[1024];
long br1()
{
long br=0;
for(i=1;i<=n;i++)
{if(a[i]==b[i]-1||a[i]==b[i]) br+=1;
 if(a[i]==b[i]-2) br+=4;
 if(a[i]==b[i]+1) br+=7;
}
return br;
}
void p(long x, long s)
{b[x]=j;
 if(x==n) {s1=br1();;if(br==-1||s1<br) br=s1;return;}
 if((j-2==a[x]||j-1==a[x]||j==a[x])&&j<=a[x+1]) {j++;p(x+1,s+7);j--;}
 if(j<=a[x+1]&&(j==a[x]-1||j==a[x]-2)) {j++;p(x+1,s+7);j--;}
 if(j+2==a[x+1]||j-1==a[x+1]||j==a[x+1]) p(x+1,s+1);
 if(j>=a[x+1]) {j--;p(x+1,s+1);j++;}
 if(j>=a[x+1]) {j-=2;p(x+1,s+4);j+=2;}
}
int main()
 {
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 j=a[1];
 a[n+1]=a[n];
 p(0,0);
 cout<<br<<endl;
 //system("PAUSE");
 return 0;
 }
