#include<iostream>
using namespace std;
int main()
{
    int a,am,ma;
    cin>>a>>am;
    ma=a*60+am;
    cin>>a>>am;
    ma=(a*60+am)-ma;
    int b,bm,mb;
    cin>>b>>bm;
    mb=b*60+bm;
    cin>>b>>bm;
    mb=(b*60+bm)-mb;
    int c,cm,mc;
    cin>>c>>cm;
    mc=c*60+cm;
    cin>>c>>cm;
    mc=(c*60+cm)-mc;
    if(ma==mb&&mb==mc)cout<<"X"<<endl;
    if(ma==mb&&mb>mc)cout<<"XC"<<endl;
    if(ma==mb&&mb<mc)cout<<"CX"<<endl;
    if(ma==mc&&mc>mb)cout<<"XB"<<endl;
    if(ma==mc&&mc<mb)cout<<"BX"<<endl;
    if(mb==mc&&mc>ma)cout<<"XA"<<endl;
    if(mb==mc&&mc<ma)cout<<"AX"<<endl;
    if(ma>mb&&mb>mc)cout<<"ABC"<<endl;
    if(ma>mc&&mc>mb)cout<<"ACB"<<endl;
    if(mb>ma&&ma>mc)cout<<"BAC"<<endl;
    if(mb>mc&&mc>ma)cout<<"BCA"<<endl;
    if(mc>ma&&ma>mb)cout<<"CAB"<<endl;
    if(mc>mb&&mb>ma)cout<<"CBA"<<endl;
    system("pause");
    return 0;
}
