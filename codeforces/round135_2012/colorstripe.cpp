#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int n,k;
int main()
{
    cin>>n>>k>>s;
    if(k==2)
    {
        int t1=0,t2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]-'A'!=i%2)t1++;
            else t2++;
        }
        if(t1<t2)
        {
            cout<<t1<<endl;
            for(int i=0;i<n;i++)cout<<(char)('A'+i%2);
            cout<<endl;
        }
        else{cout<<t2<<endl;for(int i=0;i<n;i++)cout<<(char)('B'-i%2);cout<<endl;}
        return 0;
    }
    int t=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            while(s[i]==s[i-1]||s[i]==s[i+1])s[i]=rand()%k+'A';
            t++;
        }
    }
    cout<<t<<endl;
    cout<<s<<endl;
    return 0;
}
