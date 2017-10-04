#include<iostream>
using namespace std;
int main()
{
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double x,y;
    cin>>x>>y;
    int br=0,br2=0,br3=0;
    while(x>0&&y>0)
    {
                   if((x>=x1&&x<=x2&&y>=y1&&y<=y2)&&(x==x1||x==x2||y==y2||y==y1))br2+=1;
                   if(x>=x1&&x<=x2&&y>=y1&&y<=y2)br+=1;
                   else br3+=1;
                   cin>>x>>y;
    }
    cout<<br<<" "<<br2<<" "<<br3<<endl;
    system("pause");
    return 0;
}
