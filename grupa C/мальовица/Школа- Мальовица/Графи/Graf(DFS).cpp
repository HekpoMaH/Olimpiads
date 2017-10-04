#include <iostream>
#include <vector>
using namespace std;
int visit[100];
int M[100][100];
int n,x;
vector < int > check(99);
vector < int > path;
void pathcheck(vector < int > path)
{
     if (path.size() <= check.size())
     {
        check.clear();
        for (int i=0;i<path.size();i++)
        check.push_back(path[i]);
     }
}
void solve(int z)
{
     if (z==x) 
     {  
        path.push_back(x+1);
        pathcheck(path);
        path.pop_back();
     }
     else 
     {
          if (z<=n)
          for (int i=0;i<n;i++)
          if ((visit[i]==0)&&(M[z][i]==1))
          {
             visit[z]=1;
             path.push_back(z+1);
             solve(i);
             path.pop_back();
             visit[z]=0;
          }
     }
}
int main()
{
    int z;
    cin >> n;
    cin >> z >> x;
    for (int q=0;q<n;q++)
        for (int w=0;w<n;w++)
        {
            if (q==w) M[q][w]=0;
            else
            {
             cout << "M[" << q+1 << "][" << w+1 << "]= ";
             cin >> M[q][w];
            }
        }
    x--;z--;
    solve(z);
    for (int p=0;p<check.size();p++)
    cout << check[p] << " ";
    cout << endl;
system("pause");
return 0;
}
