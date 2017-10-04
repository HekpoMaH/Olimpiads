//digit1
#include<iostream>
using namespace std;
int main()
{
    long long int n,n1,d=0;
    int c;
    cin>>n;
    n1=abs(n);
    while(n1>10)
    {
               c=n1%10;
               d=d*10+c;
               n1=n1/10;
    }
    if(d%3==0){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
    system("pause");
    return 0;
}
