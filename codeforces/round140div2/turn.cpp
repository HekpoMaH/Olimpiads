#include<iostream>
using namespace std;
long long ax,ay,bx,by,cx,cy,x1,y1,x2,y2;
int main()
{
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;
    x1=bx-ax;y1=by-ay;x2=cx-ax;y2=cy-ay;
    //cout<<x1*y2-x2*y1<<endl;
    if(x1*y2-x2*y1==0)cout<<"TOWARDS"<<endl;
    if(x1*y2-x2*y1>0)cout<<"LEFT"<<endl;
    if(x1*y2-x2*y1<0)cout<<"RIGHT"<<endl;
    return 0;
}
//1000000000