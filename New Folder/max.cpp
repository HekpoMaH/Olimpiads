#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int e,d,s,max=0;
    while(n>=100)
    {
                 e=n%10;
                 d=(n/10)%10;
                 s=(n/100)%10;
                 if(s*100+d*10+e>max){max=s*100+d*10+e;}
                 n=n/10;
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}
