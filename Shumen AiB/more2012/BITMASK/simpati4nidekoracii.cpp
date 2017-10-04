#include<iostream>
using namespace std;
int a[30][1<<6],n,m,p[1<<6][1<<6];
long long br;
bool check(int m1,int m2)
{
    int pos1,pos2,pos3,pos4;
    if(p[m1][m2]==1)return true;
    if(p[m1][m2]==-1)return false;
    for(int j=0;j<n-1;j++)
    {
        pos1=m1&(1<<j);pos2=m1&(1<<(j+1));pos3=m2&(1<<j);pos4=m2&(1<<(j+1));
        //cout<<pos1<<" "<<pos2<<" "<<pos3<<" "<<pos4<<endl;
        if(pos1==0&&pos2==0&&pos3==0&&pos4==0){p[m1][m2]=-1;return false;}
        if(pos1!=0&&pos2!=0&&pos3!=0&&pos4!=0){p[m1][m2]=-1;return false;}
    }
    p[m1][m2]=1;
    return true;
}
int main()
{
    cin>>n>>m;
    if(n>m)swap(n,m);
    for(int i=0;i<1<<n;i++)
    {
        a[1][i]=1;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<1<<n;j++)
        {
            for(int k=0;k<1<<n;k++)
            {
                if(check(k,j))a[i][j]+=a[i-1][k];
            }
        }
    }
    //cout<<check(0,1)<<endl;
    for(int i=0;i<1<<n;i++)br+=a[m][i];
    cout<<br<<endl;
    return 0;
}