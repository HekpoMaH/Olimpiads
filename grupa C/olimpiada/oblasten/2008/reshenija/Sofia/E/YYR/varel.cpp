     #include<iostream>
     using namespace std;
     int main()
     {
      int V,K,N,j;
      char ch;                                                                                                                                                                                                                                                                      
      cin>>V;
      
      cin>>K;
      cin>>N;
      
      for(j=1;j<=N;j++)
      {
      ch=cin.get();
      do
      {
      cin>>ch;
      if(ch=='+')V=V+K;
      if(ch=='-')V=V-K;
      }
      while((ch!='+')&&(ch!='-'));
      }
      cout<<V<<endl;
      system("pause");
      return 0;
      }                         
