//prime
#include<iostream>
using namespace std;
int main()
{
    int n,l=0;
    cin>>n;
    for(int br=2;br<n;br++)
    {
            if(n%br==0)
            {
                       l=1;
                       cout<<"NOPRIME"<<endl;
                       break;
            }
    }
    if(l==0){cout<<"PRIME"<<endl;}
    system("pause");
    return 0;
}
