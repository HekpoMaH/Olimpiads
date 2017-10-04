#include<iostream>
using namespace std;
int main()
{
    unsigned long long a, b;
    unsigned long long k, p;
    cin>>a>>b>>k>>p;
    unsigned long long ost=a%b, br=0 ,t=0;
    while(1)
    {
        ost=(ost*10)%b;
        br++;
        if(br+1==k%(b-1))
        {
            br--;
            t++;
            cout<<(ost*10)/b;
        }
        if(t==p) break;
    }
    cout<<"\n";
    return 0;
}
