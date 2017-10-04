#include<iostream>
#include<vector>
#include<string>
using namespace std;
long a,b,c,d,e,f,i,j,n,br1,br2;
vector<string> z;
string k;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
             cin>>k;
             br1=0;
             br2=0;
             for(j=0; j<=k.size()-1; j++)
             {
                      if(k[j]=='C'||k[j]=='A'||k[j]=='T') {br1++;}
                      if(k[j]=='G'||k[j]=='P'||k[j]=='I') {br2++;}
             }
             if(br1>br2) {z.push_back("CAT");}
             else if(br1<br2) {z.push_back("GPI");}
             else if(br1==br2&&br1!=0) {z.push_back("CAT-GPI");}
             else if(br1==0&&br2==0) {z.push_back("UFO");}
    }
    for(i=0; i<=n-1; i++)
    {
             cout<<z[i]<<endl;
    }
    return 0;
}
