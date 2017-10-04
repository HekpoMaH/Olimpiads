#include <iostream>
using namespace std;
    int n,i,br1,br2,br3,br4,z,j,d,brp;
int main () {
    char a;
    string s[10001][5];
    cin>>n>>a;
                                                                                                                     																																																														                                                                                                                                                                                 for (i=1;i<=n;i++){
        cin>>s[i][1];
        cin>>s[i][2];
        cin>>s[i][3];
        cin>>s[i][4];
    }
    for (i=1;i<=n;i++){
        if (s[i][1][0]==a || s[i][1][0]==a-32){
           br1++;
        }
    }
    for (i=1;i<=n;i++){
        d=s[i][2].size();
        for (j=0; j<=d-1; j++){
            if (s[i][2][j]==a || s[i][2][j]==a-32){
               br2++;
               break;
            }
        }
    }
    for (i=1;i<=n;i++){
        d=s[i][3].size();
        brp=0;
        for (j=0; j<=d-1; j++){
            if (s[i][3][j]==a || s[i][3][j]==a-32){
               brp++;
            }
            if (brp==2){
               br3++;
               break;
            }
        }
    }
    for (i=1;i<=n;i++){
        d=s[i][4].size();
        if (s[i][4][d-1]==a || s[i][4][d-1]==a-32){
           br4++;
        }
    }
    cout<<br1<<" "<<br2<<" "<<br3<<" "<<br4<<endl;
return 0;    
}
/*
3 a
Ani Miraj Masa Bala
Taralej toto Dani Kana
ananas pile ananas tapa
2 1 2 3


1 b
Baba Baba Baba Baobab
1 1 1 1
*/
