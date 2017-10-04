#include <cstdio>
#include <iostream>
#include <vector>

#define pb(x) push_back(x)
#define pii pair<int,int>
#define left first
#define right second
using namespace std;

int n;
vector<pii> a;
int path[16][16];
int used[16];
int minsum=10000;

void init() {
     cin >> n;
     n*=2;
     pii b;
     b.left=0;
     b.right=0;
     a.pb(b);
     for (int i=0;i<n;i++) {
         cin >> b.left >> b.right;
         a.pb(b);
         }
}

void genpath() {
     for (int i=0;i<n-1;i++)
         for (int j=i+1;j<n;j++) {
             int nm = min(abs((a[i].left-a[j].left)),abs((a[i].right-a[j].right)));
             int mm = max(abs((a[i].left-a[j].left)),abs((a[i].right-a[j].right)));
             if ((mm-nm)%2==0) path[i][j]=mm;
             else path[i][j]=10000;
         }
}

void dfs(int cur,int cnt,int sum) {
     if (cnt==(n/2) && sum<minsum){ minsum=sum; return;}
     used[cur]=1;
     for (int i=0;i<n;i++)
         if (used[i]==0) dfs(i,cnt+1,sum+path[cur][i]);
     used[cur]=0;
}

void solve() {
     genpath();
     dfs(0,0,0);
}

void print() {
     cout << minsum << endl;
}

int main () {
    init();
    solve();
    print();
return 0;   
}
