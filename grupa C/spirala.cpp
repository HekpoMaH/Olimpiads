#include<iostream>
using namespace std;
int main()
{
    int m,n,x,y,dx,dy,c,a[10][10];
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
            for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    dx=m-1;dy=n-1;
    x=1;y=n;c=1;
    while(1)
    {
            if(c%2==0&&dy==0)break;
            if(c%2==1&&dx==0)break;
            switch(c%4)
            {
                       case 0:y+=dy;dy--;break;
                       case 1:x+=dx;dx--;break;
                       case 2:y-=dy;dy--;break;
                       case 3:x-=dx;dx--;break;
            }
            c++;
    }
    cout<<a[x][y]<<endl;
    return 0;
}
