#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s="",s1="",s2="";
int j,sz=0;
int n,a[10240],ans[1024];
int pall(string x)
{
    for(int i=0;i<=x.size()-1;i++)
    {
        for(int j=x.size()-1;j>=0;j--)
        {
            if(x[j]==x[i])
            {
                i++;
                if(i==j) return 1;
            }
            else return 0;
        }
    }

}
void read()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)s+='b';
        else s+='a';
    }

    j=0;
    ans[j]=1;
}
void solve()
{
    int sum=1,end=0,l=0;
    int j=s.size()-1;
    for(int i=2;i<=j;i++)
    {
        s1=s.substr(i,j);
        s2=s.substr(j-i,i);
        if(pall(s1)&&pall(s2))
        {
            sum++;l=1;
            end=i;
            break;
        }
        if(pall(s1)||pall(s2))
        {
            if(pall(s2)) s2=s2.substr(i,i);
            sum++;
        }

        s1="";
        s2="";

    }
    cout<<sum<<endl;
    cout<<end<<endl;
}

int main ()
{
    read();
    if(pall(s))
    {
        cout<<1<<endl;
        return 0;
    }
    solve();


return 0;
}