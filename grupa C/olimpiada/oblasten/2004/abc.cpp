#include<iostream>
#include<cmath>
using namespace std;
int x1,y1,x2,y2,x3,y3,sum;
int prog(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    sum+=prog(abs(x1-x2),abs(y1-y2));
    sum+=prog(abs(x1-x3),abs(y1-y3));
    sum+=prog(abs(x3-x2),abs(y3-y2));
    cout<<sum<<endl;
    return 0;
}