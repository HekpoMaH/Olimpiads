#include<iostream>
using namespace std;
int br,n,used[503];
void des(int x)
{
    cout<<x<<endl;
    if(x==0){br++;return;}
    for(int i=x-1;i>=1;i--)
    {
        if(used[i]==0)
        {
            used[i]=1;
            //cout<<"xx="<<x-i<<" "<<i<<endl;
            des(x-i);
            used[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    des(n);
    cout<<br<<endl;
    return 0;
}