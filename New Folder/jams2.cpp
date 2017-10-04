#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,u,v,x,y;
    cin>>a>>b>>c>>d>>u>>v>>x>>y;
    if(a+d<=u&&b<=v&&c<=v||a+c<=u&&b<=v&&d<=v||a+d<=v&&b<=u&&c<=u||a+c<=v&&b<=u&&d<=u||b+d<=u&&a<=v&&c<=v||b+c<=u&&a<=v&&d<=v||b+d<=v&&a<=u&&c<=u||b+c<=v&&a<=u&&d<=u)cout<<"Yes"<<" ";
    else cout<<"No"<<" ";
    if(a+d<=x&&b<=y&&c<=y||a+c<=x&&b<=y&&d<=y||a+d<=y&&b<=x&&c<=x||a+c<=y&&b<=x&&d<=x||b+d<=x&&a<=y&&c<=y||b+c<=x&&a<=y&&d<=y||b+d<=y&&a<=x&&c<=x||b+c<=y&&a<=x&&d<=x)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
} 
