#include<iostream>
using namespace std;
int main()
{
    int a[10][10],min;
    int n,m,c,l,l1=0,i,y,x;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
            for(int y=1;y<=m;y++)
            {
                    cin>>a[i][y];
            }
    }
    i=1;
    while(i<=n&&l1==0)
    {
            y=1;
            while(y<=m&&l1==0)
            {
                    c=a[i][y];
                    l=1;
                    x=1;
                    while(x<=n&&l==1)
                    {
                                    if(x!=y)
                                    {
                                             if(c<a[i][x]){l=0;}
                                    }
                                    x++;
                    }
                    x=1;
                    while(x<=m&&l==1)
                    {
                                     if(x!=i)
                                     {
                                             if(c>a[x][y]){l=0;}
                                     }
                                     x++;
                    }
                    if(l){cout<<a[i][y]<<endl;l1=1;}
                    y++;
            }
            i++;
    }
    if(l1==0){cout<<"No"<<endl;}
    return 0;
}
