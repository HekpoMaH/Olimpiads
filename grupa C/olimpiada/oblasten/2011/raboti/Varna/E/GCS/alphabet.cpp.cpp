# include<iostream>
using namespace std;
int m, n, brr;
char c, brb, buk;
int main()
{
cin>>n>>m;

   for(buk='A'; buk<='Z'; buk++)
   {
      for(int a=1; a<=n; a++)
      {
          if(a==n) break;
      }
   }
for(int i=1; i<=m; i++)
{
    for(; ;)
    {
      cin>>c;
      if(c=='.') {brr++; break;}
      if(c==buk) {cout<<"mod "<<brr<<endl; break;}
      else cout<<"lose"<<endl;
    }

}

return 0;
}
