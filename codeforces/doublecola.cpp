#include<iostream>
#include<string>
using namespace std;
long long w;
int main()
{
    cin>>w;
    w--;
    while(w>=5)
    {
        w-=5;
        w/=2;
    }
    if(w==0)cout<<"Sheldon"<<endl;
    if(w==1)cout<<"Leonard"<<endl;
    if(w==2)cout<<"Penny"<<endl;
    if(w==3)cout<<"Rajesh"<<endl;
    if(w==4)cout<<"Howard"<<endl;
    return 0;
}
