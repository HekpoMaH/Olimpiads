#include<bits/stdc++.h>
using namespace std;
string s;long long swaps,seconds,leftr,waits;
int main()
{
    cin>>s;
    int i=0;
    for(;s[i]=='L';i++);
    for(;s[i];i++)
    {
        if(s[i]=='L')swaps+=leftr,seconds=leftr+waits++;
        else leftr++,(waits?waits--:0);
    }
    cout<<seconds<<" "<<swaps<<endl;
}
