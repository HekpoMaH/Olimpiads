//zad 12 str 106
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
    int s=0;
    for(int i=0;i<a1;i++)
    {
            if(a[i]%2==1)
            {
                         s=s+a[i];
            }
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
    
