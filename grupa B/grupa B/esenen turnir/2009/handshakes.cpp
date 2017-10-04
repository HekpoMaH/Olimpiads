#include<iostream>
#include<string>
using namespace std;
string s;
long long leftr,sw,sec,i,waits;
int main()
{
    cin>>s;
    int beg=0;
    while(s[beg]=='L')beg++;
    for(i=beg;i<s.size();i++)
    {
        if(s[i]=='L')sw+=leftr,sec=leftr+waits++;
        else leftr++,(waits?waits--:0);
    }
    cout<<sec<<" "<<sw<<endl;
    return 0;
}
