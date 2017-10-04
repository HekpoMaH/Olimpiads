#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int MAXHR = 5;
const int MAXN = 100000;
const int MAXV = 1000000;

string bver, ever;
vector<string> nums[MAXHR];

void RS(string &s)
{
	int i;
	s = "";
	for (i = 0; i < 10; i++)
	{
		char c = getchar();
		while (! ((c >= '0') && (c <= '9'))) c = getchar();
		s += c;
	}
}

void Load()
{
	RS(bver);
	RS(ever);
	int i;
	nums[0].push_back(bver);
	nums[4].push_back(ever);
	for (i = 0; i < MAXHR; i++)
	{
		int cn;
		scanf("%d", &cn);
		int j;
		for (j = 0; j < cn; j++)
		{
			string s;
			RS(s);
			nums[i].push_back(s);
		}
	}
}

int res[MAXHR][MAXN];
int pth[MAXHR][MAXN];
int go[MAXV][10];
int what[MAXV];
int mvs[MAXV];
int mvcost[MAXV];
int nver;
int chr;

void Dfs(int v, int ocost, int opath)
{
	int i;
	if (mvcost[v] < ocost)
	{
		ocost = mvcost[v];
		opath = mvs[v];
	}
	for (i = 0; i < 10; i++)
	{
		if (go[v][i] != -1) Dfs(go[v][i], ocost, opath);
	}
	if (what[v] != -1)
	{
		res[chr][what[v]] = ocost;
		pth[chr][what[v]] = opath;
	}
}

void Solve()
{
	memset(res, 0x7F, sizeof(res));
	res[0][0] = 0;
	int i, j, cver, k;
	nver = MAXV;
	for (i = 0; i < MAXHR - 1; i++)
	{
		memset(go, 0xFF, sizeof(go[0]) * nver);
		memset(what, 0xFF, sizeof(int) * nver);
		memset(mvcost, 0x7F, sizeof(int) * nver);
		nver = 1;
		for (j = 0; j < nums[i + 1].size(); j++)
		{
			cver = 0;
			for (k = 0; k < nums[i + 1][j].length(); k++)
			{
				if (go[cver][nums[i + 1][j][k] - '0'] == -1)
				{
					go[cver][nums[i + 1][j][k] - '0'] = nver;
					nver++;
				}
				cver = go[cver][nums[i + 1][j][k] - '0'];
			}
			what[cver] = j;
		}
		for (j = 0; j < nums[i].size(); j++)
		{
			cver = 0;
			int ccost = 10 - 0 + res[i][j];
			if (mvcost[cver] > ccost)
			{
				mvcost[cver] = ccost;
				mvs[cver] = j;
			}
			for (k = 0; k < nums[i][j].length(); k++)
			{
				if (go[cver][nums[i][j][k] - '0'] == -1) break;
				cver = go[cver][nums[i][j][k] - '0'];
				ccost--;
				if (mvcost[cver] > ccost)
				{
					mvcost[cver] = ccost;
					mvs[cver] = j;
				}
			}
		}
		chr = i + 1;
		Dfs(0, mvcost[0], mvs[0]);
	}
	int ch, cv;
	ch = MAXHR - 1;
	cv = 0;
	vector<string> ans;
	while (! ((ch == 0) && (cv == 0)))
	{
		ans.push_back(nums[ch][cv]);
		cv = pth[ch][cv];
		ch--;
	}
	ans.push_back(nums[0][0]);
	reverse(ans.begin(), ans.end());
	printf("%d %d\n", res[MAXHR - 1][0], ans.size());
	for (i = 0; i < ans.size(); i++) printf("%s\n", ans[i].c_str());
}

int main()
{
	freopen("sms.in", "rt", stdin);
	freopen("sms.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}