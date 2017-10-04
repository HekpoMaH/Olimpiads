#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(x>0&&y>0)cout<<"1"<<endl;
    if(x<0&&y>0)cout<<"2"<<endl;
    if(x>0&&y<0)cout<<"4"<<endl;
    if(x<0&&y<0)cout<<"3"<<endl;
    if(x==0&&y>0)cout<<"1"<<" "<<"2"<<endl;
    if(x==0&&y<0)cout<<"3"<<" "<<"4"<<endl;
    if(y==0&&x>0)cout<<"1"<<" "<<"4"<<endl;
    if(y==0&&x<0)cout<<"2"<<" "<<"3"<<endl;
    if(x==0&&y==0)cout<<"koordinatno na4alo"<<endl;
    system("pause");
    return 0;
}
