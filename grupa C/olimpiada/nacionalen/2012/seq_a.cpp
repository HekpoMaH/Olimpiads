#include <iostream>
#define MAXK (long long)(1e15)

using namespace std;

typedef long long LL;

LL k, l[50];
int dig[8];
int n, i, j;

int cnt(int t) //������ ����� �� ������� �� ������� t.
{
int br = 0;

while(t) br++, t /= 10;
return br;
}

LL len(int n) //����� ��������� �� n-��� ������� �� ��������.
{
if(n > 49) return MAXK + 1;
return l[n];
}

int main()
{
cin >> n >> k;

//����������� ��������� �� ����� �������
l[1] = 1;
for(i=2; i<=49; i++) l[i] = 2 * l[i - 1] + cnt(i);
int t;
int br;

for(i=n; i>=1; i--)
{
br = cnt(i);
if(br >= k) { // �������� ���� �� ����� �� ���������� ������� ��������
      t = i;
      for(j=br-1; j>=0; j--) dig[j] = t % 10, t /= 10;
      cout << dig[k - 1] << endl;
      k = 0;
      break;
      }

k -= br;
if(k > len(i - 1)) k -= len(i - 1);
}

if(k > 0) cout << "-1\n";
return 0;
}
