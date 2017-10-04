#include<iostream>
#include<queue>

using namespace std;

int level[1000000];
int a, b, c;
int s, s3;

void bfs(int u)  
{    queue<int> q;
     int p, p1, p2, p3, v;
     level[u] = 1;
     q.push(u);   
     do
       {  p = q.front();
          q.pop();
          p1 = p/10000;
          p2 = (p%10000)/100;
          p3 = p%100;
          if (p1 <= p2) 
            { v = 20000*p1 + 100*(p2-p1) + p3;
              if (level[v] == 0)
                { level[v] = level[p]+1;         
                  q.push(v);
                }
            }  
          if (p1 >= p2) 
            { v = 10000*(p1-p2) + 200*p2 + p3;
              if (level[v] == 0)
                { level[v] = level[p]+1;            
                  q.push(v);
                }
            }
          if (p1 <= p3) 
            { v = 20000*p1 + 100*p2 + p3-p1;
              if (level[v] == 0)
                { level[v] = level[p]+1;              
                  q.push(v);
                } 
            }
          if (p1 >= p3) 
            { v = 10000*(p1-p3) + 100*p2 + 2*p3;
              if (level[v] == 0)
                { level[v] = level[p]+1;            
                  q.push(v);
                } 
            }        
          if (p2 <= p3) 
            { v = 10000*p1 + 200*p2 + p3-p2;
              if (level[v] == 0)
                { level[v] = level[p]+1;             
                  q.push(v);
                } 
            }
          if (p2 >= p3) 
            { v = 10000*p1 + 100*(p2-p3) + 2*p3;
              if (level[v] == 0)
                { level[v] = level[p]+1;              
                  q.push(v);
                } 
            }               
        } while (q.size() > 0 && level[s3] == 0);
} 
  
int main()
{    cin >> a >> b >> c;  
     s = 10000*a + 100*b +c;
     s3 = a+b+c;
     bfs(s);
     cout << level[s3]-1 << endl;  
     return 0;
}
