#include<iostream>
#include<vector>
using namespace std;
struct cube
{
    int fron,back,up,down,left,right;
    cube(int f=0,int b=0,int u=0,int f=0,int l=0,int r=0)
    {
        front=f;back=b;u=up;f=front;
        l=left;r=right;
    }
    cube north()
    {
        return cube(down,up,front,back,left,right);
    }
    cube south()
    {
        return cube(up,down,back,front,left,right);
    }
    cube east()
    {
        return cube(front,back,left,right,down,up);
    }
    cube west()
    {
        return cube(front,back,right,left,up,down);
    }
};
int d[8][8][24]; 
int main()
{
    
}