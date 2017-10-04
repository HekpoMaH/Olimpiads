#include<iostream>
using namespace std;
int main()
{
    int n=1,a;
    do 
    {
        cin>>a;
        n=n*a;
    }
    while(a!=1);
    cout<<n<<endl;
    system("pause");
    return 0;
}    
