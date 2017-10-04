#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> prefix_func(string s)
{
    int sz=s.size();
    vector<int> p(sz+1);
    p[0]=0;
    p[1]=0;
    int l,r,lng,f=0;
    l=0;
    r=2;
    while(r<=sz)
    {
        if(s[l]==s[r-1])
        {
            l++;
            if(l*2==r)
            {
                f=1;
                lng=l;
                printf("%d %d\n",r,r/lng);
                p[r]=l;
                r++;
                continue;
            }
            if(lng!=0 && r%lng==0)
            {
                f=1;
                printf("%d %d\n",r,r/lng);
            }
            p[r]=l;
            r++;
        }
        else
        {
            lng=0;
            if(l==0) p[r++]=0;
            else l=p[l];
        }
    }
    if(f==0) cout << "No Solution" << endl;
    return p;
}

int main()
{
    int i,n;
    string s;
    vector<int> p;
    cin >> n;
    cin >> s;
    p=prefix_func(s);

    return 0;
}
