#include <iostream>
using namespace std;
int main()
{
    int a[6],N, i, min;
    cin>>N;
    for (i=0;i<N;i++)
    {
        cin>>a[i];
    }
    min=a[0];
    for (i=0;i<N;i++)
    {
        if (min>a[i]) min=a[i];
    }
    cout<<min*N<<endl;
    return 0;
}
