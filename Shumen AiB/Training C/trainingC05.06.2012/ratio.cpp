#include<iostream>
#include<string>
using namespace std;
string s;
int n;
void solve(string given)
{
    int ll=given.size();
    for(int i=0;i<ll;i++)
    {
        if(i+12<ll)
        {
            if(given[i+1]=='^'&&given[i+2]=='2'&&given[i+3]=='+'&&given[i+4]=='2'&&given[i+5]=='*'&&given[i+7]=='*'&&given[i+9]=='+'&&given[i+11]=='^'&&given[i+12]=='2'){
               if(given[i]==given[i+6]&&given[i+8]==given[i+10])
                   {cout<<"("<<given[i]<<"+"<<given[i+10]<<")^2";i+=12;}
            }
            else cout<<given[i];
        }
        else cout<<given[i];
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    getline(cin,s);
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        solve(s);
    }
    return 0;
}