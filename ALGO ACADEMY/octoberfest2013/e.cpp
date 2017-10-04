#include<bits/stdc++.h>
using namespace std;
int mxn;
bool x[200000000];
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
    ofstream fout("otgovori.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=20000000;i++)
    {
        mxn=i;
        fout<<"ans["<<i<<"]="<<solve()<<"\n";
    }
    //cout<<last<<endl;
}
//0,0,0,4,4,6,6,8,9,9,9,9,9
