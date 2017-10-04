
/// Task: segments
/// Author: Mladen Manev

#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll euclid(ll b, ll c)
{
    while(b!=0)
    {
        c=c%b;
        swap(b,c);
    }
    return c;
}

void extended_euclid(ll b, ll c, ll & y1, ll &z1)
{
    ll q, r;
    ll z2=0, y2=1, z11, y11;
    z1=1; y1=0;
    while(b!=0)
    {
        q=c/b; r=c%b;
        c=b; b=r;
        z11=z1; y11=y1;
        z1=z2; y1=y2;
        z2=z11-z2*q;
        y2=y11-y2*q;
    }
    return;
}

int main()
{
    ll a, b, c, m, n, z, y, nod, y0, z0;
    double p, q, p1, p2;
    cin >> a >> b >> c >> m >> n;
    b=b-a; c=c-a; n=n-a*m;
    nod=euclid(b,c);
    if(n%nod != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    b=b/nod; c=c/nod; n=n/nod;
    extended_euclid(b,c,y,z);
    y0=y*n; z0=z*n;
    cout<<y0<<" "<<z0<<"\n";
    p1 = double(-z0)/b;
    q = double(y0)/c;
    p2 = double(y0+z0-m)/(c-b);
    if(p1<p2) p=p2;
    else p = p1;
    p = ceil(p); q = floor(q);
    cout<<p<<" "<<q<<"\n";
    if (p<=q) cout << ll(q-p+1) << endl;
    else cout << 0 << endl;
    return 0;
}
