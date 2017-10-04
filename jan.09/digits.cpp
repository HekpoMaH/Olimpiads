//digits
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c;
    while(n!=0)
    {
               c=n%10;
               cout<<c<<endl;
               n=n/10;
    }
    system("pause");
    return 0;
}
