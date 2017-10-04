#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>


using namespace std;

typedef pair<int, char> argP;
typedef vector<argP> argV;

int methods;

char a[25];

argV BuildArgumentsList()
{
     argV res;
     for(int i =0 ; i < strlen(a); ++i)
             if(strchr("()+-/*^", a[i]))
                                  res.push_back(argP(i, a[i]));
     return res;
}

void replace(int begin, int end)
{
     int i;
     char b[25];
     for(i = 0; i < begin-1; ++i)
             b[i] = a[i];
     b[begin-1] = 'a';
     int k = end - begin;
  //   if(begin==end)
//                   k++;
     for(i = begin; i + k < strlen(a); ++i)
             b[i] = a[i + k];
     b[i] = 0;
     strcpy(a, b);
}                
             

void Simplify(char sign)
{
     bool b=false;
     do
     {
     b = false;     
      argV list = BuildArgumentsList();
     
      char last = 0;
      int lasti = 0;
      for(argV::iterator itr = list.begin(); itr!= list.end(); ++itr)
      {
          if(last == (*itr).second && last == sign)
          {
                  replace(lasti, (*itr).first);
                  b = true;
                  cout << a << endl;
                  break;
          }
          last = (*itr).second;
          lasti = (*itr).first;
      }
     } while(b) ;
          
     
}

void SimplifyAll(char sign)
{
     bool b=false;
     do
     {
     b = false;     
      argV list = BuildArgumentsList();

      for(argV::iterator itr = list.begin(); itr!= list.end(); ++itr)
      {
          if((*itr).second == sign)
          {
                  replace((*itr).first, (*itr).first+2);
                  b = true;
                  cout << a << endl;
                  break;
          }

      }
     } while(b) ;
          
     
}

void Prioritize(char* group)
{
     bool b=false;
     do
     {
     b = false;     
      argV list = BuildArgumentsList();
      
      bool bg = false;
      int start = 0;
      int count = 0;

      for(argV::iterator itr = list.begin(); itr!= list.end(); ++itr)
      {
          if(!bg && strchr(group, (*itr).second))
          {
                 bg = true;
                 start = (*itr).first;
                 count++;
          }
          else if(bg && strchr(group, (*itr).second))
          {
               count++;
          }
          else
          {
              bg = false;
              if(count>1)
                         methods += count * (count + 1) / 2;
              replace(start, (*itr).first);
              cout << a;
              b = true;
              break;
          }
      }

     } while(b) ;
          
     
}

int main()
{

    cin >> a;
    
    SimplifyAll('^');
    Simplify('/');
    //Prioritize("*/");
    
    cout << 1;
}
