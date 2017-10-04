#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=4;i++)
    {
            for(int k=1;k<=i-1;k++)cout<<"  ";
            for(int k=i;k<=4;k++)cout<<k<<" ";
            for(int k=4;k>=i;k--)cout<<k<<" ";
            cout<<endl;
    }
    for(int i=3;i>=1;i--)
    {
            for(int k=1;k<=i-1;k++)cout<<"  ";
            for(int k=i;k<=4;k++)cout<<k<<" ";
            for(int k=4;k>=i;k--)cout<<k<<" ";
            cout<<endl;
    }
    system("pause");
    return 0;
}
