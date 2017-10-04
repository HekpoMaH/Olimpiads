#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;
string code,message;
string a[1005];
int n,k,codesize,br;
int main()
{
    ios::sync_with_stdio(false);
    cin>>code;
    codesize=code.size();
    n=(int)sqrt(codesize);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i]+=code[br];
            br++;
            if(code[br]>='0'&&code[br]<='9')k+=code[br]-'0';
        }
    }
    k%=n;
    int i=k,j=0;
    while(1)
    {
        if(a[i][j]>='A'&&a[i][j]<='Z')message+=a[i][j];
        else break;
        i++;j++;
        if(i==n&&j==n){i=0;j=0;}
        else if(i>=n){i=0;j--;}
        else if(j>=n){j=0;}
    }
    cout<<message<<endl;
    return 0;
}
//RNLAJDSRGT5EO8OTHIKOLWOEKIMF!MOIL2A!