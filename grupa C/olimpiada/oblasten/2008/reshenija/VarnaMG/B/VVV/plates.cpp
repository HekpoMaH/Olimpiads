#include <iostream>
using namespace std;

int m, n, i, j, k, br=0;
char c[30000][30];
bool cmpr(int, int);

int main()
{
    cin >> m >> n;
    for(i=0; i<m*n; i++) for(j=0; j<n; j++) cin >> c[i][j];
    for(i=0; i<m*n-n; i+=n)
        for(j=i+n; j<m*n; j+=n)
            if(!cmpr(i, j)) br++;
    cout << br << endl;
    return 0;
}

bool cmpr(int a, int b)
{
    bool flag=true;
    for(int i=a, j=b; i<a+n; i++, j++)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[j][k])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    flag=true;
    for(int i=a, j=b; i<a+n; i++, j++)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[j][n-k-1])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    
    
    
    flag=true;
    for(int i=a, j=b+n-1; i<a+n; i++, j--)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[j][n-k-1])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    flag=true;
    for(int i=a, j=b+n-1; i<a+n; i++, j--)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[j][k])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    
    
    
    
    flag=true;
    for(int i=a, j=b; i<a+n; i++, j++)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[n-k-1][j])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    flag=true;
    for(int i=a, j=b; i<a+n; i++, j++)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[k][j])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    
    
    
    
    flag=true;
    for(int i=a, j=b+n-1; i<a+n; i++, j--)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[n-k-1][j])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    if(flag) return true;
    
    flag=true;
    for(int i=a, j=b+n-1; i<a+n; i++, j--)
    {
        if(!flag) break;
        for(int k=0; k<n; k++) if(c[i][k]!=c[k][j])
        {
            flag=false;
            break;
        }
        if(!flag) break;
    }
    return flag;
}
