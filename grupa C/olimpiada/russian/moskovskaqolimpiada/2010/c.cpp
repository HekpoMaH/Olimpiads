#include<iostream>
#include<algorithm>
using namespace std;
struct bottle
{
    int tochki,pos;
};
bool cmp(bottle a,bottle b)
{
    if(a.tochki<b.tochki)return true;
    return false;
}
bottle poqs[1004],sand[1004];
int m,n,op[100005][2];
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++){cin>>poqs[i].tochki;poqs[i].pos=i;}
    for(int i=0;i<n;i++){cin>>sand[i].tochki;sand[i].pos=i;}
    sort(poqs,poqs+m,cmp);
    sort(sand,sand+n,cmp);
    //cout<<sand[0].tochki<<endl;
    int i=0,j=n-1,br=0;
    while(i<m&&j>=0)
    {
        if(poqs[i].tochki<sand[j].tochki)
        {
            op[br][0]=poqs[i].pos;op[br][1]=sand[j].pos;
            swap(poqs[i].tochki,sand[j].tochki);
            br++;
            //cout<<poqs[i].tochki<<" "<<sand[j].tochki<<endl;
        }
        else break;
        i++;j--;
    }
    cout<<br<<endl;
    for(int i=0;i<br;i++)cout<<op[i][0]+1<<" "<<op[i][1]+1<<endl;
    return 0;
}
