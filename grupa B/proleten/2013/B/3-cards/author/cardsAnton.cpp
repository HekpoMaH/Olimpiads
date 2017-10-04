#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char a[40];
int br1=0, br2, n, maxsum=0, brst=0;
int b[20], st[20],  mst[20];
int K = 0, sum = 0;

void search_max()
{
    int sum=0, k=0;
    for(int i=0; i<2*n; i++)
    {
        if(a[i]=='1')
        {
            if(brst==0) mst[brst]=b[k];
            else mst[brst]=min(mst[brst-1], b[k]);
            st[brst]=b[k];
            brst++;
            k++;
        }
        else brst--;
        if(brst>0) sum+=mst[brst-1];
    }
    if(sum>maxsum) maxsum=sum;
}

void gen(int k)
{
    int prevst[20], prevmst[20], prevK, prevbrst, suminc;
    if(k==2*n && br1==br2)
    {
        if (sum > maxsum) maxsum = sum;
        return;
    }
    prevK = K;
    prevbrst = brst;
    memcpy(prevst, st, sizeof(st));
    memcpy(prevmst, mst, sizeof(mst));
    if(br1>=br2 && br1<n)
    {
        a[k]='1';br1++;
        if(brst==0)
          mst[brst]=b[K];
        else
          mst[brst]=min(mst[brst-1], b[K]);
        st[brst]=b[K];
        brst++;
        K++;
        if(brst>0)
          {
            sum+=mst[brst-1];
            suminc = mst[brst-1];
          }
        gen(k+1);
        sum= sum - suminc;
        br1--;
        K = prevK;
        brst = prevbrst;
        memcpy(st, prevst, sizeof(st));
        memcpy(mst, prevmst, sizeof(mst));
    }
    if(br1>br2 && br1<=n )
    {
        a[k]='2';br2++;
        brst--;
        if(brst>0)
          {
            sum+=mst[brst-1];
            suminc = mst[brst-1];
          }
        gen(k+1);
        sum= sum - suminc;
        br2--;
        K = prevK;
        brst = prevbrst;
        memcpy(st, prevst, sizeof(st));
        memcpy(mst, prevmst, sizeof(mst));
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> b[i];
    gen(0);
    cout << maxsum << endl;
}
