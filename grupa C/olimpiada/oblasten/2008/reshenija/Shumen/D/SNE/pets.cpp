#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    int l,br=0,br2=0,i;
    cin>>l;
    for(i=0;i<l;i++)
    {
    cin>>a;
    for(int j=0;j<a.size();j++)
    {
    if(a[j]=='C'||a[j]=='A'||a[j]=='T')br++;
    if(a[j]=='G'||a[j]=='P'||a[j]=='I')br2++;
    }
    if(br==0&&br2==0)cout<<"UFO"<<endl;
    else
    if(br==br2)cout<<"CAT-GPI"<<endl;
    else
    if(br>br2)cout<<"CAT"<<endl;
    else
    if(br<br2)cout<<"GPI"<<endl;
    br=0;br2=0;
    }
    return 0;
}
