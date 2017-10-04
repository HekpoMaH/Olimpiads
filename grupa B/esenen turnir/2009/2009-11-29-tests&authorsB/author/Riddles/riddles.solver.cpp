/*
LANG: C++
TASK: riddles
ID: espr1t
*/

#include <iostream>
#include <ctime>

#define MAX 131072
#define MM 1048576

#define DEBUG_INFO 1
// 35.957s with 18184 for test 14
//  3.094s with 29821 for test 15

using namespace std;
FILE *in; FILE *out;

int n, k;
int a[MAX], v[MAX], vis[MM];

int greed(int n)
{
	memset(vis, 0, sizeof(vis)); vis[0] = 1;	
	for (int i=0; i<n; i++) v[i] = a[i]; sort(v, v + n);
	
	int sum = 0;
	for (int i=0; i<n; i++) if (v[i] <= k)
	{
		if (v[i] > sum + 1) return 0;
		sum += v[i]; if (sum >= k) return 1;
	}
	return 0;
}


int eval(void)
{
	int ans = n + 1;
	int left = 0, right = n, mid;
	
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (greed(mid)) {ans = min(ans, mid); right = mid - 1;}
		else left = mid + 1;
	}	
	return ans > n ? -1 : ans;
}

int main(void)
{
	in = stdin; out = stdout;
	
	for (int test = 1; test <= 10; test++)
	{
		char inpFile[32], outFile[32];
		sprintf(inpFile, "riddles.%02d.in", test); in = fopen(inpFile, "rt");
		sprintf(outFile, "riddles.%02d.out", test); out = fopen(outFile, "wt");
		
		int numTests;
		fscanf(in, "%d", &numTests);
		
		for (int test = 0; test < numTests; test++)
		{
			unsigned sTime, eTime;
			if (DEBUG_INFO) sTime = clock();
	
			fscanf(in, "%d %d", &n, &k);
			for (int i=0; i<n; i++) fscanf(in, "%d", &a[i]);
			fprintf(out, "%d\n", eval());
	
			if (DEBUG_INFO)
			{
				eTime = clock();
				cout << "eval() returns " << eval() << endl;		
				cout << "Done with test Nr. " << test + 1 << " for " << (double)(eTime - sTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
			}
		}
		fclose(in); fclose(out);
	}
	if (DEBUG_INFO) system("pause");
	return 0;
}
