#include<bits/stdc++.h>
using namespace std;
int num[10009],br;
int num2[10009],br2;
int num3[10009],br3;
void sumit()
{
    br3=br2;
    for(int i=1;i<=br2;i++)
    {
        num3[i]=num2[i];
    }
    //for(cout<<num)
    for(int i=1;i<=max(br,br2);i++)
    {
        num2[i]=num2[i]+num[i];
    }
    for(int i=1;i<=max(br,br2);i++)
    {
        num2[i+1]+=num2[i]/10;num2[i]%=10;
        if(i==max(br,br2)&&num2[i+1]!=0)br2++;
    }
    br=br3;
    for(int i=1;i<=br3;i++)num[i]=num3[i];
}
int main()
{
    int n;
    cin>>n;
    num[1]=1;br=1;
    num2[1]=1;br2=1;
    for(int i=1;i<=n;i++)
    {
        sumit();
    }
    reverse(num+1,num+1+br);
    reverse(num2+1,num2+1+br2);
    for(int i=1;i<=br;i++)cout<<num[i];cout<<" ";
    for(int i=1;i<=br2;i++)cout<<num2[i];cout<<endl;
}
