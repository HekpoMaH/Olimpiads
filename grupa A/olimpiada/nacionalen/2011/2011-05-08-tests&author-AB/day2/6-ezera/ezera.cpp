#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <int> S;
int C=0,BE=0;
int E[10000][2];
int main()
{
    string L;
    int i,ls;
    cin >> L;
    ls=L.size();
    for (i=0; i<ls; i++)
    {
        if (L[i]=='\\') S.push(i);
        if (L[i]=='/' && S.size()>0)
        {
                      int x=S.top();
                      S.pop();
                      C+=i-x;
                      E[BE][0]=x;
                      E[BE][1]=i;
                      BE++;
                      while (BE>1)
                      {
                            if (E[BE-1][0]<E[BE-2][0] && E[BE-1][1]>E[BE-2][1])
                            {
                                                      E[BE-2][0]=E[BE-1][0];
                                                      E[BE-2][1]=E[BE-1][1];
                                                      BE--;
                            }
                            else break;
                      }
        }
    }
    cout << BE << ' ' << C << '\n'; 
    return 0;
}