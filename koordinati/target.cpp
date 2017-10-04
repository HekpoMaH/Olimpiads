#include<iostream>
using namespace std;
int main()
{
    double x,y;
    cin>>x>>y;
    if((x>3||x<-3)||(y>3||y<-3))cout<<"0"<<endl;
    else
    {
        if(((x>=-3&&x<-2)||(x<=3&&x>2))||((y>=-3&&y<-2)||(y>2&&y<=3)))cout<<"2"<<endl;
        if(((x>=-2&&x<-1)||(x<=2&&x>1))||((y>=-2&&y<-1)||(y>1&&y<=2)))cout<<"5"<<endl;
        if(x>=-1&&x<=1&&y>=-1&&y<=1)cout<<"10"<<endl;
    }
    system("pause");
    return 0;
}
