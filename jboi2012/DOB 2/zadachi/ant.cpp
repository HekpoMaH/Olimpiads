#include<iostream>
using namespace std;
int main()
{
    int n,b;
    cin>>n;
    b=0;
    for(int br=1;br<=n;br++)
    {
        b=b+2*br;
    }
    cout<<b<<endl;
    system("pause");
    return 0;
}    
    
