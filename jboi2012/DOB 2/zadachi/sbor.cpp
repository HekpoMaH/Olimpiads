#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s;
    s=0;
    int chislo;
    for(int br=1;br<=n;br++)
    {
            cin>>chislo;
            s=s+chislo;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
