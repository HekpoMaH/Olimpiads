//zad 1 15.02.2008
#include<iostream>
using namespace std;
int main()
{
    int a,s;
    a=5;
    s=0;
    while(a>0)
    {
              s=s+a;
              a=a-1;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
