#include <stdio.h>
int N,K, ar[1048575]={0};
int used[1 << 20];

int main(int argc, char *argv[])
{
 int i;
 FILE * fi;
 FILE * fa;

 fi = fopen(argv[1], "r");	// input file
 if (fi == NULL)
 {
	printf("0\nCannot open input.\n");
	return 0;
 }
 fa = fopen(argv[2], "r");	//answer file
 if (fa == NULL)
 {
  printf("0\n%s\n no competitor_answer_file\n", argv[2]);
  return 0;
 }
   fscanf(fi,"%d %d",&N,&K);
   int ttN=1<<N,num; // 2^N
   used[K] = 1;
   //ar[K]=1;
   if(fscanf(fa,"%d",&num)<0)
   {printf("0\nno competitor 1st value\n");return 1;};
   if(num!=ttN-1)
   {printf("0\n competitor 1st value wrong\n");return 1;};


   for(int i=1;i<ttN;i++)
   {
      if(fscanf(fa,"%d",&num)<0)
      {printf("0\nno enough values\n");return 1;};
      K += num;
      /*K=K+num;
      if(K<0||K>ttN-1)
      {printf("0\nnot correct value\n");return 1;};
      if(ar[K]!=0)
      {printf("0\nrepeated value %d in line %d\n",K,i);return 1;};
      ar[K]=1;*/
      if(num<0) num= -num;
      if ( K < 0 || K >= ttN ){
        printf ( "0\nOut of boundaries\n" );
        return 1;
      }
      if(num<1||num>ttN-1)
      {printf("0\nnot correct value\n");return 1;};
      if ( used[K] ){
        printf ( "0\nalready visited\n" ); return 1; }
      if(ar[num]!=0)
      {printf("0\nrepeated value %d in line %d\n",num,i);return 1;};
      ar[num] = 1;
      used[K] = 1;
}
   sscanf( argv[4], "%d", &i );
   printf("%d\nAccepted!\n", i);
   return 0;
}
