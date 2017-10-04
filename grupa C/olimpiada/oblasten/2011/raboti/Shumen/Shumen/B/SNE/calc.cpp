#include<iostream>
using namespace std;
int s,br,n;
int main()
{
    cin>>s>>n;
    while(s>n)
    {
        //cout<<s<<endl;
        br++;
        if(s%n==0)
        {
            s/=n;
            continue ;
        }
        int x=s%n;
        s-=x;
    }
    cout<<br+1<<endl;
    return 0;
}