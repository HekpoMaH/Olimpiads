#include <iostream>
using namespace std;
int a[6];
int b[14];
int c[6];
   bool Straight()
   {
       int i;
       for(i=1;i<=13;i++)
       if(b[i]!=0)
       if ((b[i]==1)&&(b[i+1]==1)&&(b[i+2]==1)&&(b[i+3]==1)&&(b[i+4]==1))
       return 1;
       return 0;

   }
   int main()
   {
       for(int i=1;i<=5;i++)
       cin>>a[i];
       for(int i=1;i<=5;i++) b[a[i]]++;
       for(int i=1;i<=13;i++) c[b[i]]++;
       if (c[5]==1) cout<<"Impossible";
        else if (c[4]==1) cout<<"Four of a Kind";
        else if ((c[3]==1)&&(c[2]==1)) cout<<"Full House";
        else if (c[3]==1) cout<<"Three of a Kind";
        else if (c[2]==2) cout<<"Two Pairs";
        else if (c[2]==1) cout<<"One Pair";
        else if (Straight()) cout<<"Straight";
        else cout<<"Nothing";
   }
