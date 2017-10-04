#include<iostream>
using namespace std;
int main()
{
    double x,y;
    cin>>x>>y;
    int l=0;
    if((x>-1&&x<1)&&(y>-1&&y<1)){cout<<"No"<<endl;l=1;}
    if((x<-2||x>2)||(y<-2||y>2))cout<<"No"<<endl;
    else{if(l==0)cout<<"Yes"<<endl;}
    system("pause");
    return 0;
}
