#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,r,c,a[130][130],na[130][130],br;
void make()
{
    int brjs;
    memset(na,0,sizeof(na));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            brjs=0;
            if(a[i-1][j]==1)brjs++;
            if(a[i][j-1]==1)brjs++;   
            if(a[i-1][j-1]==1)brjs++;   
            if(a[i+1][j]==1)brjs++;
            if(a[i][j+1]==1)brjs++;   
            if(a[i+1][j+1]==1)brjs++;
            if(a[i-1][j+1]==1)brjs++; 
            if(a[i+1][j-1]==1)brjs++;
            if(a[i][j]==0&&brjs==3)na[i][j]=1;
            if(a[i][j]==1&&(brjs==2||brjs==3))na[i][j]=1;
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            a[i][j]=na[i][j];
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)make();
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(a[i][j]==1)br++;
        }
    }
    cout<<br<<endl;
    return 0;
}