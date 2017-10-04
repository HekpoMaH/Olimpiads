#include<iostream>
#include<string>
using namespace std;
long n,i,j,s1,s2,k1,k2;
string a;
long b1[10],b2[10];
char p;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
                     s1=0;
                     s2=0;
                     cin>>a;
                     for(j=0;j<=a.size()-1;j++)
                     {
                     if (a[j]=='C') {s1++;}
                     if (a[j]=='A') {s1++;}
                     if (a[j]=='T') {s1++;}
                     if (a[j]=='G') {s2++;}
                     if (a[j]=='P') {s2++;}
                     if (a[j]=='I') {s2++;}
                     }
                     b1[i]=s1;
                     b2[i]=s2;
    }
    for(i=1;i<=n;i++)
    {
                     if(b1[i]>b2[i]) {cout<<"CAT"<<endl;}
                     else if(b1[i]<b2[i]) {cout<<"GPI"<<endl;}
                     else if(b1[i]==0 && b2[i]==0) {cout<<"UFO"<<endl;}
                     else if(b1[i]==b2[i]) {cout<<"CAT-GPI"<<endl;}
    }
    return 0;
}
