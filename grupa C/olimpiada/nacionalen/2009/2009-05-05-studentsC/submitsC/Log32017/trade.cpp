/*
TASK: trade
LANG: C++
*/
#include<iostream>
using namespace std;
double s,s1,a[100001][3],z,b[100001];
long ok,i,n,x,y,j;
int main()
 {
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
  if(i%2==0) s+=a[i][2];
  else s1+=a[i][2];
  }
 if(n%2==0) if(s1!=s) ok=1;
            else ok=2;
 else
 {b[long(a[1][0])]=s1-s;
  i=1;j=0;
  for(i=1;i<n;i++)
  b[long(a[i][1])]=2*a[i][2]-b[long(a[i][0])];
   if(b[long(a[n][0])]+b[long(a[n][1])]==2*a[n][2]) ok=1;
 }
 if(ok==0)
 {for(i=1;i<n;i++)
  printf("%.2lf ",b[i]);
 printf("%.2lf\n",b[n]);
 }
 if(ok==1) cout<<"impossible"<<endl;
 if(ok==2) cout<<"too many"<<endl;
 //system("PAUSE");
 return 0;
 }
