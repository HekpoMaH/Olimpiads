#include<iostream>
using namespace std;
int main()
{
    unsigned long long int a,b,p,k;
    cin>>a>>b>>k>>p;
    a*=10;
    for(int i=0;i<k-1;i++)
    {
    if(a<b) {a*=10;continue;}
    a%=b;
    a*=10;
    }
    for(int i=0;i<p;i++)
    {
    if(a<b) {cout<<"0";a*=10;continue;}
    cout<<a/b;
    a=(a%b)*10;
    }
    cout<<endl;
    //system("pause");
    return 0;
}
