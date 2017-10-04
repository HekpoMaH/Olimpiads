#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,a[512][512]={0};
    int **b=new int*[512];
    for(int i=0;i<512;i++){b[i]=new int[512];
    for(int j=0;j<512;j++){a[i][j]=0; b[i][j]=0;}}
    cin >> n;
    for(int i=0;i<n;i++){
            int l,p,q,r;
            cin >> l >> p >> q >> r;
            for(int j=l;j<q;j++){
                    a[j][p]=1;
                    a[j][r]=1;
                    }
            for(int j=p;j<r;j++){
                    b[l][j]=1;
                    b[q][j]=1;
                    }
            }
    int br=0;
    for(int i=0;i<512;i++)
    for(int j=0;j<512;j++) br+=a[i][j]+b[i][j];
    cout << br << endl;
    return 0;
}
