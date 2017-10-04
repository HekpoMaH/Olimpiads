///PROGRAM NAME: Triangles
///AUTHOR: Mladen Manev

#include<iostream>
#include<algorithm>
using namespace std;

struct Point
{ 
    int x, y; 
};

int direction(Point A, Point B, Point C)
{   
    int a1=B.x-A.x, a2=B.y-A.y;
    int b1=C.x-A.x, b2=C.y-A.y;
    int p=a1*b2, q=a2*b1;
    if(p>q) return +1;
    if(p<q) return -1;
    return 0;
}

bool onSegment(Point A, Point B, Point C)
{   return min(A.x,B.x)<=C.x && C.x<=max(A.x,B.x) &&
           min(A.y,B.y)<=C.y && C.y<=max(A.y,B.y);
}

bool intersectSegments(Point A, Point B, Point C, Point D)
{   int d1 = direction(A,B,C);
    int d2 = direction(A,B,D);
    int d3 = direction(C,D,A);
    int d4 = direction(C,D,B);
    if (d1*d2<0 && d3*d4<0) return true;
    if (d1==0 && onSegment(A,B,C)) return true;
    if (d2==0 && onSegment(A,B,D)) return true;
    if (d3==0 && onSegment(C,D,A)) return true;
    if (d4==0 && onSegment(C,D,B)) return true;
    return false;
}

bool onTriangle(Point A, Point B, Point C, Point M)
{
    int d1 = direction(A,B,M);
    int d2 = direction(B,C,M);
    int d3 = direction(C,A,M);
    if (d1>=0 && d2>=0 && d3>=0) return true;
    if (d1<=0 && d2<=0 && d3<=0) return true;
    return false;
}

bool intersectTriangles(Point A, Point B, Point C, Point P, Point Q, Point R)
{
    if (onTriangle(A,B,C,P) || onTriangle(A,B,C,Q) || onTriangle(A,B,C,R)) return true;
    if (onTriangle(P,Q,R,A) || onTriangle(P,Q,R,B) || onTriangle(P,Q,R,C)) return true;
    if (intersectSegments(A,B,P,Q) || intersectSegments(A,B,P,R) || intersectSegments(A,B,Q,R)) return true;
    if (intersectSegments(B,C,P,Q) || intersectSegments(B,C,P,R) || intersectSegments(B,C,Q,R)) return true;
    if (intersectSegments(C,A,P,Q) || intersectSegments(C,A,P,R) || intersectSegments(C,A,Q,R)) return true;
    return false;
}

int main()
{ 
    Point A, B, C, P[4], Q[4], R[4];
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    for(int i=0; i<4; i++)
        cin >> P[i].x >> P[i].y >> Q[i].x >> Q[i].y >> R[i].x >> R[i].y;
    for(int i=0; i<4; i++)
        cout << intersectTriangles(A,B,C,P[i],Q[i],R[i]);
    cout << endl;
    return 0;
}
