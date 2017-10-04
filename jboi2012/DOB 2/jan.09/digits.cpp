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
               n=n/10;
               cout<<c<<endl;
    }
    system("pause");
    return 0;
}
