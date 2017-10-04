#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char a[30];
int m,n;
cin>>m>>n;
for (int i=0; i<=m*n; i++)
{
    cin.getline(a, n+1);
}
system("pause");
return 0;

}
