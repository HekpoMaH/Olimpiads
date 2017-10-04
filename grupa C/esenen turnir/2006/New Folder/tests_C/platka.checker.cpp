#define MAXMASK 0

#define MAXPOINTS 10

#include <iostream>
#include <fstream>
#include <string>
#define maxn 10000
using namespace std;
int a[maxn][maxn], n, m, vis[maxn], k;
ifstream fin;

//------------------------------
void init ()
{int i, j, u, v;
fin>>n>>m;
for (i=1; i<=m; i++)
    { fin>>u>>v;
    a[u][v] = a[v][u]=1;
    a[u][0] = !a[u][0]; 
    a[v][0] = !a[v][0]; 
}
}
//--------------------------------
void dfs(int u) // za proverkata dali grafa e svyrzan
{
     vis[u] = 1;
     for (int i = 1; i <= n; i++)
         if (a[u][i] && !vis[i])
            dfs(i);
}
//--------------------------------

bool IsAll()
{ int i, j;
for (i=1; i<=n; i++)
for (j=1; j<=n; j++)
    if (a[i][j]!=0) return false;
return true;
}
//----------------------------------
bool check_wrong()
{ 
     int i, u, br = 0;
     for (i = 1; i <= n; i++)
    	{   //cout << a[i][0] << " ";
            if (a[i][0]) { u = i; break;}
            }
	dfs(u);
	for (i = 1; i <= n; i++)
		if (!vis[i]) br++;
    string s;
    cin >> s;
    cin >> s;
    int b; 
    cin >> b;
    if (b == 0) return false;
    if (b != br && b != n-br) 
          return false;
    return true;
}
//--------------------------------
bool path()
{int v1, v2, i;
bool answ=true;
char c;
if (!(cin >> c)) return false;
if (c == 'S')
   { answ = check_wrong();
  //   cout << answ << endl;
     }
else
   { v1 = int(c) - '0';
     cin.get(c);
     while (c != ' ')
           {
                 v1 = v1*10 + int(c) - '0';
                 cin.get(c);
                 }
     for (i=1; i<=m; i++)
     {cin>>v2;
     if (a[v1][v2]==1) {
                       a[v1][v2]=a[v2][v1]=0;
                       v1=v2;}
     else {
          answ=false;
          break;
          }
     }
     if (!IsAll()) {
                   answ = false;
                   }
     }
return answ;
}


//--------------------------
int main(int argc, char **argv)
{
	if(argc != 4)
	{
		printf("argument error");
		return 0;
	}
	
	FILE * fo = freopen(argv[2],"r",stdin);
	if(fo == NULL)
	{
		printf("0\nCannot open result.\n");
		return 0;
	}
	
	fin.open(argv[1], ios::in);
	
    init();
	/*
    if (path()) cout<<"10\nOK\n"<<endl;
		
    else cout<<"0\nWrong answer\n"<<endl;
	*/	
	if (path())
	{
		printf("%d\n", MAXPOINTS*MAXMASK+MAXPOINTS);
		printf("Correct solution.\n");
	}
	else
	{
		printf("0\n");
		printf("Wrong answer.\n");
	}
	fin.close();
	return 0;
}
