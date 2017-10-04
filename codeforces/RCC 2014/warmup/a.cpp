#include<bits/stdc++.h>
using namespace std;
int c,d;
int n,m,k;
int main()
{
    cin>>c>>d;
    cin>>n>>m;
    cin>>k;
    int people=n*m-k;
    int totna=n*d;
    int tasks=0;
    while(people>0)
    {
        totna=people*d;
        if(totna<c)people-=totna,tasks+=totna;
        else people-=n,tasks+=c;
    }
    cout<<tasks<<endl;
}
