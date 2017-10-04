//zad 4 15.02.2008
#include<iostream>
using namespace std;
int main()
{
    int a;
    int s=0;
    cin>>a;
    while(a!=0)
    {
               s=s+a;
               cin>>a;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
