#include<iostream>
#include<string>
using namespace std;
string s;
char f[6]={'h','e','l','l','o'};
int br;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==f[br])br++;
        //cout<<i<<" "<<br<<endl;
        if(br==5){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}