#include<bits/stdc++.h>
using namespace std;
int a,b;
int br2a,br3a,br5a,br2b,br3b,br5b;
int main()
{
    cin>>a>>b;
    while(a%2==0)a/=2,br2a++;
    while(a%3==0)a/=3,br3a++;
    while(a%5==0)a/=5,br5a++;
    while(b%2==0)b/=2,br2b++;
    while(b%3==0)b/=3,br3b++;
    while(b%5==0)b/=5,br5b++;
    if(a!=b)
    {
        cout<<-1<<endl;
        exit(0);
    }
    cout<<max(br2a,br2b)-min(br2a,br2b)+max(br3a,br3b)-min(br3a,br3b)+max(br5a,br5b)-min(br5a,br5b)<<endl;
}
