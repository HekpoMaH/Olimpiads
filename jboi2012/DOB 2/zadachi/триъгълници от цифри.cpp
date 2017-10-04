#include<iostream>
using namespace std;
int main()
{
    for(int br=1;br<=7;br++)
    {
            for(int ch=1;ch<br;ch++)
            {
                                 cout<<" ";
            }
            for(int i=br;i<=7;i++)
            {
                    cout<<i;
            }
            cout<<endl;
    }
    system("pause");
    return 0;
}
