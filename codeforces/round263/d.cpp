#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define L first
#define R second
#define MP make_pair
#define PB push_back

const int maxn = 1e5 + 100;
const long long mode = 1e9 + 7;
long long dp[maxn][2];
vector<int> v[maxn];
int p[maxn];
bool sts[maxn];

long long power(long long fi, long long se){
	if(se == 0)
		return 1;
	long long ret = power(fi, se/2);
	ret *= ret;
	ret %= mode;
	if(se % 2)
		return (ret * fi) % mode;
	return ret;
}

void dfs(int x){
	for(int i=0;i<v[x].size();i++){
		int child = v[x][i];
		dfs(child);
	}
	dp[x][0] = 1;
	for(int i=0;i<v[x].size();i++){
		int child = v[x][i];
		dp[x][0] *= (dp[child][1] + dp[child][0]);
		dp[x][0] %= mode;
	}
	if(sts[x]){
		dp[x][1] = dp[x][0];
		dp[x][0] = 0;
		return ;
	}
	for(int i=0;i<v[x].size();i++){
		int child = v[x][i];
		long long res = dp[x][0];
		res *= power(dp[child][1] + dp[child][0], mode - 2);
		res = ((res % mode) + mode) % mode;
		res *= dp[child][1];
		res %= mode;
		dp[x][1] += res;
		dp[x][1] %= mode;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> p[i];
		v[p[i]].PB(i);
	} for(int i=0;i<n;i++)
		cin >> sts[i];
	dfs(0);
	cout << dp[0][1] << endl;
}
