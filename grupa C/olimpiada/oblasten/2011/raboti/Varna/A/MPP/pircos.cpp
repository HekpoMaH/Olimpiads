/*
TASK: pircos
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int n,x;
set<int> s;
set<int> :: iterator it;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(s.find(x) != s.end()) s.erase(x);
        else s.insert(x);
    }

    it = s.begin();
    x = *it;

    printf("%d ",x);

    s.erase(x);

    it = s.begin();
    x = *it;

    printf("%d\n",x);

    return 0;
}
