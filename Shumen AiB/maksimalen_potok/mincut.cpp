//Stoer and Wagner algorithm for finding mincut
//O(n^3)
#include<bits/stdc++.h>
using namespace std;
const int nmax=509;
int n,g[nmax][nmax],m;
int best_cost=1e9;
vector<int> best_cut;
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[x-1][y-1]=g[y-1][x-1]=z;
   }
}
void mincut() {
	vector<int> v[nmax];
	for (int i=0; i<n; ++i)
		v[i].assign (1, i);
	int w[nmax];
	bool exist[nmax], in_a[nmax];
	memset (exist, true, sizeof exist);
	for (int ph=0; ph<n-1; ++ph) {
		memset (in_a, false, sizeof in_a);
		memset (w, 0, sizeof w);
		for (int it=0, prev; it<n-ph; ++it) {
			int sel = -1;
			for (int i=0; i<n; ++i)
				if (exist[i] && !in_a[i] && (sel == -1 || w[i] > w[sel]))
					sel = i;
			if (it == n-ph-1) {
                           cout<<sel<<" "<<w[sel]<<"\n";
				if (w[sel] < best_cost)
					best_cost = w[sel],  best_cut = v[sel];
				v[prev].insert (v[prev].end(), v[sel].begin(), v[sel].end());
				for (int i=0; i<n; ++i)
					g[prev][i] = g[i][prev] += g[sel][i];
				exist[sel] = false;
			}
			else {
				in_a[sel] = true;
				for (int i=0; i<n; ++i)
					w[i] += g[sel][i];
				prev = sel;
			}
		}
	}
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   mincut();
   cout<<best_cost<<"\n";
}
