#include<iostream>
using namespace std;
int main()
{
    long long int a[99999];
    int n,e,d,s;
    cin>>n;
    e=n%10;
    d=(n/10)%10;
    s=n/100;
    a[0]=e*e+d*d+s*s;
    int l=0,i=1;
    do
    {
        e=a[i-1]%10;
        d=(a[i-1]/10)%10;
        s=a[i-1]/100;
        a[i]=e*e+d*d+s*s;
        for(int j=1;j<=i-1;j++)
        {
                for(int k=j+1;k<=i;k++)
                {
                        if(a[j]==a[k])l++;
                }
        }
        i++;
    }
    while(l==0);
    cout<<a[i-1]<<endl;
    system("pause");
    return 0;
}
