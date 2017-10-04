#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int main()
{
    cin>>s;
    if(s[0]>='a'&&s[0]<='z')s[0]=s[0]-('a'-'A');
    cout<<s<<endl;
}
