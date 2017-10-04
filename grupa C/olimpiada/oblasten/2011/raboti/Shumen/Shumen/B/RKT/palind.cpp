#include<iostream>
#include<vector>
using namespace std;

int n,a[16384],minp=100;
vector <int> sp,ans_sp;
void read()
{
    int i;
    cin>>n;
    for( i=0 ; i<n ; i++ )
    cin>>a[i];
}

void write()
{
    cout<<minp<<endl;
    int i,j=ans_sp.size();
    for( int i=1;i<j;i++)
    cout<<ans_sp[i]<<' ';
}

void answer()
{
    if(minp>sp.size())
    {
        minp=sp.size();
        ans_sp=sp;
    }
}

int find_pal( int st )
{
    int ed=n-1,lam=1;
    while(st<=ed)
    {
        int st1=st,ed1=ed,l=1;
        while(st1<=ed1)
        {
            if(a[st1]!=a[ed1])
            {
                l=0;
                break;
            }
            ed1--;
            st1++;
        }
        if(l==1)
        {
            sp.push_back(st);
            if(ed==n-1)
            {
                answer();
                sp.pop_back();
                sp.pop_back();
                return 0;

            }
            else
            find_pal(ed+1);
        }
        ed--;

    }
    sp.pop_back();

}


int main()
{
    read();

    find_pal(0);

    write();

    return 0;
}