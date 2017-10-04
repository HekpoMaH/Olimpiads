#include<iostream>
using namespace std;
int n,a[10000][3],mbr=99999;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            int br=0;
            for(int k=1;k<=n;k++)
            {
                if(i==0&&a[k][1]==1)br++;
                if(i==1&&a[k][1]==0)br++;
                if(j==0&&a[k][2]==1)br++;
                if(j==1&&a[k][2]==0)br++;
            }
            mbr=min(mbr,br);
        }
    }
    cout<<mbr<<endl;
}
