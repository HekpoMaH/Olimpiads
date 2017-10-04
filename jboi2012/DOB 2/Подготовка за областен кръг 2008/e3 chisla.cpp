//e3 chisla
#include<iostream>
using namespace std;
int main()
{
    char ch;
    int l,br=0;
    while(ch!='.')
    {
                  cin.get(ch);
                  if(ch>='0' && ch<='9' && l!=1){l=1;}
                  if((ch<'0' || ch>'9')&& l==1){
                                                l=0;
                                                br++;
                                                }
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
                  
