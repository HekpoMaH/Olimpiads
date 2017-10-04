#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Vryh {
  int nom;
  int st;
  bool fl;
  int pred;
};
Vryh vv;
vector<Vryh> v,vH;
int V1,V2,P,N,s;

/*
 *        (1)---3--(2)
 *      / |  \     |  \
 *    1   1    4   1   2
 *   /    |      \ |    \
 * (0)-3-(4)--1---(3)--2-(7)
 *   \    |        |     /
 *     7  4        1   1
 *      \ |        |  /
 *       (5)--2---(6)
*/
// Матрица на съседство
//----------------------------------------
//             1 2 3 4 5 6 7 8
int a [9][9]={{0,1,0,0,3,7,0,0},   //  1
              {1,0,3,4,1,0,0,0},   //  2
              {0,3,0,1,0,0,0,2},   //  3
              {0,4,1,0,1,0,1,2},   //  4
              {3,1,0,1,0,4,0,0},   //  5
              {7,0,0,0,4,0,2,0},   //  6
              {0,0,0,1,0,2,0,1},   //  7
              {0,0,2,2,0,0,1,0}};  //  8
//----------------------------------------
//
void Pechat() {
    cout <<"Graph:"<<endl;
    cout << endl;
    cout<<"        (1)--3---(2)"<<endl;
    cout<<"      / |  \\     |  \\"<<endl;
    cout<<"    1   1    4   1   2"<<endl;
    cout<<"   /    |      \\ |     \\"<<endl;
    cout<<" (0)-3-(4)--1---(3)--2-(7)"<<endl;
    cout<<"   \\    |        |    /"<<endl;
    cout<<"    7   4        1   1"<<endl;
    cout<<"      \\ |        | /"<<endl;
    cout<<"       (5)---2--(6)"<<endl;
    cout<<"\n\n";
}
//
void Pec () {
  for (unsigned i=0; i<v.size(); i++) {cout << v[i].nom<< " " << v[i].st; cout << endl; }
}

int fff (Vryh v1, Vryh v2) {
   if (v1.st>v2.st) return 1;
   else
   return 0;
}
void minp(int v1,int v2,vector<Vryh> &v)
{
// Добавя останалите върхове
  v.clear();
  for (int i=0; i<N; i++)
   if (i!=V1)
   {
     vv.nom=i; vv.st=10000; vv.fl=false;vv.pred=0;
     v.push_back(vv);
   }
   else
   {
     vv.nom=V1; vv.st=0; vv.fl=false;vv.pred=-1;
     v.push_back(vv);
   }
  vv.nom=V1; vv.st=0;
  vH.clear();
  vH.push_back(vv);
  make_heap (vH.begin(),vH.end(),fff);

  while (!vH.empty())
  {
    vv=vH.front();
    pop_heap(vH.begin(), vH.end(), fff);
    vH.pop_back();
    if (v[vv.nom].fl)	continue;
    v[vv.nom].fl=true;

    for (int i=0;i<N;i++)
     if (i!=vv.nom)
      if (!v[i].fl)
       if (a[i][vv.nom]>0)
        if (v[i].st>vv.st+a[i][vv.nom])
        {
          v[i].st=vv.st+a[i][vv.nom];
          v[i].pred=vv.nom;
          vH.push_back(v[i]);//cout<<"a"<<a[i][vv.nom]<<endl;system("pause");
          push_heap(vH.begin(),vH.end(),fff);
        }
//    Pec ();
//    cout<<endl;
  }
}
void delr(vector<Vryh> &v)
{
  int k1=999,k2,mn=10005;
  k2=V2;
  while(k1!=V1)
  {
    k1=v[k2].pred;
    if(mn>a[k1][k2]&&a[k1][k2]>0)mn=a[k1][k2];
    k2=k1;
  }
  if(mn=10005)return;
  s+=mn;
  k2=V2;
  k1=999;
  while(k1!=V1)
  {
    k1=v[k2].pred;
    cout<<"a="<<a[k2][k1]<<" "<<mn<<endl;


    a[k1][k2]-=mn;
    a[k2][k1]=a[k1][k2];cout<<"a="<<a[k2][k1]<<" "<<mn<<endl;
    system("pause");
    //cout<<k1<<"=k  "<<k2<<"=k2"<<endl;
    k2=k1;
    cout<<a[k1][k2]<<endl;
  }
}
int main () {
  int i;
  N=8;
  Pechat();
  cout<<"V1="; cin>>V1;
  cout<<"V2="; cin>>V2;
  cout<<endl;
  do
  {
   //cout<<v[V2].st<<"=st"<<endl;
   //system("pause");
    minp(V1,V2,v);
    delr(v);
    cout<<v[V2].st<<"=st"<<endl;
  }while(v[V2].st!=10000);
  cout<<s<<endl;
  //system ("pause");
  return 0;
}
