#include<iostream>
using namespace std;
int n,l,d;
int t1,t2,t;
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>d;
        if(t==1)
        {
            if(d==-1)t1++;
            else if(d<=l)t1+=2;
            else t1+=3;
        }
        if(t==2)
        {
            if(d==-1)t2++;
            else if(d<=l)t2+=2;
            else t2+=3;
        }
    }
    cout<<t1<<":"<<t2<<endl;
}
