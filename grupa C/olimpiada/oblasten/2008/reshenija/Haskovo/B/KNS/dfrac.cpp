#include <iostream>

using namespace std;

struct num
{
    int pos;
    bool visit;
}used[16];

short p;
int size, ans, fsize, upto;
unsigned long long int a, b, k, br;
int answer[64], final[32];

void print()
{
     unsigned long long int from, current;
     
     from=k%fsize;
     current=from-1;
     if (!from) current=fsize-1;
     for (int i=0; i<p; ++i)
     {
         if (current < fsize) cout << final[current++];
         else
         {
            current-=fsize;
            cout << final[current++];
         }
     } 
     cout << endl;
}

void find()
{
   unsigned long long int to;
    
    to=k+p-1;
    while (br < to)
    {
          ++br;
          a*=10;
          ans=a/b;
          a-=(ans*b);
          answer[size++]=ans;
          if (!used[ans].visit)
          {
             used[ans].visit=1;
             used[ans].pos=size-1;
          }
          else
          {
              upto=used[ans].pos;
              for (int i=used[ans].pos; i<size-1; ++i)
              final[fsize++]=answer[i];
              break;
          }
    }
    print();
}

void solve()
{
    unsigned long long int to;
    
    to=k+p-1;
    while (br < to)
    {
          ++br;
          a*=10;
          ans=a/b;
          a-=(ans*b);
          if (br >= k)
          answer[size++]=ans;
    }
    for (int i=0; i<size; ++i)
    cout << answer[i];
    cout << endl;
}

inline void read()
{
    cin >> a >> b;
    cin >> k >> p;
}

int main()
{
    read();
    if (k <= 13500000)
    solve();
    else
    find();
return 0;
}
