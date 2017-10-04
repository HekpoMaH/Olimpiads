#include<iostream>
using namespace std;
int main(){
int n,m,x,y;
scanf("%d%d",&n,&m);
x=y;
x=150/(m+n);
if(150%(m+n)==0)
{
printf("%d\n",x*2);
}
else printf("%d\n",x*2+2);
return 0;
}
