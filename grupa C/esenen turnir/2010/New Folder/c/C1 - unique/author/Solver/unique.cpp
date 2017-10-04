#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

int vis[10];
long long lim1, lim2;

long long getLong(char* num)
{
	int len = strlen(num);
	if (len > 10) return 10000000000LL;
	long long ret = 0;
	for (int i = 0; i < len; i++)
		ret = ret * 10 + num[i] - 48;
	return ret;
}

int recurse(long long num)
{
	if (num > lim2) return 0;
	long long ans = (num >= lim1 && num <= lim2);
	for (int dig = !num; dig < 10; dig++) if (!vis[dig])
	{
		vis[dig] = 1;
		ans += recurse(num * 10 + dig);
		vis[dig] = 0;
	}
	return ans;
}

void solve()
{
	char num1[128], num2[128];
	scanf("%s %s", num1, num2);

	lim1 = getLong(num1);
	lim2 = getLong(num2);

	printf("%d\n", recurse(0));
}

int main(void)
{
	solve();
	return 0;
}
