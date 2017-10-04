#include <iostream>
using namespace std;
int main()
{
    double a,b;
    long long count=1,maxcount;
    cin>>a>>b;
    if(a<=b){count++;maxcount=count;}
    a=b;
    while(true)
    {
        cin>>b;
        if(b==0){break;}
        else
        {
            if(a<=b)
            {
                count++; a=b;
                if(count>maxcount){maxcount=count;}
            }
            else {count=1; cin>>a;}
        }
    }
    cout<<maxcount<<'\n';
    return 0;
}
