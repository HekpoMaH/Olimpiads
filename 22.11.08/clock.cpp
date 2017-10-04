#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    a=n/12;
    b=n%12;
    if(n%12==0){
                b=12;
                }
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
