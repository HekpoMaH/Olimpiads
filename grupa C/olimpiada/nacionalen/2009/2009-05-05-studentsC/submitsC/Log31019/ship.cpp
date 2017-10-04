/*
TASK:ship
LANG:C++
*/
#include <iostream>
using namespace std;

struct tovar
{
       int ind;
       int t;
       int p;
};

int n;
tovar m[16384];

bool cmp(tovar a,tovar b)
{
     if(a.t<b.t) return true;
     if(a.t>b.t) return false;
     if(a.p<b.p) return true;
     return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) { m[i].ind=i; scanf("%d",&m[i].t); }
    for(int i=0;i<n;i++) scanf("%d",&m[i].p);
    
    sort(m,m+n,cmp);
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
            if(m[i].p==i) continue;
            
            int t;
            for(int j=0;j<n;j++) if(m[j].ind==m[i].p) { t=j; break; }
            
            sum+=m[i].t+m[t].t;
            swap(m[t].ind,m[i].ind);
            swap(m[t].t,m[i].t);
    }
    
    cout << sum << endl;
    
    return 0;
}
