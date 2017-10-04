#include<iostream>
using namespace std;
int main()
{
    int m,n,l,br1,br2,d;
    cin>>m>>n>>l;
    br1=(l/m)+1;
    br2=(l/n)+1;
    d=abs(br1-br2);
    d++;
    cout<<d<<endl;
    system("pause");
    return 0;
}
