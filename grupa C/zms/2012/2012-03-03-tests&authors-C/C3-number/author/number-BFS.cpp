#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int MAX_LEN=100;
const int MAX_S = 9*MAX_LEN;
const int MAX_P = 9*9*MAX_LEN;

int len[MAX_S + 1][MAX_P + 1];
int last[MAX_S + 1][MAX_P + 1];

int main()
{
  memset(len, -1, sizeof(len));
  memset(last, -1, sizeof(last));

  len[0][0]=0; last[0][0]=1;
  
  queue <pair<int,int>> q;
  q.push(pair<int,int>(0,0));

  while(!q.empty())
  { auto x = q.front(); q.pop();
    int s = x.first, p = x.second;
    for(int k=last[s][p]; k<=9; k++)
    { int s1=s+k, p1=p+k*k;
      if(s1<=MAX_S && p1<=MAX_P && len[s1][p1]==-1)
      { len[s1][p1] = len[s][p]+1;
        last[s1][p1] = k;
        q.push(pair<int,int>(s1,p1));
      }
    }  
  }

  int tcnt;
  cin >> tcnt;
  for(int t=1; t<=tcnt; t++)
  { int s,p;
    string ans;
    cin >> s >> p;
    if(s > MAX_S || p > MAX_P || len[s][p]==-1 || len[s][p] > MAX_LEN) ans = "No solution";
    else
    {
      do
      { int k = last[s][p];
        char dig = '0' + k;
        ans= dig + ans;
        s = s - k;
        p = p - k*k; 
      } while(s>0 && p>0);
    }
    cout << ans << endl;     
  }

return 0;
}
