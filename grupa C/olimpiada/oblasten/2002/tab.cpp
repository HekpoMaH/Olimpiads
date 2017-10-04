#include<iostream>
using namespace std;
long long t4,br,brk,n,k,used[2000][2000];
int main()
{
    cin>>n>>k;
    int i=0,j=0,ipr=-1,jpr=-1;
    while(!(br>n*n))
    {
        used[i][j]=1;
        t4++;
        //cout<<t4<<endl;
        if(t4==k){cout<<i+1<<" "<<j+1<<endl;return 0;}
        br++;
        if(brk%4==0)
        {
            j++;
            if(j==n||used[i][j]==1){j--;brk++;}
        }
        if(brk%4==1)
        {
            i++;
            if(i==n||used[i][j]==1){i--;brk++;}
        }
        if(brk%4==2)
        {
            j--;
            if(j==-1||used[i][j]==1){j++;brk++;}
        }
        if(brk%4==3)
        {
            i--;
            if(i==-1||used[i][j]==1){i++;brk++;}
        }
        if(ipr==i&&jpr==j)t4--;
        ipr=i;jpr=j;
        //cout<<t4<<" "<<i<<" "<<j<<endl;
    }
    cout<<n*n<<endl;
    return 0;
}
