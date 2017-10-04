#include<iostream>
using namespace std;
int main()
{
    int a,b,ae,ad,as,ah,be,bd,bs,bh;
    cin>>a>>b;
    ah=a/1000;
    as=(a/100)%10;
    ad=(a/10)%10;
    ae=a%10;
    bh=b/1000;
    bs=(b/100)%10;
    bd=(b/10)%10;
    be=b%10;
    int brb,brc;
    brb=0;
    brc=0;
    if(ah==bh){brb++;}
    if(as==bs){brb++;}
    if(ad==bd){brb++;}
    if(ae==be){brb++;}
    if(ah==bs || ah==bd || ah==be){brc++;}
    if(as==bd || as==be || as==bh){brc++;}
    if(ad==be || ad==bh || ad==bs){brc++;}
    if(ae==bh || ae==bs || ae==bd){brc++;}
    cout<<brb<<" "<<brc<<endl;
    system("pause");
    return 0;
}
    
