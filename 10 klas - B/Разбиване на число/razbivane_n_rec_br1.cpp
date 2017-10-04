#include <iostream>
using namespace std;
int br=0;
void razbivane(int n, int prev)
{
    if (n==0)br++;
    else
        for (int i=prev;i<=n;i++)
                razbivane(n-i, i);
}
int main()
{
    int n;
    cin>>n;
    razbivane(n,1);
    cout<<br<<endl;
    return 0;
}
