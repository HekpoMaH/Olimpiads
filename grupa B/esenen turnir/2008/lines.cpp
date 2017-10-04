#include<bits/stdc++.h>
using namespace std;
int x[600009];
int y[600009];
int main()
{
    int x0,x1,y0,y1;
    int n;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x0>>y0>>x1>>y1;
        if(x0<x1)
        {
            x[2*i]=2*x0;
            x[2*i+1]=2*x1+1;
        }
        else x[2*i]=2*x1,x[2*i+1]=2*x0+1;
        if(y0<y1)
        {
            y[2*i]=2*y0;
            y[2*i+1]=2*y1+1;
        }
        else y[2*i]=2*y1,y[2*i+1]=2*y0+1;

    }
    sort(x,x+2*n);
    sort(y,y+2*n);
    //reverse(x,x+2*n);reverse(y,y+2*n);
    int sx=0,sy=0;
    int mx=-1;
    for(int i=0;i<2*n;i++)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(x[i]%2)sx--;
        else sx++,mx=max(mx,sx);
        if(y[i]%2)sy--;
        else sy++,mx=max(mx,sy);
    }
    cout<<mx<<endl;
}
