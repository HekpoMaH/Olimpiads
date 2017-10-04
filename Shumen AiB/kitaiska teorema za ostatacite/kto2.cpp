//re6enie na kitaiska teorema za ost. upgraded
#include<iostream>
using namespace std;
int a[100],m[100],n,pr=1,mm[100],nn[100];
long long sum;
int find(int a,int b)
{
    long long tr=b,br=0;
    //cout<<tr<<endl;
    do
    {

        tr=b*br+1;
        if(tr%a==0)
        {
            return tr/a;
        }
        br++;
    }while(1);
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>m[i];
        pr*=m[i];
    }
    for(int i=1;i<=n;i++)
    {
        mm[i]=pr/m[i];
    }
    //find(1,4);
    for(int i=1;i<=n;i++)
    {
        nn[i]=find(mm[i],m[i]);
    }
    for(int i=1;i<=n;i++)sum+=a[i]*mm[i]*nn[i];
    cout<<sum%pr<<endl;
    return 0;
}
