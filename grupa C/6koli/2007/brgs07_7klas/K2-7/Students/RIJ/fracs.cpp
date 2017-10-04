#include<iostream>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;b=r;
    }
    return a;
}
struct d
{
    int c,z;
    void skr()
    {
        int n=nod(c,z);
        c/=n;
        z/=n;
    }
};
bool f(d a,d b)
{
    int cc,ccc;
    cc=a.c*b.z;
    ccc=b.c*a.z;
    if (cc>=ccc) return true;
    return false;
}
int main()
{
    int n;
    d a[32];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].c>>a[i].z;
        a[i].skr();
    }
    sort(a,a+n,f);
    cout<<n<<endl;
    for(int i=n-1;i>=0;i--)
    cout<<a[i].c<<' '<<a[i].z<<endl;
    return 0;
}
