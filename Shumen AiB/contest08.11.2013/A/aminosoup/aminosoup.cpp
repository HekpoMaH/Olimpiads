/*
AUTH: Petar Ivanov
PROB: aminosoup (�������������� �����)
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
const int MOD   = 602214179;												// ��������� �� �������� = 6.02214179�23

typedef long long type;														// ���������� �� int ������ ��������� 
typedef type matrix[1<<MAX_M][1<<MAX_M];

type n;
int m, t;
matrix A, B;

void matrix_init ()
{
	int i, j, k;
	int dp[MAX_M];

	for (i=0; i<t; i++) {													// ���������� �� ������ �������� ���������� �� ��������� ���
		for (j=0; j<t; j++) {												// ���������� �� ������ �������� ���������� �� ������� ���, ���� ���� ��������������� �� ����������, ������ ������ �� ��������� ��� ������ �� �� ��������
			memset (dp,0,sizeof(dp));										// dp[w] := �� ����� ������ ����� �� �� ����������� ���������� � ������� w ������ (��� ��������� ���������� �� ������� � ������� ���)

			for (k=0; k<m; k++) {											// �� ����� �� ����� ������ ����� �� ������� �� �������� ����� k
				if (j&(1<<k)) {												// ��� ������ �� �������� ������ ������ k
					if (i&(1<<k)) {											// ��� ��� ��� ���� � ���������
						if (k && (j&(1<<(k-1))) && (i&(1<<(k-1))) )			// ��� ������ �� ��� � ����� � ��� ������ ������ � �����
							dp[k] += k>1?dp[k-2]:1;							// ��������� �������� ������������
					}
					else {													// ��� ��� �������� ������ ��� �� � ���������
						dp[k] += k?dp[k-1]:1;								// ��������� �������� ����������
					}
				} else {													// ��� ������ �� ������� �������� ������ �����������
					if (i&(1<<k))											// ���� ��� ��� ��� � ���� ����������
						dp[k] += k?dp[k-1]:1;								// �� ��������� �������
				}
			}

			A[i][j] = dp[m-1];												// �� ����� ������ ���� �� �� ������� �� ��� ��� ��������� i ��� ������� ��� ��� ��������� j
		}
	}
}

inline void add_mod (type &a, type b) { a=(a+b)%MOD; }

// ��������� �� ��� ������� � ���������� t ���� �� t ������ -> O(t^3)
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

// ����� ��������� �� ������� �� ������ p -> O(log(p))
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
// ����� ��������� �� ������� �� ������ p -> O(p)
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

	t = 1<<m;											// ���� �� ���������� ������ �� ���������� �� ���
	matrix_init ();
	matrix_power (n);

	cout << B[t-1][t-1] << "\n";						// �� ������� ��������� �������� ��� ����

	return 0;
}
