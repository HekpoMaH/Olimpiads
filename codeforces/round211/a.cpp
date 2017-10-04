#include<bits/stdc++.h>
using namespace std;
string dog,ig;
int n;
int main()
{
    cin>>n;
    if(n==0)cout<<"O-|-OOOO"<<endl;
    while(n!=0)
    {
        dog="";ig="";
        if(n%10>=5)
        {
            dog="-O";
            int br=0;
            for(int i=1;i<=n%10-5;i++)
            {
                ig+="O";br++;
            }
            ig+="-";
            for(int i=1;i<=4-br;i++)ig+="O";
        }
        else
        {
            dog="O-";
            int br=0;
            for(int i=1;i<=n%10;i++)
            {
                ig+="O";br++;
            }
            ig+="-";
            for(int i=1;i<=4-br;i++)ig+="O";
        }
        cout<<dog<<"|"<<ig<<endl;
        n/=10;
    }
}
