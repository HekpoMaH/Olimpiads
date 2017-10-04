// Task: DOMINO
// Author: S. Kapralov

#include <iostream>
#include <vector>
using namespace std;

string a[7];
string d[28]={"00","01","02","03","04","05","06",
                   "11","12","13","14","15","16",
                        "22","23","24","25","26",
                             "33","34","35","36",
                                  "44","45","46",
                                       "55","56",
                                            "66"};

typedef pair<int,int> pos;

vector<pos> p[28];

int cnt;
int b[56];

void place(int k)
{ if(k==28)
  { cnt++;
    return;
  }

  for(int i=0; i<p[k].size(); i++)
  { int x=p[k][i].first, y=p[k][i].second;
    if(b[x]==-1 && b[y]==-1)
    { b[x]=k; b[y]=k;
      place(k+1);
      b[x]=-1; b[y]=-1;
    }
  }
}

int main()
{ for(int i=0; i<7; i++)
    cin >> a[i];

  for(int k=0; k<28; k++)
  {
    for(int i=0; i<7; i++)
    for(int j=0; j<8; j++)
    { char x1,x2;
      if(j+1<8)
      { x1=a[i][j], x2=a[i][j+1];
        if(x1>x2) swap(x1,x2);
        if(d[k][0]==x1 && d[k][1]==x2)
          p[k].push_back(pos(i*8+j,i*8+j+1));
      }
      if(i+1<7)
      { x1=a[i][j], x2=a[i+1][j];
        if(x1>x2) swap(x1,x2);
        if(d[k][0]==x1 && d[k][1]==x2)
          p[k].push_back(pos(i*8+j,(i+1)*8+j));
      }
    }
  }

  cnt = 0;
  for(int i=0; i<56; i++)
    b[i]=-1;
  place(0);
  cout << cnt << endl;

  return 0;
}
