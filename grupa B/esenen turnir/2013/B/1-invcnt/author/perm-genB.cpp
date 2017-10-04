// ������ ������ �� ����������� - 2013
// ������: ���� �� ����������
// �����: ����� ��������
// ��������� �� ����������
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int NMAX = 1000000;
int a[NMAX];

// n -���� ��������
// seed - �� ���������� �� �������� �����
void permgen(int n, int seed,int t)
{ srand(seed);
  for(int i=0; i<n; i++)
    a[i] = i+1;
  for(int k=0; k<t; k++)
  { int p = rand()%n;
    int q = rand()%n;
    swap(a[p],a[q]);
  }
}

int main()
{ int n,seed,t;
  cin >> n >> seed >> t;

  permgen(n,seed,t);
  cout << n << endl;
  for(int i=0; i<n-1; i++)
    cout << a[i] << " ";
  cout << a[n-1] << endl;

  return 0;
}

