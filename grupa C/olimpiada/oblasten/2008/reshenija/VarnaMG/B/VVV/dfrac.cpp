#include <iostream>
#include <iomanip>
using namespace std;

long t[10000]={0}, w[10000]={0}, a, b, k, p, i=0, d=10, br=1, pos, lenght, l[50], j;
bool flag=true;

bool search()
{
    j=0;
    while(j<i)
    {
        if(w[i]==w[j]) 
        {
            pos = j;
            lenght = i-j;
            return false;
        }
        j++;
    }
    return true;
}

int main()
{
    cin >> a >> b >> k >> p;
    while(flag)
    {
        t[i]=a*d/b;
        if(t[i]==0) d*=10;
        else
        {
            w[i]=a*d%b;
            a=w[i];
            d=10;
            flag=search();            
            i++;
        }
    }
    if(k-1>i)
    {
        for(int g=(k-1)%lenght; g<(k-1)%lenght+p; g++)
        {
            cout << t[pos+(pos+g)%lenght];
        }
    }
    else
    {
        for(int g=k-1; g<k-1+p; g++) 
        {
            if(g<i) cout << t[g];
            else cout << t[pos+(pos+g)%lenght];
        }
    }
    cout << endl;
    return 0;
}
