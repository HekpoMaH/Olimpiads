#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<string>
#define ll long long

using namespace std;

    int n;
    char s[1000];

    set<string> used;

    string tmp;

int main()
{
    scanf("%s", s);
    n = (int)strlen(s);

    int ans = 0;

    for( int i = 1; i < (1<<n); ++i )
    {
     int j = i;

     tmp = "";
     for( int q = 0; q < n; ++q )
      if( (1<<q) & j )
      {
       tmp += s[q];
      }

     if( used.find(tmp) == used.end() )
     {
      used.insert(tmp);
      //cout<<tmp<<"\n";
      ans++;
     }
    }

    printf("%d\n",ans);
return 0;
}
