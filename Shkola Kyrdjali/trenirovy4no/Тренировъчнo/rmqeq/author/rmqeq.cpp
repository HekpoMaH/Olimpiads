#include <stdio.h>
#include <stack>
#include <climits>

using namespace std;

int n;
int p[1000001];
int L[1000001];
int L1;

void Lbuild()
{
  stack<int> st;
  int i;
  
  st.push( INT_MIN );
  
  for ( i = 1; i <= n; i++ )
  {
    L[i]=0;  
    while ( st.top() > p[i] )
    {
      st.pop();
      L[i]++;      
    }
    st.push( p[i] );
  }
}

bool compare()
{
  stack<int> st;
  int pe;
  bool indeq;
  int i;
  
  st.push( INT_MIN );
  indeq = true;
  for ( i = 1; i <= n; i++ )
  {
    scanf("%d",&pe);  
    L1=0;  
    while (( st.top() > pe ) && (indeq))
    {
      st.pop();
      L1++;
    }
    st.push( pe );
    if (L1 != L[i])
      indeq = false;
  }
  return indeq;
}        

int main()
{
  int i;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&p[i]);  
  Lbuild();
  if (compare())
    printf("YES\n");
  else
    printf("NO\n");  
  return 0;  
}
