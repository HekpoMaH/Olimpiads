#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i1,i2;
    cin>>i1>>i2;
    string ss=s.substr(i1-i2,4);
    cout<<ss<<endl;//0 lenght 3
    return 0;
}