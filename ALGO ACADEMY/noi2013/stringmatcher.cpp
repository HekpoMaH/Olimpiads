#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
//char s[100009];
string name,sr,s,number;
int k;
struct fear
{
    int start;
    string ss;
};
vector<fear> ans;
int main()
{
    getline(cin,name);
    getline(cin,number);
    getline(cin,s);
    //cout<<s<<" "<<name<<endl;
    for(int i=0;i<name.size();i++)
    {
        sr+=s[i];
    }
    for(int i=name.size();i<s.size();i++)
    {
        if(name==sr)
        {
            fear ff;
            ff.start=i-name.size();
            ff.ss=sr;ans.push_back(ff);
            //cout<<i-name.size()<<" "<<sr<<endl;
        }
        sr+=s[i];
        sr.erase(sr.begin());
        //cout<<sr<<endl;
    }
    if(ans.size()==0){cout<<"Not found!"<<endl;return 0;}
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<"index: "<<ans[i].start<<" - string: "<<ans[i].ss<<endl;
    }
}

