#include<iostream>
using namespace std;
class UF
{
    private:
    int n;
    int *c;
    int *sz;
    int cnt;
    int find(int x)
    {
        while(x!=c[x])x=c[x];
        return x;
    }
    public:
    UF(int n0)
    {
        cnt=n0;
        n=n0;
        c=new int[n];
        sz=new int[n];
        for(int i=0;i<n;i++)
        c[i]=i,sz[i]=1;
    }
    bool sameset(int f,int s)
    {
        return c[f]==c[s];
    }
    int setcnt()
    {
        return cnt;
    }
    void join(int f,int s)
    {
        s=find(s);
        f=find(f);
        if(f!=s)
        {
            if(sz[f]>sz[s])
            {
                c[s]=f;
                sz[f]+=sz[s];
            }
            else
            {
                c[f]=s;
                sz[s]+=sz[f];
            }
        }
        cnt--;
    }
};
int main()
{
    UF s(10);
    s.join(1,2);
    s.join(1,3);
    s.join(3,9);
    cout<<s.setcnt()<<endl;
    s.join(5,6);
    cout<<s.sameset(7,8)<<endl;
    
}