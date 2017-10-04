#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int n;
int k,m;

vector <int> v;


int main()
{
   scanf("%d", &n);
   int t;

   for(int i=0; i<n; i++)
   {
      cin >> t;
      v.push_back(t);
      for(int j=0; j < v.size(); j++)
      {
         if(v[j] != 0)
         {
            if(t == v[j] && j!= v.size()-1)
            {
               //cout << v[v.size()-1] << "=" << v[j] << " " << v.size()-1 << " " << j <<endl ;
               v.pop_back();
               //v.erase();
               v[j] = 0;
               break;
            }
         }
      }
   }
   int p;
   for(int i=0; i<v.size(); i++)
   {
      if(v[i] != 0) {k = v[i]; p = i; break; }
   }

   for(int i=p+1; i<v.size(); i++)
   {
      if(v[i] != 0) {m = v[i]; break; }
   }

   if(k < m) cout << k << " " << m << endl;
   else cout << m << " " << k << endl;





}
