#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int br2=1;
vector<int> b;
vector<int> br;

int fact(int n)
{
    int i;
    int ans=1;
    for (i=1;i<=n;i++)
        ans*=i;
return ans;
}

int rec(int l,int r)
{
    int br3=1;
    int br4=1;
    int i;
    for (i=l+1;i<r;i++)
    {
        if (b[i]==1)
        {
            int k=i;
            for (int j=i+1;j<r;j++)
            {
                if (b[j]==1) k=j;
                if (b[j]==2){ br3*=rec(k,j+1); i=0; break;}
            }
        }
    }
    int t=-1;
    if (b[l]==3 || b[l+1]==3)
    {
        int bro=0;
        for (i=l;i<r;i++)
            if (b[i]==5){ t=i;}
            else if (b[i]==3) bro++;
        if (t==-1)
        {
            br4=fact(bro+1);
        }
        else
        {
            br4=rec(l,t+1)*rec(t+1,r);
        }
    }
    if (b[l]==5 || b[l+1]==5)
    {
        int bro=0;
        for (i=l;i<r;i++)
            if (b[i]==3){ t=i;}
            else if (b[i]==5) bro++;
        if (t==-1)
        {
            br4=fact(bro+1);
        }
        else
        {
            br4=rec(l,t+1)*rec(t+1,r);
        }
    }
    b.erase(b.begin()+l,b.begin()+r);
    return br3*br4;
}

int main()
{
    char a;
    a=0;
    int i;
    br.push_back(1);
    
    while (a!='\n' && !feof(stdin))
    {
        a=cin.get();
        if (a>='a' && a<='z') continue;
        else if (a=='(') b.push_back(1);
        else if (a==')') b.push_back(2);
        else if (a=='+') b.push_back(3);
        else if (a=='-') continue;
        else if (a=='*') b.push_back(5);
        else if (a=='/') continue;
        else if (a=='^') continue;
    }
    /*br2=1;
    for (i=0;i<b.size();i++)
    {
        if (b[i]==1)
        {
            int k=i;
            for (int j=i+1;j<b.size();j++)
            {
                if (b[j]==1) k=j;
                if (b[j]==2){ br2*=rec(k,j+1); i=0; break;}
            }
        }
    }*/
    br2=rec(0,b.size());
    printf ("%d\n",br2);
return 0;
}
    
