#include <iostream>
#include <algorithm>
using namespace std;


int main()
{   
    int s, n, a[3000], br=0, p[1000], k, m, q;
    cin >> s >> n;
    k=0;
    for(int i=0; i<n; i++)
    {
            cin >> a[i];        
    }
    for(int j=0; j<n; j++)
    {
        m=0;
        q=n-j;
        for(int i=q; i>0; i--)
        {
        m=m+s/a[i];
        s=s%a[i];       
        }
        p[k]=m;
        k++;
    }
    cout << p[k-1]<<endl;
    return 0;
}
