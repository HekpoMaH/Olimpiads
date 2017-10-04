#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=7;i++)
    {
            for(int k=1;k<=i-1;k++)cout<<" ";
            for(int k=7;k>=i;k--)cout<<"*";
            cout<<endl;
    }
    system("pause");
    return 0;
}
