#include<iostream>
using namespace std;
int main()
{
    int x,x1,x2,min;
    cin>>x>>x2;
    x1=x2-x;
    min=x1;
    if(x1<min) min=x1;
    cin>>x>>x2;
    x1=x2-x;
    if(x1<min) min=x1;
    cin>>x>>x2;
    if(x1<min) min=x1;
    cout<<min<<endl;
    system("pause");
    return 0;
}
