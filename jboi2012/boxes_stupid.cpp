#include<iostream>
using namespace std;
int used[9];
int boxes[100][9],n,mx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            cin>>boxes[i][j];
            used[boxes[i][j]]++;
        }
    }
    mx=used[1];int mi,fl=0;
    for(int i=0;i<=6;i++)
    {
       if(used[i]>mx)
       {
           if(used[i]!=n&&used[i]!=0)fl=1;
           mx=used[i];
           mi=i;
       }
    }
    if(fl==0){cout<<0<<endl;return 0;}
    int br=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(boxes[i][j]!=mi)br++;
        }
    }
    cout<<br<<endl;
    return 0;
}