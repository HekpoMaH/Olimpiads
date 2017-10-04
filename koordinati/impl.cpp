#include<iostream>
using namespace std;
int main()
{
    double a1,a2,b1,b2,x,y;
    cin>>x>>y>>a1>>b1>>a2>>b2;
    int l=0;
    if(x>=0&&x<=a1&&y>=0&&y<=b1&&x>=0&&x<=a2&&x>=0&&y<=b2&&y>=0){l=1;cout<<"0"<<endl;}
    if((x>=0&&x<=a1&&y>=0&&y<=b1&&x>=0 || x<=a2&&x>=0&&y<=b2&&y>=0)&&l==0)cout<<"1"<<endl;
    else{
         if(l==0)cout<<"-1"<<endl;
         }
    system("pause");
    return 0;
}
