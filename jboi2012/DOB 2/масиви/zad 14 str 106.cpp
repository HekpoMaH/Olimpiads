//zad 14 str 106
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int a1;
    cin>>a1;
    for(int i=0;i<a1;i++)
    {
            cin>>a[i];
    }
    for(int i=0;i<a1;i++)
    {
            if(a[i]%3==0)
            {
                         cout<<a[i]<<endl;
            }
    }
    system("pause");
    return 0;
}
