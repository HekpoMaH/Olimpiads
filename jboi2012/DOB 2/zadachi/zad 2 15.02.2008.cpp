//zad 2 15.02.2008
#include<iostream>
using namespace std;
int main()
{
    int s=0;
    int a=5;
    do
    {
        s+=a;
        a=a-1;
    }
    while (a>0);
    cout<<s<<endl;
    system("pause");
    return 0;
}
