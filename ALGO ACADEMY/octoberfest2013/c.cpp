#include<bits/stdc++.h>
using namespace std;

string is;
set<string> s;
int main()
{
    while(cin>>is)
    {
        if(is!="-1")
        {
            sort(is.begin(),is.end());
            s.insert(is);
        }
        else break;

    }
    cout<<s.size()<<endl;
}
