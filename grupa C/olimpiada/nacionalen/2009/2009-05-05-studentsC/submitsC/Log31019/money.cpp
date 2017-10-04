/*
TASK:money
LANG:C++
*/
#include <iostream>
#include <algorithm>
using namespace std;

int l,r;
int n;
int m[262144];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&m[i]);
    sort(m,m+n);
    
    l=0; r=0;
    int sol=-1;
    for(int i=0;i<n-1;i++)
    {
            if(r-l<=1) r++;
            else if(r-l>1)
            {
                     while(r-l>1 && m[l]+m[l+1]<=m[r]) l++;
                     if(r-l>1) sol=max(sol,r-l+1);
                     r++;
            }
            //cout << i << " " << l << " " << r << " " << sol << endl;
    }
    
    while(r-l>1 && m[l]+m[l+1]<=m[r]) l++;
    if(r-l>1) sol=max(sol,r-l+1);
    
    if(sol!=-1) cout << sol << endl;
    else cout << 1 << endl;
    
    return 0;
}
