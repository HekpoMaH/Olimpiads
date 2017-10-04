#include<iostream>
using namespace std;
int k;
int m[10][1000],mn,md;
int main()
{
    cin>>k;
    mn=k+2;
    for(int d=1;d<=9;d++)
    {
        for(int j=1;j<=k;j++)
        {
            m[d][j]=(m[d][j-1]*10+d)%k;
            if(m[d][j]==0)
            {
                if(j<mn)
                {
                    mn=j;
                    md=d;
                }
            }
        }
    }
    if(mn==k+2){cout<<"Impossible"<<endl;return 0;}
    cout<<md<<" "<<mn;
    cout<<endl;
}
