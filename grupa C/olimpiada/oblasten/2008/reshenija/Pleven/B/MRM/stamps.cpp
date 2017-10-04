#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 5000
using namespace std;
int ar[MAXN],wayr[2][300000];
bool usedr[2*MAXN];
int main()
{int ir,sr,nr,kr,sizer,lr,pr,jr,redr,hr;
scanf("%d %d",&sr,&nr);
for(ir=0;ir<nr;ir++)
{scanf("%d",&ar[ir]);wayr[0][ir]=ar[ir];}
if(sr==1) {printf("%d\n",1);return 0;}
kr=lr=0;pr=redr=1;sizer=nr;
while(1) {
for(ir=0;ir<sizer;ir++)
for(jr=0;jr<nr;jr++)
{hr=wayr[kr][ir]+ar[jr];
if(!usedr[hr]){wayr[pr][lr]=hr;usedr[hr]=true;
if(wayr[pr][lr]==sr) {printf("%d\n",redr+1);return 0;}lr++;}}
swap(kr,pr);sizer=lr;lr=0;redr++;
}
return 0;
}