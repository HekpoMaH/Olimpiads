//revert
#include<iostream>
using namespace std;
int main()
{
    int n,a,b=0,c;
    cin>>n;
    a=n;
    while(a!=0)
    {
               c=a%10;
               b=b*10+c;
               a=a/10;
    }
    cout<<b+n<<endl;
    system("pause");
    return 0;
}
