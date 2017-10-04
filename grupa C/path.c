#include <iostream>
using namespace std;
int arr[10][10] = {0};
int n, s = -1;
int x[100];
bool way = false;
void writeway()
{for (int i = 0; i <= s; i++)
  cout << x[i] << " ";
 cout << endl;
}
bool member(int x, int n, int* a)
{if (n == 1) return a[0] == x;
 return x == a[0] || member(x, n-1, a+1);
}
void foundallway(int i, int j)
{if (i == j)
 {way = true;
  s++;
  cout<<"sr="<<s<<" ";
  x[s] = i;
  cout<<"x["<<s<<"]="<<x[s]<<endl;
  writeway();
 }
 else
 {s++;
 cout<<"s1="<<s<<endl;
  x[s] = i;
  for (int k = 0; k <= n-1; k++)
	 if (arr[i][k] == 1 && !member(k, s+1, x))
	 { cout<<"kanditat"<<" "<<i<<" "<<k<<endl;
	   arr[i][k] = 0; arr[k][i] = 0;
	  foundallway(k, j);
	  arr[i][k] = 1; arr[k][i] = 1;
	  s--;cout<<"s2="<<s<<endl;
	 }
	}
}
int main()
{do
 {cout << "n= ";
  cin >> n;
 } while (n < 1 || n > 10);
 for (int i = 0; i <= n-2; i++)
   for (int j = i+1; j <= n-1; j++)
   {cout << "connection between " <<  i << " and "
		   << j << " 0/1? ";
	 cin >> arr[i][j];
	 arr[j][i] = arr[i][j];
   }
 int j,i;
 do
 {
   cout << "start and final towns: ";
   cin >> i >> j;
 } while (i < 0 || i > 9 || j < 0 || j > 9);
 foundallway(i, j);
 if (!way) cout << "no \n";
 return 0;
}
