#include <iostream>
#include <vector>

using namespace std;

struct Points
{int x,y;}temp;
vector < Points > A;
int br;

bool check(Points x,Points y, Points z)
{
     ++br;
     int result;
     Points a,b,c;
     a.x=y.x-x.x;
     a.y=y.y-x.y;
     b.x=z.x-y.x;
     b.y=z.y-y.y;
     c.x=x.x-z.x;
     c.y=x.y-z.y;
     result=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
     return (result > 0);
}

void solve ()
{
     int size=A.size();
     int k;
     for (int i=2; i<size; ++i)
     {
         if (i == size-1) k=0;
         else k=i; 
         if (!check(A[i-2],A[i-1],A[k]))
         {
            cout << "vdalbnat" << endl;
            return;
         }
     }
     cout << "ispaknal" << endl;
}

inline void read()
{
    while(cin)
    {
       cin >> temp.x >> temp.y;
       A.push_back(temp);
    }   
}

int main()
{
    read();
    solve();
system("pause");
return 0;
}
