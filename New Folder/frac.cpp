#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c,d;
    c=a;
    d=b;
    while(c!=d)
    {
               if(c>d)c=c-d;
               else d=d-c;
    }
    cout<<a/d<<" "<<b/d<<endl; 
    system("pause");
    return 0;
}
