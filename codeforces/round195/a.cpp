#include<bits/stdc++.h>
using namespace std;
long long x,y,nx,ny,nnx,nny;
int main()
{
    cin>>x>>y;
    if(x>0&&y>0)
    {

        cout<<0<<" "<<x+y<<" "<<x+y<<" "<<0<<endl;
        return 0;
    }
    if(x>0&&y<0)
    {

        cout<<0<<" "<<-(x+(-y))<<" "<<x+(-y)<<" "<<0<<endl;
        return 0;
    }
    if(x<0&&y>0)
    {cout<<-(-x+(y))<<" "<<0<<" "<<0<<" "<<(-x+(y))<<endl;
        //cout<<0<<" "<<-x+y<<" "<<-(-x+y)<<" "<<0<<endl;
        return 0;
    }
    if(x<0&&y<0)
    {
        cout<<-(-x+(-y))<<" "<<0<<" "<<0<<" "<<-(-x+(-y))<<endl;
        return 0;
    }
}
