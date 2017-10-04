#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n/12<<" ";
    if(n%12==0){cout<<"12"<<endl;}
    else{cout<<n%12<<endl;}
    system("pause");
    return 0;
}
