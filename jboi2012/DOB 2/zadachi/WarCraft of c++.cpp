#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a=1,b=1,c;
    if(n==1 || n==2){cout<<1<<endl;}
    for(int num=3;num<=n;num++)
    {
        
            c=a+b;
            a=b;
            b=c;
            if (n==num) {cout<<c<<endl;}
    }
    system("pause");
    return 0;
}    
