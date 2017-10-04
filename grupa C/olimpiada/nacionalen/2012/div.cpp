#include<iostream>
using namespace std;
char s[1000],q[1000];
int div(int k)
{
    int i=0,c=0,j=0,w=0,v;
    while(s[i]>0)
    {
        c=c*10+s[i]-'0';
        v=c/k;
        if(v!=0)w=true;
        if(w){q[j]=v+'0';j++;}
        c%=k;
        i++;
    }
    q[j]=0;
    return c;
}
int main()
{
    cin>>s;
    int r;
    for(int i=2;i<=2000;i++)
    {
        r=div(i);
        if(r==0)cout<<i<<" "<<q<<endl;
    }
    return 0;
}