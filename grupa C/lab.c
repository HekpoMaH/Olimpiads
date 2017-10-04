#include <iostream>
using namespace std;
char m[20][20];
int n,br=0;
bool way = false;

void init()
{int i, j;
 do
 {cout << "n= ";
  cin >> n;
 } while(n < 1 || n > 20);
 do
 {cout << "labyrinth:\n";
  for (i = 0; i <= n-1; i++)
  for (j = 0; j <= n-1; j++)
    cin >> m[i][j];
 } while (m[0][0] != '0');
}
	void writelab()
{int k, l;
cout << endl;

for (k = 0; k <= n-1; k++)
  {for (l = 0; l <= n-1; l++)
     cout << m[k][l] << " ";
   cout << endl;
  }
}
void labyrinth(int i, int j)
{if (i == n-1 && j == n-1)
 {m[i][j] = '*';
  way = true;
  writelab();
  br++;
 }
 else
  if (i >= 0 && i <= n-1 && j >= 0 && j <= n-1)
	if(m[i][j] == '0')
	{m[i][j] = '*';
		 labyrinth(i+1, j);
	 labyrinth(i, j+1);
    labyrinth(i-1, j);
    labyrinth(i, j-1);
    m[i][j] = '0';
	}
}
	int main()
 {  init();
    labyrinth(0, 0);
    if (!way) cout << "no"<<endl;
    else cout<<br<<endl;
    return 0;
}
