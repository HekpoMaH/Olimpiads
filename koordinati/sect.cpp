#include<iostream>
using namespace std;
int main()
{
    double xa1,xa2,xb1,xb2,ya1,ya2,yb1,yb2;int br=0;
    cin>>xa1>>ya1>>xb1>>yb1>>xa2>>ya2>>xb2>>yb2;
    double x,y;
    cin>>x>>y;
    while(x!=0&&y!=0)
    {
                     if((x>=xa1&&x<=xb1&&y>=ya1&&y<=yb1)&&(x>=xa2&&x<=xb2&&y>=ya2&&y<=yb2))br+=1;
                     cin>>x>>y;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
