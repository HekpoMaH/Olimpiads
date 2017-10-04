#include<iostream>
using namespace std;
int n,k,supsum[16][16],zpr;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int f=1;f<=j;f++)
            {
                if(i-1==0)zpr=f;
                else zpr=supsum[i-1][f];
                //cout<<zpr<<endl;
                supsum[i][j]+=zpr;
            }
            //cout<<i<<" "<<j<<" "<<supsum[i][j]<<endl<<"-----"<<endl;
        }
    }
    cout<<supsum[n][k]<<endl;
    return 0;
}