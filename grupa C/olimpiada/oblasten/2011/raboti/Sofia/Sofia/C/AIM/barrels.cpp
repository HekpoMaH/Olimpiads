#include<iostream>
using namespace std;
long long barrels[100];
int main()
{
    long long s, max, current=0, remain, k, h;
    int n, t;
    cin>>s>>n;
    max=s;
    t=n-1;
    for(int a=0; a<n; a++)
    {
        cin>>barrels[a];
    }
    sort(barrels, barrels+n);
    while(t>0)
    {
        k=s/barrels[t];
        while(k>0)
        {
            remain=s-k*barrels[t];
            current=current+k;
            while(remain>0)
            {
                h=n-1;
                while(remain<barrels[h])
                {
                    h--;
                }
                current=current+remain/barrels[h];
                remain=remain%barrels[h];
            }
            if(current<max) max=current;
            k--;
            current=0;
        }
        t--;
    }
    cout<<max<<endl;
    return 0;
}
