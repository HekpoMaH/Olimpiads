#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n,k,a[505][505],path[505][505],used[505],br=0;
queue <int> st;
void dfs(int vrah,int pos)
{

  used[vrah]=1;
  //cout<<vrah<<endl;
  if(vrah==pos)
  {//cout<<br<<endl;
    do
    {
      //cout<<st.front()<<" ";
      if(st.front()!=1)path[br][0]++;
      if(st.front()!=1)path[br][path[br][0]]=st.front();
      st.pop();
    }while(!st.empty());//cout<<endl;
    for(int i=1;i<=path[br][0];i++){st.push(path[br][i]);}//cout<<endl;
    //cout<<endl;
    br++;//cout<<"A"<<endl;
  }
  //cout<<vrah<<" "<<a[vrah][0]<<endl;
  for(int i=1;i<=a[vrah][0];i++)
  {
    //cout<<used[a[vrah][i]]<<" ";
    if(used[a[vrah][i]]==0)
    {
      st.push(vrah);
      //cout<<vrah<<" "<<a[vrah][i]<<endl;
      dfs(a[vrah][i],pos);
      if(!st.empty())st.pop();
      used[a[vrah][i]]=0;//cout<<st.front()<<endl;

    }
  }
  //cout<<endl;
  //cout<<"aaa"<<endl;
}
void input()
{
  cin>>k>>n;
  br=0;
  for(int i=0;i<=n;i++)
  {
    used[i]=0;a[i][0]=0;
  }
  string s;
  int num,e;
  for(int i=0;i<=n;i++)
  {
    //cout<<i<<endl;
    getline(cin,s);
    e=s.size();
    num=0;
    for(int j=0;j<e;j++)
    {
      if(s[j]>='0'&&s[j]<='9')
      {
        num=num*10+s[j]-'0';
      }
      if(s[j]==' '||j==e-1)
      {
        a[i][0]++;//cout<<num<<endl;
        a[i][a[i][0]]=num;
        //a[num][a[num][0]]=i;
        num=0;
      }
    }
  }

  /*for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=a[i][0];j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }*/
  //for(int i=1;i<=n;i++)cout<<a[i][0]<<" ";
  //cout<<endl;
}

int main()
{
  input();
  for(int i=0;i<=n;i++)path[i][0]=0;
  dfs(1,2);
  if(br<k)cout<<"Impossible"<<endl;
  else
  for(int i=0;i<br;i++)
  {
    cout<<1<<" ";
    for(int j=1;j<=path[i][0];j++)
    {
      cout<<path[i][j]<<" ";
    }
    cout<<2;
    cout<<endl;
  }

  //cout<<br<<endl;
  return 0;
}
