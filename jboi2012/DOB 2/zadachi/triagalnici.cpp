#include<iostream>
using namespace std;
int main()
{
    int a,b,i,j,n;
    char c;
    cin>>n>>c;
    for(j=1;j<=n-1;j++){cout<<" ";}
    cout<<c<<"\n";
    a=n-2;
    b=1;
    for(i=1;i<=n-2;i++)
    {
                       for(j=1;j<=a;j++){cout<<" ";}
                       cout<<c;
                       for(j=1;j<=b;j++){cout<<" ";}
                       cout<<c<<"\n";
                                     a=a-1;
                                     b=b+2;
    }
    for(j=1;j<=n;j++){cout<<c<<" ";}
    cout<<"\n";
    system("pause");
    return 0;
}
                                     
