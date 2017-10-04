#include<iostream>
using namespace std;
int roses[1000][1000];
int main()
{
    long long sum=0, max=-1, current=0;
    int m, n, k;
    cin>>m>>n>>k;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            cin>>roses[a][b];
            sum=sum+roses[a][b];
        }
    }
    for(int a=0; a<=m-k; a++)
    {
        for(int b=0; b<=n-k; b++)
        {
            for(int c=a; c<a+k; c++)
            {
                for(int d=b; d<b+k; d++)
                {
                    current=current+roses[c][d];
                }
            }
            if(max<current) max=current;
            current=0;
        }
    }
    cout<<sum-max<<endl;
    return 0;
}
