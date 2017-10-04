#include<iostream>
#include<string>
using namespace std;
string s;

int main()
{
    cin>>s;
    if(expr(0)==-1)cout<<"error"<<endl;
    else cout<<"correct"<<endl;
    return 0;
}

