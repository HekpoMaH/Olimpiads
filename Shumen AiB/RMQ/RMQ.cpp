#include<iostream>
#include<cstring>
using namespace std;
int m[100][100];
int n;
int a[100];
void precompute()
{
    for(int i=0;i<n;i++)
    m[i][0]=i;
    //cout<<(1<<1)<<" "<<(1<<2)<<" "<<(1<<3)<<endl;
    for(int j=1;1<<j <=n;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            //cout<<(1<<(j-1))<<endl;
            if(a[m[i][j-1]]<a[m[i+(1<<(j-1))][j-1]])m[i][j]=m[i][j-1];
            else m[i][j]=m[i+(1<<(j-1))][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;1<<j <n;j++)
        cout<<m[i][j]<<" ";
        cout<<endl;
    }
}
int findlg(int number)
{
    if(number==1)return 0;
    int br=0;
    do
    {
        br++;
    }while((1<<(br))<number);
    if(1<<br>number)br--;
    return br;
}
int qu;
int l,r;
int main()
{
    cin>>n;
    //memset(m,31,sizeof(m));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    precompute();
    cin>>qu;
    for(int i=0;i<qu;i++)
    {
        cin>>l>>r;
        int lg=findlg(r-l+1);//lg--;
        //if(l==r)lg=0;
        //cout<<"m["<<l<<"]["<<lg<<"]="<<m[l][lg]<<endl;
        //cout<<"m["<<r-(1<<lg)+1<<"]["<<lg<<"]="<<m[r-(1<<lg)+1][lg]<<endl;
        //cout<<lg<<" "<<r-(1<<lg)+1<<" "<<m[l][lg]<<" "<<m[r-(1<<lg)][lg]<<endl;
        if(a[m[l][lg]]<=a[m[r-(1<<lg)+1][lg]])cout<<m[l][lg]<<endl;
        else cout<<m[r-(1<<lg)+1][lg]<<endl;
    }
}
