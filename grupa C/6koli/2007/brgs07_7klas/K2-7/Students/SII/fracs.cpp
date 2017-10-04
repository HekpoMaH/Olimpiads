#include<iostream>
using namespace std;
struct drob
{
       int ch,zn;
};
drob a[32];
int nod(int a,int b)
{
    while(a!=b){
    if(a>b)a-=b;
    else b-=a;}
    return a;
}
int cmp(drob b[],int n)
{
    int ch1=0,ch2=0,zn1=0,zn2=0,i,j;
    for(j=n-1;j>=0;j--){
    for(i=0;i<j;i++)
    {
                      zn1=zn2=a[i].zn*a[i+1].zn/nod(a[i].zn,a[i+1].zn);
                      ch1=a[i].ch*(zn1/a[i].zn);
                      ch2=a[i+1].ch*(zn2/a[i+1].zn);
                      if(ch1>ch2)swap(a[i],a[i+1]);
    }}
}
int main()
{
    int n,i,j,k,m,p;
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>a[i].ch>>a[i].zn;
     p=nod(a[i].ch,a[i].zn);
     a[i].ch/=p;a[i].zn/=p;
    }
    cmp(a,n);
    cout<<n<<endl;
    for(i=0;i<n;i++)
    cout<<a[i].ch<<' '<<a[i].zn<<endl;
}
