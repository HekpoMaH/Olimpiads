#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p;
    p=1;
    int chislo;
    for(int br=1;br<=n;br++)
    {
            cin>>chislo;
            p=p*chislo;
    }
    cout<<p<<endl;
    system("pause");
    return 0;
}
