#include<iostream>
using namespace std;
int main()
{
    int in=6,zv=1;
    for(int i=1;i<=7;i++)
    {
            for(int k=1;k<=in;k++)cout<<" ";
            for(int k=1;k<=zv;k++)cout<<"*";
            in-=1;
            zv+=2;
            cout<<endl;
    }
    system("pause");
    return 0;
}
