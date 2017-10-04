#include<iostream>
using namespace std;
struct alien
{
    double c;
    double koord[100000][2];
};
alien a[505];
double b,s;double x,y;
double dead[505],under,under2;
void check(double x,double y)
{
    double x1,x2,y1,y2;
    int fl;
    for(int i=1;i<=b;i++)
    {
        if(dead[i]==1)continue;
        under=0;fl=1;
        for(int j=1;j<a[i].c;j++)
        {
            if(j==1)
            {
                x1=a[i].koord[j][1]-a[i].koord[j+1][1];
                y1=a[i].koord[j][2]-a[i].koord[j+1][2];
                x2=a[i].koord[j][1]-x;
                y2=a[i].koord[j][2]-y;
                if(x1*y2-y1*x2<=0)under=1;             
            }
            else
            {
                x1=a[i].koord[j][1]-a[i].koord[j+1][1];
                y1=a[i].koord[j][2]-a[i].koord[j+1][2];
                x2=a[i].koord[j][1]-x;
                y2=a[i].koord[j][2]-y;
                under2=0;
                if(x1*y2-x2*y1<=0)under2=1;
            }
            if(under!=under2){fl=0;break;}
        }
        if(fl==1)dead[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>b>>s;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i].c;
        for(int j=1;j<=a[i].c;j++)
        {
            cin>>a[i].koord[j][1]>>a[i].koord[j][2];
        }
    }
    for(int i=1;i<=s;i++)
    {
        cin>>x>>y;
        check(x,y);
    }
    int br=0;
    for(int i=1;i<=b;i++)if(dead[i])br++;
    cout<<br<<endl;
    return 0;
}
/*
1 3
3
-2 1
8 1
3 4
3 2
10 30
2 37

1 1
3
-2 1
8 1
3 4
200 200
*/