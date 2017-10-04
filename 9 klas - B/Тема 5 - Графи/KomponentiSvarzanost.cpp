#include <iostream>
#include <vector>
using namespace std;
vector <vector <int> > g, gr;
vector <bool> used;
vector <int> order, component;
int n, m;
void dfs1 (int v)
{
	used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    	if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back(v);
}

void dfs2 (int v)
{
	used[v] = true;
	component.push_back(v);
	for (int i = 0; i < gr[v].size(); i++)
		if (!used[ gr[v][i] ])
			dfs2(gr[v][i]);
}

int main()
{
    cin >> n>>m;
    g.resize(n); gr.resize(n);
    int x, y;
    for (int i=1; i<=m;i++)
    {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

	used = vector < bool > (n, false);
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);

	used = vector <bool> (n, false);
	for (int i = n - 1; i >= 0; i--)
		if (!used[order[i]])
		 {
			dfs2(order[i]);
            for (int i = 0; i < component.size(); i++)
                cout << component [i]<<" ";
            cout << endl;
            component.clear();
        }
    return 0;
}
