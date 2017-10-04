#include <iostream>
using namespace std;
int br=0;
void razbivane(int n, int prev)
{
    if (n==0)br++;
    else
        for (int i=1;i<=n;i++)
            if (i>=prev)
                razbivane(n-i, i);
}
int main()
{
    int n;
    cin>>n;
    razbivane(n,0);
    cout<<br<<endl;
    return 0;
}
