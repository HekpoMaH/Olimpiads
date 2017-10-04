#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 5000
using namespace std;
int a[MAXN],way[2][300000];
bool used[2*MAXN];
int main()
{int i,s,n,k,size,l,p,j,red,h;
scanf("%d %d",&s,&n);
for(i=0;i<n;i++)
{scanf("%d",&a[i]);way[0][i]=a[i];}
if(s==1) {printf("%d\n",1);return 0;}
k=l=0;p=red=1;size=n;
while(1) {
for(i=0;i<size;i++)
for(j=0;j<n;j++)
{h=way[k][i]+a[j];
if(!used[h]){way[p][l]=h;used[h]=true;
if(way[p][l]==s) {printf("%d\n",red+1);return 0;}l++;}}
swap(k,p);size=l;l=0;red++;
}
return 0;
}
