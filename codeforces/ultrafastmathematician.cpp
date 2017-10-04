#include<iostream>
#include<string>
using namespace std;
string a,b;
int main()
{
    cin>>a;
    cin>>b;
    int x,y,z;
    for(int i=0;i<a.size();i++)
    {
        x=a[i]-'0';
        y=b[i]-'0';
        z=x;z^=y;
        cout<<z;
    }
    cout<<endl;
    return 0;
}
