#include<iostream>
using namespace std;
int a[4],n,br,br1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        br=0;
        for(int j=1;j<=3;j++)
        {
            cin>>a[j];
            if(a[j]==1)br++;
        }
        if(br>1)br1++;
    }
    cout<<br1<<endl;
    return 0;
}
