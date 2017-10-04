//VALID
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a>31)
    {cout<<"No"<<endl;
    cout<<"31"<<endl;return 0;}
    if (a>29)
    {cout<<"No"<<endl;
    cout<<"29"<<endl;return 0;}
    if (a>30&&a<30&&a<31&&a>29)
    {
    cout<<"No"<<endl;
    cout<<"30"<<endl;return 0;
    }
    else
        if (a<31||a<30||a<29&&a>31&&a>30)
        cout<<"Yes"<<endl;
        cout<<a+1<<"."<<b<<"."<<c<<endl;
    return 0;
}
