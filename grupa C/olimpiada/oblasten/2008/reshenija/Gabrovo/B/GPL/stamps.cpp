#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
vector <int> b;
vector <int> solut;
int s,n,temp_s;
void init()
{
     cin>>s>>n;
     for(int i=1;i<=n;i++)
     {
             int temp;
             cin>>temp;
             a.push_back(temp);
             b.push_back(0);
             sort(a.begin(),a.end());
     }
}

bool prov()
{
     int temp=0;
     for(int i=0;i<a.size();i++)
             temp+=b[i]*a[i];
     if(temp==s)
     return 1;
     else return 0;
}
     
int temporary_r()
{
     int temp=0;
     for(int i=0;i<a.size();i++)
             temp+=b[i]*a[i];
     if(s-temp>0)
     return temp;
     else return 0;
}

void sol(int j)
{
   for(int i=0;i<=s/a[j];i++)
   {b[j]=i;
     if(prov()==false&&j-1>=0)
     sol(j-1);
     else if(prov())
     {   int temp=0;
         for(int i=0;i<a.size();i++)
                 temp+=b[i];
         solut.push_back(temp);
     }
    }
     
}

int main()
{
    init();
    sol(a.size()-1);
    sort(solut.begin(),solut.end());
    cout<<solut[0]<<endl;
    return 0;
}
