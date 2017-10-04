#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>c,r;
long long a[1040][1040];
long long sr[1000400],sc[1000400];
int main()
{
    long long n,m,k,p,i,j,s,o,cc,cr;
    cin>>n>>m>>k>>p;
    for(i=0;i<n;i++){
        s=0;
        for(j=0;j<m;j++){
            cin>>a[i][j];
            s+=a[i][j];
        }
        r.push(s);
    }
    for(j=0;j<m;j++){
        s=0;
        for(i=0;i<n;i++)
             s+=a[i][j];
        c.push(s);
    }
    vector<long long>co,ro;
    for(i=0;i<k;i++){
        cc=c.top();
        cr=r.top();
        co.push_back(cc);
        ro.push_back(cr);
        c.pop();
        r.pop();
        c.push(cc-p*n);
        r.push(cr-p*m);
    }
    sr[0]=sc[0]=0;
    for(i=1;i<=k;i++){
        sr[i]=sr[i-1]+ro[i-1];
        sc[i]=sc[i-1]+co[i-1];
    }
    o=sc[k];
    for(i=1;i<=k;i++)
        o=max(o,sr[i]+sc[k-i]-i*p*(k-i));
    cout<<o<<endl;
}
