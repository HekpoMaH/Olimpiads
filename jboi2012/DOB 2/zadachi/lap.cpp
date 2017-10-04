#include<iostream>
using namespace std;
int main()
{
    long int x,y,z,t;
    cin>>x>>y>>z>>t;
    long int p,d,g,s;
    p=x;
    d=y;
    g=z;
    s=t;
    x=abs(x);
    y=abs(y);
    do
    {
             if(x>y){x=x-y;}
             else{y=y-x;}
    }
    while(x!=y);
    int nod=y;
    cout<<nod<<" ";
    z=abs(z);
    do
    {
        if(nod>z){nod=nod-z;}
        else{z=z-nod;}
    }
    while(nod!=z);
    cout<<nod<<" ";
    t=abs(t);
    do
    {
             if(nod>t){nod=nod-t;}
             else{t=t-nod;}
    }
    while(nod!=t);
    cout<<nod<<" ";
    long long int nok;
    nok=p*d*g*s;
    nok=nok/nod;
    cout<<nok<<endl;
    system("pause");
    return 0;
}
