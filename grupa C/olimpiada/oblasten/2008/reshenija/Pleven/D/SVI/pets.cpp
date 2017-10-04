#include<iostream>
#include<string>
using namespace std;
int main()
{
    long n,m,i,j,br1=0,br2=0; 
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
                     cin>>s;
                     m=s.size();
                     for(j=0;j<=m-1;j++)
                     {
                                        if (s[j]=='C' || s[j]=='A' || s[j]=='T') {br1++;}
                                        if (s[j]=='G' || s[j]=='P' || s[j]=='I') {br2++;}
                     }
                     if (br1>br2) {cout<<"CAT"<<endl;}
                     if (br1<br2) {cout<<"GPI"<<endl;}
                     if (br1==br2 && br1==0) {cout<<"UFO"<<endl;}
                     if (br1==br2 && br1!=0) {cout<<"CAT-GPI"<<endl;}
                     br1=0;
                     br2=0;
    }
//    system("pause");
    return 0;
}
                     
