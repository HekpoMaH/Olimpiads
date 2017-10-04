#include <iostream>

using namespace std;

struct nail{
      int beg[2];
      int end[2];
};

int det(int ax, int bx, int cx, int ay, int by, int cy)
{
      return (ax*by + ay*cx + bx*cy - cx*by - cy*ax - bx*ay);
}

int main()
{
      int n;
      cin >> n;
      nail Nails[n];
      nail Line;
      for(int i = 0; i < n; i++) cin >> Nails[i].beg[0] >> Nails[i].beg[1] >>Nails[i].end[0] >>Nails[i].end[1];
      cin >> Line.beg[0]>> Line.beg[1] >> Line.end[0] >> Line.end[1];
      int count = 0;
      int crossing[n];
      for(int i = 0; i < n; i++)
      {
            crossing[i] = 0;
            if(det(Line.beg[0], Line.beg[1], Line.end[0], Line.end[1], Nails[i].beg[0], Nails[i].beg[1])*det(Line.beg[0], Line.beg[1], Line.end[0], Line.end[1], Nails[i].end[0], Nails[i].end[1]) < 0) {count++; crossing[i] = 1;}
      }
      int k;
      for(int i = 0; i < n; i++)
      {
            if(crossing[i] == 1){
                  for(k = 0; k <= n; k++)
                  if(det(Nails[i].beg[0], Nails[i].beg[1], Nails[i].end[0], Nails[i].end[1], Nails[k].beg[0], Nails[k].beg[1])*det(Nails[i].beg[0], Nails[i].beg[1], Nails[i].end[0], Nails[i].end[1], Nails[k].end[0], Nails[k].end[1]) < 0) {count++; crossing[k] = 1;}
            }
      }
      cout << count;
      return 0;
}
