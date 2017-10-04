#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct cell
{
    int x, y;
    };

vector<cell> v;

int A[1024][1024];

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
    }

int n;
void solve()
{
    int li=0, S=0;
    cin>>n;
    cell c;
    int x, y;
    for(int i=0; i<2*n; i++)
    {cin>>c.x>>c.y;
    v.push_back(c);
    }
    int minn=1002;
    cell tc, rc;
    tc.x=0;
    tc.y=0;
    for(int k=0; k<n; k++){
    for(int i=0; i<v.size(); i++)
    {
    if(abs(max(tc.x, tc.y)-max(v[i].x, v[i].y))<minn){minn= abs(max(tc.x, tc.y)-max(v[i].x, v[i].y)); li=i; rc.x=v[i].x; rc.y=v[i].y;}
    
        }
        
        
        v.erase(v.begin()+li, v.begin()+li+1);

        tc.x=rc.x;
        tc.y=rc.y;
        S+=minn;
        minn=1002;
        }
        cout<<S<<endl;
    
    }



int main()
{
    
    solve();


    return 0;
    }
