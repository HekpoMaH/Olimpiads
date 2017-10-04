#include<iostream>
#include<string>
using namespace std;
string s;
int cx,cy;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x')cx++;
        if(s[i]=='y')cy++;
    }
    if(cx>cy)
    {
        for(int i=1;i<=cx-cy;i++)cout<<"x";
        cout<<endl;
    }
    if(cx<cy)
    {
        for(int i=1;i<=cy-cx;i++)cout<<"y";
        cout<<endl;
    }
}
