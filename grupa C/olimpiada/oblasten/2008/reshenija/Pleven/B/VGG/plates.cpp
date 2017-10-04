#include <iostream>
#include <vector>
#include <string>
using namespace std;
char v[1000][30][30];
char a[30][30];
bool f[3][5];
int m,n;
int main()
{
	cin >> m >> n;
	string s="";
	char c;
	int i,j,k,l,q,qq,o,p,x,y,br=0;
	for (q=0; q<m; q++)
	{
		bool fl=false;
		for (x=0; x<n; x++)
		{
			for (y=0; y<n; y++)
			{
				cin>>a[x][y];
			}
		}
		for (i=0; i<br; i++)
		{
			for (qq=1; qq<=2; qq++)
		 		for (l=1; l<=4; l++)
		  			f[qq][l]=false;
			for (x=0; x<n; x++)
			 for (y=0; y<n; y++)
			 {	
					int xx=x;
					int yy=y;
					o=n-xx-1;
					p=n-yy-1;
					if (v[i][xx][yy]!=a[x][y])  f[1][1]=true;
					if (v[i][yy][o]!=a[x][y])  f[1][2]=true; 
					if (v[i][o][p]!=a[x][y])  f[1][3]=true; 
					if (v[i][p][xx]!=a[x][y])  f[1][4]=true; 
					xx=n-x-1;
					yy=n-y-1;
					if (v[i][xx][yy]!=a[x][y])  f[2][1]=true; 
					if (v[i][yy][o]!=a[x][y])  f[2][2]=true; 
					if (v[i][o][p]!=a[x][y])  f[2][3]=true; 
					if (v[i][p][xx]!=a[x][y])  f[2][4]=true;
			}
		  if (!(f[1][1] & f[1][2] & f[1][3] & f[1][4] & f[2][1] & f[2][2] & f[2][3] & f[2][4]))
		  {
				break;
		  }
		}
		if (br==0 || (f[1][1] & f[1][2] & f[1][3] & f[1][4] & f[2][1] & f[2][2] & f[2][3] & f[2][4])) fl=true;
		if (fl==true)
		{
			//cout << q << endl;
			for (i=0; i<n; i++)
			 for (j=0; j<n; j++)
			  v[br][i][j]=a[i][j];
			br++;
		}
	}
//	br--;
	cout << br << "\n";
	return 0;
}
			
					
