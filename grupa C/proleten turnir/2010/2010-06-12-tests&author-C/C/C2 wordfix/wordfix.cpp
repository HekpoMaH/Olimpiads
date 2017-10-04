#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#define mp make_pair

using namespace std;

    char s1[1000002];
    char s2[1000002];

    vector <int> G[500];
    int pos[500];
    
int main()
{
    int N;
    long long ans = 0;

    scanf("%s %s",s1,s2); N = (int)strlen(s1);
    
    for(int i = 0; i < N; ++i)
    {
     G[(int)s2[i]].push_back(i);
    }    

    for(int i = 0; i < N; ++i)
    {
     if(i > G[(int)s1[i]][pos[(int)s1[i]]])ans += i - G[(int)s1[i]][pos[(int)s1[i]]];
     pos[(int)s1[i]]++;
    }
    printf("%lld\n",ans);
return 0;
}
