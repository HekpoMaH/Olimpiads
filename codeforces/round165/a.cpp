#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
double n;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int l=0;
        cin>>n;
        for(int i=3;i<=100000;i++)
        {
            double angle=(i-2)*180;
            angle/=i;
            if(n==angle){cout<<"YES"<<endl;l=1;break;}
        }
        if(l==0)cout<<"NO"<<endl;
    }
}
