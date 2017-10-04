#include<iostream>
using namespace std;
int x,y,dx=1,dy,tms=1,br,turns,br2,l;
int mxx,mnx=101,mxy=-101,mny=101,a=0,b=0;
int used[222][222];
int main()
{
    ios::sync_with_stdio(false);
    cin>>x>>y;a=x,b=y;
    x=0,y=0;
    do
    {
        if(br==tms)
        {
            if(dx==1)dx=0,dy=1,turns++;
            else if(dy==1)dy=0,dx=-1,tms++,turns++;
            else if(dx==-1)dx=0,dy=-1,turns++;
            else if(dy==-1)dy=0,dx=1,tms++,turns++;
            br=0;
        }

        if(x==a&&y==b)
        {
            cout<<turns<<endl;return 0;
        }
        x+=dx,y+=dy;
        br++;

    }while(x!=a||y!=b);if(x==a&&y==b)
        {
            cout<<turns<<endl;return 0;
        }
}

