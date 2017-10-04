#include<stdio.h>
#include<math.h>

#define EPSILON 0.01

int main(int argc, char * argv[])
{   FILE * out = fopen(argv[3],"r");
    FILE * sol = fopen(argv[2],"r");

    double lout,lsol;
    int o, s;


    if (out==NULL)
    {   printf("0\nCannot open out file\n");
        return 1;
    }
    if (sol==NULL)
    {   printf("0\nCannot open sol file\n");
        return 1;
    }

    while (1)
    {   o=fscanf(out,"%lf",&lout);
        s=fscanf(sol,"%lf",&lsol);

        if (o!=s)
        {   printf("0\nWrong answer\n");
            return 0;
        }
        if (o<=0 && s<=0)
        {   printf("10\nAccepted\n");
            return 0;
        }
        if (fabs(lout-lsol)>EPSILON)
        {   printf("0\nWrong answer\n");
            return 0;
        }
    }
}
