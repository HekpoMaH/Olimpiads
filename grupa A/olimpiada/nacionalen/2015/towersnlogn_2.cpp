#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int a[1000009],br=1,q;
int b[1000009];
int ans[1000009];
vector <int> v[1000009];
stack <int> st;
bool used[1000009];
void dfs(int x)
{
   q++;
   int sz=v[x].size();
   for(int i=0;i<sz;i++)
   {
      if(used[v[x][i]]==0)
      {
         used[v[x][i]]=1;
         dfs(v[x][i]);
      }
   }
   ans[x]=br;
   br++;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,x;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      b[i]=a[i];
      //if(l==0&&a[i]!=0)l=i;
   }
  // int br=1;
   for(int i=n;i>=1;i--)
   {
      if(!st.empty())
      {
         x=st.top();
         if(b[x]==1)
         {
            st.pop();
           // ans[x]=br;
            //br++;
         }
         b[x]--;
         v[x].push_back(i);
        // v[i].push_back(x);

         if(b[i]>0)st.push(i);


         //if(a[i]!=0)st.push(i);
      }
     /* else if(a[i]==0)
      {
         ans[i]=br;
         br++;
      }*/
      else if(st.empty()&&a[i]>0)
      {
         st.push(i);
      }
      /*else
      {

         ans[i]=a[i]+br;
         for(int j=i-1;j>=i-a[i];j--)
         {
            ans[j]=br;
            br++;
         }
         i-=a[i];
         br++;*/
     // }
   }
   for(int i=n;i>=1;i--)
   {
      if(a[i]==0&&used[i]==0)
      {
         ans[i]=br;
         br++;
      }
      else if(used[i]==0)
      {
         used[i]=1;
         q=1;
         dfs(i);
      }
   }
   for(int i=1;i<=n;i++)
   {
      cout<<ans[i]<<'\n';
   }
   /*ans[i]=n;
   used[n]=1;
   int l=0,r=0;
   for(int i=l+1;i<=n;i++)
   {
      if(a[i]!=0)
      {
         r=i;
      }
   }*/

   return 0;
}
