#include<iostream>
using namespace std;

int count_num[11];
int diff_num[11];

int check_diff ()
{
    int i;
    for (i=1;i<=10;i++) if(diff_num[i]>1) return 0;
    for (i=1;i<=10;i++) diff_num[i]=0;
    return 1;
}

int main ()
{
    int num, i, j;
    for (i=1; i<=30; i++)
    {
        for (j=1; j<=6; j++)
        {
            cin >> num;
            if (num<1 || num>10 )
            {
                cout <<"Out of range - Wrong Answer"<< endl;
                return 0;
            }
            diff_num[num]++;
            count_num[num]++;
        }
        if ( check_diff()==0 )
        {
            cout <<"Not different numbers - Wrong Answer"<<endl;
            cout <<i<<endl;
            return 0;
        }
    }
    for(i=1;i<=10;i++)
    if(count_num[i]!=18)
    {
        cout <<"Different by 18 - Wrong Answer"<<endl;
        return 0;
    }
    cout <<"Accepted"<<endl;
    return 0;
}


