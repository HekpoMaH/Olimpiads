#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k4,kz,k42,kz2;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }
    return a;
}
int main()
{
    cin>>a>>b>>c>>d;
    double aa=a,bb=b,cc=c,dd=d;
    if(aa/bb<cc/dd)
    {
        k4=b*c-a*d;
        kz=b*c;
        int nd=nod(k4,kz);
        k4/=nd;kz/=nd;
        cout<<k4<<"/"<<kz<<endl;
    }
    else if(aa/bb>cc/dd)
    {
        k4=-b*c+a*d;
        kz=a*d;
        //cout<<k4<<" "<<kz<<endl;
        int nd=nod(k4,kz);
        k4/=nd;kz/=nd;
        cout<<k4<<"/"<<kz<<endl;
    }
    else cout<<"0/1"<<endl;
}

