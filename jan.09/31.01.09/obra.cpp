#include<iostream>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    long long int a1;
    a1=a;
    int c;
    long long b=0;
    while(a1!=0)
    {
                c=a1%10;
                b=b*10+c;
                a1=a1/10;
    }
    if(b==a){
             cout<<"0"<<endl;
             }
    if(b>a){
            cout<<"-1"<<endl;
            }
    if(b<a){
            cout<<"1"<<endl;
            }
    system("pause");
    return 0;
}
