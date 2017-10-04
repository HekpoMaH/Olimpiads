#include<iostream>
#include<math.h>
using namespace std;
int d[101];
main()
{int r,m,p,i,f,j,z;double a,b;
string k;double c;int d[101];
cin>>a>>b;
cin>>k>>p;
r=k.length();z=a;m=b;
int h[r],v=0,br=r-1;
for(i=0;i<r;i++){h[i]=k[i]-'0';}
do{c=a/b;}while(z%m==0);
c=a/b;
for(i=0;i<r+p+1;i++){c=c*10;
d[i]=c;}
for(i=0;i<r;i++){
v=v+h[i]*pow(10,br);br--;}
cout<<d[v+p-2]<<endl;
return 0;
}
