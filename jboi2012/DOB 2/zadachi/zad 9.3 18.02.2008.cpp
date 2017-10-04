//zad 9.3 18.02.2008
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,s,n;
    cin>>s;
    n=0;
    for(a=1;a<s;a++)
    for(b=a+1;b<s;b++)
    for(c=b+1;c<s;c++)
    if(s==a+b+c)
    n++;
    cout<<n<<endl;
    system("pause");
    return 0;
}
