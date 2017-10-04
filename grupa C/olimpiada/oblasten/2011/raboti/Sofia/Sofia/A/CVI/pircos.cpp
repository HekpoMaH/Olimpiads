#include <iostream>
#include <vector>

using namespace std;

int main()
{
     int n;
     long long t;
     vector<long long> a;

     cin >> n;
     for (int i=0;i<n;i++)
     {
          cin >> t;
          if (a.size() == 0)
          {
               a.push_back(t);
               continue;
          }
          bool inside = false;
          for (int j=0; j<a.size();j++)
          {
               if (t == a[j])
               {
                    a.erase(a.begin()+j);
                    inside = true;
                    break;
               }
               if (t < a[j])
               {
                    a.insert(a.begin()+j,1,t);
                    inside=true;
                    break;
               }
          }
          if (!inside)
          {
               a.push_back(t);
          }
     }
     cout << a[0] << ' ' << a[1] << '\n';
     return 0;
}