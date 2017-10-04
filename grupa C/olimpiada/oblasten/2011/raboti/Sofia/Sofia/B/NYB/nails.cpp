#include <cstdio>
#include <vector>
using namespace std;

struct line {
    int sx,sy;
    int ex,ey;
};
line vhod[1002];

int n;
bool pos[1002];
vector<int> q;

bool check(int a, int b)
{
    int f=((vhod[a].ex-vhod[a].sx)*(vhod[b].ey-vhod[a].sy)-(vhod[b].ex-vhod[a].sx)*(vhod[a].ey-vhod[a].sy));
    int s=((vhod[a].ex-vhod[a].sx)*(vhod[b].sy-vhod[a].sy)-(vhod[b].sx-vhod[a].sx)*(vhod[a].ey-vhod[a].sy));
    if ((f>0 && s>0) || (f<0 && s<0)) { return false; }
    f=((vhod[b].ex-vhod[b].sx)*(vhod[a].ey-vhod[b].sy)-(vhod[a].ex-vhod[b].sx)*(vhod[b].ey-vhod[b].sy));
    s=((vhod[b].ex-vhod[b].sx)*(vhod[a].sy-vhod[b].sy)-(vhod[a].sx-vhod[b].sx)*(vhod[b].ey-vhod[b].sy));
    if ((f>0 && s>0) || (f<0 && s<0)) { return false; }
    return true;
}

void bfs()
{
    q.push_back(n-1);
    pos[n-1]=true;
    for (int i=0;i<q.size();i++) {
        for (int j=0;j<n;j++) {
            if (pos[j]==true) { continue; }
            if (check(q[i], j)) {
                pos[j]=true;
                q.push_back(j);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d%d%d", &vhod[n].sx, &vhod[n].sy, &vhod[n].ex, &vhod[n].ey)>0)
    {
        n++;
    }
    bfs();
    printf("%d\n", n-q.size());
    return 0;
}
