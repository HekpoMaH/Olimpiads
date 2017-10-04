/*
AUTH: Petar Ivanov
PROB: aminosoup (Аминокиселинна чорба)
CONT: Shumen 2008
ALGO: (dp or recursion) + fast matrix power -> O(m * 2^m * 2^m) + O((2^m)^3 * log(n)) -- 100pts
MORE: 
brute force -> exponential -- ~30pts
dp for the whole matrix -- ~50pts
(dp or recursion) + slow matrix power -> O(m * 2^m * 2^m) + O((2^m)^3 * n) -- ~70pts
*/

#include <iostream>
#include <memory.h>
using namespace std;

const int MAX_M = 6;
const int MOD   = 602214179;												// Константа на Авогадро = 6.02214179е23

typedef long long type;														// препълване на int поради умножение 
typedef type matrix[1<<MAX_M][1<<MAX_M];

type n;
int m, t;
matrix A, B;

void matrix_init ()
{
	int i, j, k;
	int dp[MAX_M];

	for (i=0; i<t; i++) {													// генериране на всички възможни запълвания на предишния ред
		for (j=0; j<t; j++) {												// генериране на всички възможни запълвания на текущия ред, като след разпределението на елементите, всички клетки от предишния ред трябва да се запълнят
			memset (dp,0,sizeof(dp));										// dp[w] := по колко начина могат да се разпределят елементите в първите w стълба (при фиксирани запълвания на миналия и текущия ред)

			for (k=0; k<m; k++) {											// ше броим по колко начина можем да стигнем до поредния стълб k
				if (j&(1<<k)) {												// ако трябва да запълним новата клетка k
					if (i&(1<<k)) {											// ако над нея вече е запълнено
						if (k && (j&(1<<(k-1))) && (i&(1<<(k-1))) )			// ако отляво на нея е пълно и над лявата клетка е пълно
							dp[k] += k>1?dp[k-2]:1;							// поставяме елемента хоризонтално
					}
					else {													// ако над текущата клетка още не е запълнено
						dp[k] += k?dp[k-1]:1;								// поставяме елемента вертикално
					}
				} else {													// ако трябва да оставим текущата клетка незапълнена
					if (i&(1<<k))											// само ако над нея е вече запълняено
						dp[k] += k?dp[k-1]:1;								// не поставяме елемент
				}
			}

			A[i][j] = dp[m-1];												// по колко начина може да се премине от ред със запълване i към следващ ред със запълване j
		}
	}
}

inline void add_mod (type &a, type b) { a=(a+b)%MOD; }

// умножение на две матрици с размерност t реда на t стълба -> O(t^3)
void matrix_mult (matrix C, matrix D)
{
	int i, j, k;
	matrix ans;

	memset (ans,0,sizeof(ans));

	for (i=0; i<t; i++)
		for (j=0; j<t; j++)
			for (k=0; k<t; k++)
				add_mod (ans[i][j], C[i][k]*D[k][j]);

	memcpy (C,ans,sizeof(ans));
}

// бързо повдигане на матрица на степен p -> O(log(p))
void matrix_power (type p)
{
	if (p==1) memcpy(B,A,sizeof(A));
	else {
		matrix_power (p>>1);
		matrix_mult (B,B);
		if (p&1) matrix_mult (B,A); 
	}
}

/*
// бавно повдигане на матрица на степен p -> O(p)
void matrix_power (type p)
{
	int i;

	memcpy(B,A,sizeof(A));

	for (i=1; i<p; i++)
		matrix_mult (B,A);
}
*/

int main ()
{
	cin >> n >> m;

	t = 1<<m;											// брой на различните начини за генериране на ред
	matrix_init ();
	matrix_power (n);

	cout << B[t-1][t-1] << "\n";						// за напълно запълнени последни два реда

	return 0;
}
