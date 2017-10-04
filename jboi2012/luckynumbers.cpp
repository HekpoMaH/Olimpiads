#include<iostream>
#include<string>
using namespace std;
string s;
int l;
int main()
{
    cin>>l;
    cin>>s;
    //proverka za dvoiki,3-ki i t.n.
    for(int i=0;i<s.size()-1;i++)
    {
        l=1;
        for(int j=i;j<=i+1;j++)
        {
            if(s[j]!='2'&&s[j]!='?'){l=0;break;}
        }
        if(l==1){cout<<"cool"<<endl;return 0;}
    }
    for(int i=0;i<s.size()-2;i++)
    {
        l=1;
        for(int j=i;j<=i+2;j++)
        {
            if(s[j]!='3'&&s[j]!='?'){l=0;break;}
        }
        if(l==1){cout<<"cool"<<endl;return 0;}
    }
    for(int i=0;i<s.size()-4;i++)
    {
        l=1;
        for(int j=i;j<=i+4;j++)
        {
            if(s[j]!='5'&&s[j]!='?'){l=0;break;}
        }
        if(l==1){cout<<"cool"<<endl;return 0;}
    }
    for(int i=0;i<s.size()-6;i++)
    {
        l=1;
        for(int j=i;j<=i+6;j++)
        {
            if(s[j]!='7'&&s[j]!='?'){l=0;break;}
        }
        if(l==1){cout<<"cool"<<endl;return 0;}
    }
    cout<<"boring"<<endl;
    return 0;
}