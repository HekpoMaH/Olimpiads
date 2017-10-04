#include<iostream>
#include<string>
using namespace std;
unsigned long long d,p,mt=1;
int l=1;
void di(unsigned long long &p)
{
    unsigned long long c,mm=mt,pp=p;
    //cout<<mm<<endl;
    l=0;
    while(mm!=1)
    {
        pp/=10;
        mm/=10;
    }
    //cout<<"pp="<<pp<<endl;
    c=pp%10;
    //cout<<"c="<<(c+1)*mt<<endl;
    if(c==9)l=1;
    if((c+1)*mt<=d&&c!=9)
    {
        l=1;
        p-=(c+1)*mt;
        d-=(c+1)*mt;
    }
    //cout<<p<<" "<<d<<endl;
}
int main()
{
    cin>>p>>d;
    while(l){di(p),mt*=10;}
    cout<<p<<endl;
    return 0;
}
//1445355 994244
//1388593859112389 19584958339