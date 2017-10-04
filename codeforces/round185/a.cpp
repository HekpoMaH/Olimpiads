#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n;
string s;
int main()
{
    cin>>n;
    getline(cin,s,'\n');
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<endl;
        getline(cin,s,'\n');
        if(s.size()>=5)
        {
            if(s[s.size()-1]=='.'&&s[s.size()-2]=='a'&&s[s.size()-3]=='l'&&s[s.size()-4]=='a'&&s[s.size()-5]=='l'&&!(s[4]=='.'&&s[3]=='o'&&s[2]=='a'&&s[1]=='i'&&s[0]=='m'))cout<<"Freda's"<<endl;
            else if(s[4]=='.'&&s[3]=='o'&&s[2]=='a'&&s[1]=='i'&&s[0]=='m'&&!(s[s.size()-1]=='.'&&s[s.size()-2]=='a'&&s[s.size()-3]=='l'&&s[s.size()-4]=='a'&&s[s.size()-5]=='l'))cout<<"Rainbow's"<<endl;
            else cout<<"OMG>.< I don't know!"<<endl;
        }
        else cout<<"OMG>.< I don't know!"<<endl;
    }
}

