#include<iostream>
using namespace std;
int main ()
{
    string s;
    int n,i,br1=0,br2=0,j,sz;
    cin>>n;
    for(i=0;i<n;i++)
{
    cin>>s;
    sz=s.size();
    for(j=0;j<sz;j++)
{
    if(s[j]=='C'||s[j]=='A'||s[j]=='T')br1++;
    else
    if(s[j]=='G'||s[j]=='P'||s[j]=='I')br2++;
}
if(br1>br2)cout<<"CAT"<<endl;
    if(br1<br2)cout<<"GPI"<<endl;
    if(br1!=0&&br2!=0&&br1==br2)cout<<"CAT-GPI"<<endl;
    if(br1==0&&br2==0)cout<<"UFO"<<endl;
    br1=0;
    br2=0;
}
    return 0;
}
