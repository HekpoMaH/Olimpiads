#include<iostream>
using namespace std;

int br1=0, br2=0, n, maxsum=0, sum=0;
int b[20], mst[20], st[20];

void gen(int k)
{
    int minimal, el;
    if(k==2*n)
    {
        if(sum>maxsum) maxsum=sum;
        return;
    }
    if(br1>=br2 && br1<n)
    {
        br1++;
        st[br1-br2-1]=b[br1-1];
        minimal=st[0];
        for(int j=1; j<br1-br2; j++)
            if(st[j]<minimal) minimal=st[j];
        sum+=minimal;
        gen(k+1);
        br1--;
        sum-=minimal;
    }
    if(br1>br2 && br1<=n)
    {
        br2++;
        if(br1>br2)
        {
            minimal=st[0];
            for(int j=1; j<br1-br2; j++)
                if(st[j]<minimal) minimal=st[j];
            sum+=minimal;
        }
        el=st[br1-br2];
        gen(k+1);
        br2--;
        st[br1-br2-1]=el;
        if(br1>br2+1) sum-=minimal;
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> b[i];
    gen(0);
    cout << maxsum << endl;
    return 0;
}