#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int min_val = 9999999;
char str[32];
void calc(char s1[32], int num_done, int total)
{
  if(num_done == total)
  {
    int k = s1[0] - '0';
    if(k < min_val) min_val = k;
    return;
  }
  for(int i = 0; i < total - num_done; ++i)
  {
    if(num_done == 0) strcpy(s1, str);
    int v = s1[i*2]-'0';
    if(s1[i*2+1] == '+') v += s1[i*2+2] - '0';
    if(s1[i*2+1] == '-') v -= s1[i*2+2] - '0';
    if(s1[i*2+1] == '*') v *= s1[i*2+2] - '0';
    char s2[32];
    strncpy(s2, s1, i*2);
    s2[i*2] = (char) v + '0';
    strcpy(s2+i*2+1, s1+i*2+3);
    calc(s2, num_done+1, total);
  }
}
int main()
{
  scanf("%s", str);
  int l = strlen(str);
  calc(str, 0, (l-1)/2);
  printf("%d\n", min_val);
  return 0;
}
