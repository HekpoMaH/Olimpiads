#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=10100;
int n,m;
vector<int>v[MAXN],path;
int a[MAXN],used[MAXN],prev[MAXN];
void readInput()
{
    int i,num,pos=0,br=0,back=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
}
bool is_palindrom(int i,int j)
{
    while(i<=j) {
        if(a[i]!=a[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
void solve()
{
    int i,j,s,k,t,f,r,l=0;
    for(i=2;i<=n;i++)
    if(a[i]!=a[i-1]) {
        l=1;
        break;
    }
    if(l==0) {
        printf("1\n");
        return;
    }
    for(i=1;i<=n;i++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,n)) {
        printf("2\n");
        printf("%d\n",i);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=2;j<=n;j++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,n)) {
        printf("3\n");
        printf("%d %d\n",i,j);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    for(s=j+1;s<=n;s++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,s)&&is_palindrom(s+1,n))
    {
        printf("4\n");
        printf("%d %d %d\n",i,j,s);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    for(s=j+1;s<=n;s++)
    for(k=s+1;k<=n;k++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,s)&&is_palindrom(s+1,k)&&is_palindrom(k+1,n))
    {
        printf("5\n");
        printf("%d %d %d %d\n",i,j,s,k);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    for(s=j+1;s<=n;s++)
    for(k=s+1;k<=n;k++)
    for(t=k+1;t<=n;t++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,s)&&is_palindrom(s+1,k)&&is_palindrom(k+1,t)&&is_palindrom(t+1,n))
    {
        printf("6\n");
        printf("%d %d %d %d %d\n",i,j,s,k,t);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    for(s=j+1;s<=n;s++)
    for(k=s+1;k<=n;k++)
    for(t=k+1;t<=n;t++)
    for(f=t+1;f<=n;f++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,s)&&is_palindrom(s+1,k)&&is_palindrom(k+1,t)&&is_palindrom(t+1,f)&&is_palindrom(f+1,n))
    {
        printf("7\n");
        printf("%d %d %d %d %d %d\n",i,j,s,k,t,f);
        return;
    }
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    for(s=j+1;s<=n;s++)
    for(k=s+1;k<=n;k++)
    for(t=k+1;t<=n;t++)
    for(f=t+1;f<=n;f++)
    for(r=f+1;r<=n;r++)
    if(is_palindrom(1,i)&&is_palindrom(i+1,j)&&is_palindrom(j+1,s)&&is_palindrom(s+1,k)&&is_palindrom(k+1,t)&&is_palindrom(t+1,f)&&is_palindrom(f+1,r)&&is_palindrom(r+1,n))
    {
        printf("8\n");
        printf("%d %d %d %d %d %d %d\n",i,j,s,k,t,f,r);
        return;
    }
}
int main()
{
    readInput();
    if(n==1||n==2) {
        printf("1\n");
        return 0;
    }
    solve();
    return 0;
}
