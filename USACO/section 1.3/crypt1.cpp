/*
ID: dobrikg1
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int n;
int a[11],num,br,given[11];
bool corr(int x)
{
    while(x!=0)
    {
        if(given[x%10]==0)return false;
        x/=10;
    }
    return true;
}
int main()
{
    ifstream fin ("crypt1.in");
    ofstream fout("crypt1.out");
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a[i];
        given[a[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                num=a[i]*100+a[j]*10+a[k];
                for(int f=0;f<n;f++)
                {
                    if(a[f]!=0)
                    {
                        for(int d=0;d<n;d++)
                        {
                            if(a[f]*num>99&&a[f]*num<1000)if(a[d]*num>99&&a[d]*num<1000)if(num*(a[f]*10+a[d])>=1000&&num*(a[f]*10+a[d])<10000)
                            {
                                if(corr(num*a[f])==true&&corr(num*a[d])&&corr(num*(a[f]*10+a[d])))br++;
                            }
                        }
                    }
                }
            }
        }
    }
    fout<<br<<endl;
    return 0;
}