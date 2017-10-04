#include<iostream>
#include<algorithm>
using namespace std;
struct jib
{
    unsigned long long k,a;
};
jib box[100009];
unsigned long long n;
bool cmp(jib x,jib y)
{
    if(x.k<y.k)return true;
    else return false;
}
unsigned long long pow(unsigned long long num)
{
    unsigned long long an=1;
    while(num>0)
    {
        if(num&1)an*=4;
        num>>=1;
    }
    return an;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>box[i].k>>box[i].a;
    }
    sort(box+1,box+n+1,cmp);
    for(int i=2;i<=n;i++)
    {
        unsigned long long ebahti;
        unsigned long long aa=pow(box[i].k-box[i-1].k);
        ebahti=box[i].k*aa*box[i].a;
        while(ebahti<box[i-1].a)ebahti+=aa,box[i].a++;
    }
    unsigned long long e2=4;
    for(int i=box[n].k+1;;i++)
    {
        if(e2>=box[n].a){cout<<i<<endl;break;}e2*=4;
    }
}
