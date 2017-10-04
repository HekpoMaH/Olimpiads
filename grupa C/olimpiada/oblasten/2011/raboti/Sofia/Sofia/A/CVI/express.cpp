#include <iostream>
#include <vector>

using namespace std;

long long m;

class exp
{
     public:
     vector<int> a;
     vector<char> b;

     exp(string s)
     {
          for (int i=0; i<s.size();i++)
          {
               if (i%2==0)
                    a.push_back(s[i]-'0');
               else
                    b.push_back(s[i]);
          }
     }
};

     long long sum(exp f)
     {
          exp temp = f;
          long long e = 0;
          for (int i = 0; i< temp.b.size();i++)
          {
               if (temp.b[i] == '-')
               {
                    temp.b[i] = '+';
                    if (i==temp.b.size()-1)
                    {
                         temp.a[i+1]*=-1;
                    }
                    else
                    {
                         temp.a.insert(temp.a.begin()+i+2,1,-1);
                         temp.b.insert(temp.b.begin()+i+2,1,'*');
                    }
               }
          }

          for (int i=0;i<temp.b.size();i++)
          {
               if (temp.b[i] == '*')
               {
                    temp.a[i]*=temp.a[i+1];
                    temp.a[i+1] = temp.a[i];
                    temp.b[i]='#';
               }
          }

          for (int i =0; i<temp.b.size();i++)
          {
               if (temp.b[i]=='+')
               {
                    e+=temp.a[i];
               }
          }
          e+=temp.a.back();
          return e;
     }

void func (exp f)
{
     exp temp = f;
     for (int i=0;i<temp.b.size();i++)
     {
          temp = f;
          if (temp.b[i] == '+' || temp.b[i] == '-')
          {
               if (temp.b[i] == '+')
               {
                    temp.a[i+1]+=temp.a[i];
               }
               if (temp.b[i] == '-')
               {
                    temp.a[i+1] = temp.a[i] - temp.a[i+1];
               }
               temp.a.erase(temp.a.begin()+i);
               temp.b.erase(temp.b.begin()+i);
               m = min(m,sum(temp));
               func(temp);
          }
     }
     return;
}

int main()
{
     string s;
     cin >> s;
     exp a(s);
     m=sum(a);
     func(a);
     cout << m << '\n';
     return 0;
}
