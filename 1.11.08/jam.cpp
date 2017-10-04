//jam
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=c&&b<=d||a<=d&&b<=c)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    system("pause");
    return 0;
}     
