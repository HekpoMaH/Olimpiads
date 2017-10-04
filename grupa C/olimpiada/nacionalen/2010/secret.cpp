#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;
string kod,mes;
long long n,k,sumc,kods,br;
int main()
{
    cin>>kod;
    n=(int)sqrt(kod.size());
    string tab[n];
    kods=kod.size();
    for(long long i=0;i<kods;i++)if(kod[i]>='0'&&kod[i]<='9')sumc+=kod[i]-'0';
    k=sumc%n;
    br=0;
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            tab[i]+=kod[br];
            br++;
        }
    }
    long long i=k,j=0,l;
    while(1)
    {
        mes+=tab[i][j];
        l=0;
        if(i>=n-1){i=0;l=1;}
        if(j>=n-1&&l==0){i++;j=0;l=1;}
        if(i<n-1&&j<n-1&&l==0){i++;j++;}
        if(!(tab[i][j]>='A'&&tab[i][j]<='Z'))break;
    }
    cout<<mes<<endl;
    return 0;
}
