/*
TASK:odd
LANG:C++
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m[1048576];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> m[i];
    sort(m,m+n);
    
    if(m[0]!=m[1]) { cout << m[0] << endl; return 0; }
    
    int br=1;
    for(int i=1;i<n;i++)
    {
            if(m[i]==m[i-1]) br++;
            else
            {
                if(br%2) { cout << m[i-1] << endl; return 0; }
                br=1;
            }
    }
    
    if(br%2) cout << m[n-1] << endl;
    return 0;
}
