#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
struct stepen
{
    int num,st;
};
int n,s,ans;
vector<stepen>v,v1;
void readInput()
{
    scanf("%d%d",&s,&n);
}
void solve()
{
    int i;
    while(s>n) {
        if(s%n!=0) {
            ans+=2;
            s/=n;
        }
        else {
            ans++;
            s/=n;
        }
    }
    if(s>1) ans++;
}
int main()
{
    readInput();
    if(n==1) {
        printf("%d\n",s);
        return 0;
    }
    if(s==n) {
        printf("1\n");\
        return 0;
    }
    if(s-n<=n) {
        printf("2\n");
        return 0;
    }
    if(s/n<=n&&s%n==0) {
        printf("2\n");
        return 0;
    }
    solve();
    printf("%d\n",ans);
    return 0;
}
