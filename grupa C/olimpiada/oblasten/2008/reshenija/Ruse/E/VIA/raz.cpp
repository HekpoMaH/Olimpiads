#include<iostream>
using namespace std;
int main ()
{
    long n,i,y,min=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
                    if (n==i*y)
            if (i<y)
            if (y-i<min) min=y-i;
        for (y=1;y<=n;y++)
        {
            if (n==i*y)
            if (i<y)
            {
            if (y-i<min) min=y-i;
            }
            if (y<i)
            {
                    if (i-y<min) min=y-i;
            }
            }               
     
    }
    cout<<i<<" "<<y<<endl;
    return 0;
}
