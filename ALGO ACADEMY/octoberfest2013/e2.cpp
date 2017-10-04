#include<bits/stdc++.h>
using namespace std;
int mxn;
bool x[20000000];
int solve()
{
    int last;
    memset(x,false,sizeof(x));
    x[1]=true;
    for(int i=2;i<=mxn;i++)
    {
        if(x[i]==false)
        {
            for(int j=2;j<=mxn/i;j++)if(x[i*j]==false)
            {
                last=i*j;
                x[i*j]=true;
            }
        }
    }
    return last;
}
int main()
{
    cin>>mxn;
    cout<<solve()<<endl;
    //cout<<last<<endl;
}
//0,0,0,4,4,6,6,8,9,9,9,9,9

