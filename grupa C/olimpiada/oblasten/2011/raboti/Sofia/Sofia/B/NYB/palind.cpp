#include <cstdio>
#include <vector>
using namespace std;

int n;
int a[10002];
int d[10002];
int r[10002];
vector<int> out;
unsigned long long t1;
unsigned long long t2;
unsigned long long po;

bool isPalind(int s, int e)
{
    for (int i=0;i<(e-s)/2;i++) {
        if (a[s+i]!=a[e-i-1]) { return false; }
    }
    return true;
}

void solve()
{
    for (int i=1;i<=n;i++) {
        t1=0;
        t2=0;
        po=1;
        for (int j=i-1;j>=0;j--) {
            if (d[j]==0 && j!=0) { continue; }
            t1*=2;
            t1+=a[j];
            t2+=a[j]*po;
            po*=2;
            if (po==0) { po=2; }
            if (t1==t2) {
                if (d[j]+1<d[i] || d[i]==0) {
                    d[i]=d[j]+1;
                    r[i]=j;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    solve();
    printf("%d\n", d[n]);
    for (int i=r[n];i>0;i=r[i]) {
        out.push_back(i);
    }
    if (out.size()==0) { return 0; }
    else { printf("%d", out[out.size()-1]); }
    for (int i=out.size()-2;i>=0;i--) {
        printf(" %d", out[i]);
    }
    printf("\n");
}
