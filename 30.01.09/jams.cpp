#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,u,v,x,y;
    cin>>a>>b>>c>>d>>u>>v>>x>>y;
    int l=0,l1=0;
    if(b+d<=v&&a<=u&&c<=u||a+c<=v&&b<=u&&d<=u||a+d<=v&&b<=u&&c<=u||b+c<=u&&a<=u&&d<=v){l=1;}
    if(b+d<=u&&a<=v&&c<=v||a+c<=u&&b<=v&&d<=v||a+d<=u&&b<=v&&c<=v||b+c<=v&&a<=u&&d<=u){l=1;}
    if(b+d<=y&&a<=x&&c<=x||a+c<=y&&b<=x&&d<=x||a+d<=y&&b<=x&&c<=x||b+c<=y&&a<=x&&d<=x){l1=1;}
    if(b+d<=x&&a<=y&&c<=y||a+c<=x&&b<=y&&d<=y||a+d<=x&&b<=y&&c<=y||b+c<=x&&a<=y&&d<=y){l1=1;}
    if(l==1){cout<<"YES"<<" ";}
    else{cout<<"NO"<<" ";}
    if(l1==1){cout<<"YES"<<" ";}
    else{cout<<"NO"<<" ";}
    cout<<endl;
    system("pause");
    return 0;
}
