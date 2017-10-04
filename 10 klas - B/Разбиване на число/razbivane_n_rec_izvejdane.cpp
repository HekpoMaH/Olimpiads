#include <iostream>
using namespace std;
int a[1000];
void print(int br)
{
    for (int i=1;i<=br;i++)
               cout<<a[i]<<" ";
            cout<<endl;
}
void razbivane(int n, int pos)
{
    if (n==0)print (pos-1);
    else
        for (int i=n;i>=1;i--)
            if (i<=a[pos-1])
            {
                a[pos]=i;
                razbivane(n-i, pos+1);
            }
}
int main()
{
    int n;
    cin>>n;
    a[0]=n;
    razbivane(n,1);
    return 0;
}
