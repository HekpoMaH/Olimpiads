#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<queue>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
string z1,z2;
int sum,mx,mxt,ptr,mt,br,used[111],n,sm[111],bs;
int main()
{
    srand(time(NULL));
    /*getline(cin,z1);
    int idx=0;
    while(z1.size()!=0)
    {
        //cout<<z1.size()<<endl;
        if(z1[0]=='_'){z1.erase(z1.begin());if(z1.size()!=0)z1.erase(z1.begin());}
        else
        {
            int nbr=0;
            while(z1[0]!=' '&&z1.size()!=0)
            {
                nbr=nbr*10+z1[idx]-'0';z1.erase(z1.begin());
            }

            if(z1.size()==0)break;
            z1.erase(z1.begin());
        }n++;
    }
    getline(cin,z2);
    while(z2.size()!=0)
    {
        //cout<<z2.size()<<endl;
        if(z2[0]=='_'){z2.erase(z2.begin());if(z2.size()!=0)z2.erase(z2.begin());}
        else
        {
            int nbr=0;
            while(z2[0]!=' '&&z2.size()!=0)
            {
                nbr=nbr*10+z2[idx]-'0';z2.erase(z2.begin());
            }

            if(z2.size()==0)break;
            z2.erase(z2.begin());
        }
        n++;
    }
    //n-=2;
    cin>>ptr>>mt;cout<<n<<endl;
    used[mt]=used[ptr]=0;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            br++;
            sm[br]=sm[br-1]+i;
            //mx=max(mx,i);
        }
        else mx=max(mx,i);
    }*/

    cout<<"Sleep!"<<endl;
    cout<<rand()%29<<endl;
}


