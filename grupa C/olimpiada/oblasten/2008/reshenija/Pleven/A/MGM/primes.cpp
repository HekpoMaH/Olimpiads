#include <cstdio>

#define f(i, n) for(int i = 0; i < n; i ++)
#define fo(i, a, b) for(int i = a; i <= b; i ++)

#define MAX_N (65536)


int N;
int MOD;
bool sieve[MAX_N];
int primes[MAX_N];
int primes_sz;
int dp[MAX_N];


void Read()
{
	scanf("%d", &N);
}

void Find_Primes_And_MOD()
{
	f(i, MAX_N) sieve[i] = true;
	
	sieve[0] = sieve[1] = false;;
	
	f(i, MAX_N) if(sieve[i])
	{
		for(int j = 2; j * i < MAX_N; j ++)
		{
			sieve[j * i] = false;
		}
	}
	
	primes_sz = 0;
	
	f(i, N) if(sieve[i])
	{
		primes[primes_sz ++] = i;
	}
	
	fo(i, N + 1, MAX_N - 1) if(sieve[i])
	{
		MOD = i;
		
		break;
	}
}

void Solve()
{
	Find_Primes_And_MOD();
	
	f(i, MAX_N) dp[i] = 0;
	
	dp[0] = 1;
	
	f(i, primes_sz)
	{
		fo(j, primes[i], N)
		{
			dp[j] = (dp[j] + dp[j - primes[i]]) % MOD;
		}
	}
}

void Write()
{
	printf("%d\n", dp[N]);
}

int main()
{
	Read();
	
	Solve();
	
	Write();
	
	
	return 0;
}
