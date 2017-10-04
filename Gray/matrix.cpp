#include<bits/stdc++.h>
using namespace std;
int n,m,step=1,br;
vector<int> v[1024*512+19];
int g(int n)
{
    return n^(n>>1);
}
int main()
{
    cin>>n>>m;
    int j;
    for(int i=1;i<=(1<<m);i++)
    {
        if(step==1)
        j=1;
        else j=(1<<n);
        while(j>=1&&j<=(1<<n))
        {

            v[j].push_back(g(br));
            //cout<<j<<" "<<i<<" "<<br<<" "<<g(br)<<endl;
            j+=step;br++;

        }
        step=-step;
    }
    for(int i=1;i<=(1<<n);i++)
    {
        for(j=0;j<(1<<m);j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
