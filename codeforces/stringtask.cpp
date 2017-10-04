#include<iostream>
#include<string>
using namespace std;
long long w;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='a'&&s[i]!='A'&&s[i]!='y'&&s[i]!='Y'&&s[i]!='e'&&s[i]!='E'&&s[i]!='i'&&s[i]!='I'&&s[i]!='o'&&s[i]!='O'&&s[i]!='u'&&s[i]!='U')cout<<"."<<(char)tolower(s[i]);
    }
    cout<<endl;
    return 0;
}
