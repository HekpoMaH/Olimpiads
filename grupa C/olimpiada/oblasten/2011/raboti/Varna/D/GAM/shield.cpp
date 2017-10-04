#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int n,i;

struct fences
{
    int wallz[128];
    int lowest;
    int difference[128];
};

int main()
{
    fences fence[2];
    cin>>n;
    for(i=0;i<n;i++) cin>>fence[0].wallz[i];
    fence[0].lowest=fence[1].lowest=400;
    for(i=0;i<n;i++)
    {
        cin>>fence[1].wallz[i];
        fence[0].difference[i]=fence[0].wallz[i]+fence[1].wallz[i];
        fence[1].difference[i]=fence[0].wallz[(n-i)-1]+fence[1].wallz[i];
        if(fence[0].difference[i]<fence[0].lowest) fence[0].lowest=fence[0].difference[i];
        if(fence[1].difference[i]<fence[1].lowest) fence[1].lowest=fence[1].difference[i];
    }
    if(fence[0].lowest>=fence[1].lowest)
    cout<<fence[0].lowest<<endl;
    else cout<<fence[1].lowest<<endl;
    return 0;
}
