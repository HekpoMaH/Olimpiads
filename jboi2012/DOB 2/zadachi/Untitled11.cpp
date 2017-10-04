#include<iostream> 
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<10){cout<<22+n<<".01.2008"<<endl;}
    else{cout<<22+n-31<<"02.2008"<<endl;}
    system("pause");
    return 0;
}
