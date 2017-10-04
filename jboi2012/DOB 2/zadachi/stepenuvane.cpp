#include<iostream>
using namespace std;
int main()
{
    long long int a,b,c;
    cin>>a>>b;
    for(int i=2;i<=b;i++)
    {
            if(i==2)
            {
                    c=a*a;
            }
            else{c=c*a;}
    }
    cout<<c<<endl;
    system("pause");
    return 0;
}
