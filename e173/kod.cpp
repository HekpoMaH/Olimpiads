#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int e,d,s,h,dh,sh;
    e=n%10;
    d=(n/10)%10;
    s=(n/100)%10;
    h=(n/1000)%10;
    dh=(n/10000)%10;
    sh=n/100000;
    int br=0;
    if(e%2!=0){br++;}
    if(d%2!=0){br++;}
    if(s%2!=0){br++;}
    if(h%2!=0){br++;}
    if(dh%2!=0){br++;}
    if(sh%2!=0){br++;}
    int r=0;
    r=abs((sh*100+h*10+d)-(d*100+h*10+sh));
    cout<<br<<r<<endl;
    return 0;
}
