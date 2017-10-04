#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int count;
    char find;
    bool stop=false;
    cin>>count>>find;
    char in[4][1024];
    short out1=0,out2=0,out3=0,out4=0;
    for(short i=0;i<count;i++)
    {
        //kolonka 1
        cin>>in[0];
        if(in[0][0]==find or in[0][0]==find+'A'-'a') {out1++;}

        //kolonka 2
        cin>>in[1];
        for(short j=0;j<strlen(in[1]);j++)
        {
            if(in[1][j]==find or in[1][j]==find+'A'-'a') {out2++; break;}
        }

        //kolonka 3
        cin>>in[2];
        for(short j=0;j<strlen(in[2]);j++)
        {
            if(in[2][j]==find or in[2][j]==find+'A'-'a')
            {
                for(short t=j+1;t<strlen(in[2]);t++)
                {
                    if(in[2][t]==find or in[2][t]==find+'A'-'a'){out3++;stop=true;break;}
                }
            }
            if(stop) {break;}
        }

        //kolonka 4
        cin>>in[3];
        if(in[3][strlen(in[3])-1]==find or in[3][strlen(in[3])-1]==find+'A'-'a') {out4++;}
    }
    cout<<out1<<' '<<out2<<' '<<out3<<' '<<out4<<'\n';
    return 0;
}
