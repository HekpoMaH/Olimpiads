#include <cstdio>

int main ()
{
    float prev_price = 999999, crnt_price;
    int seq = 1, maxseq = 1;

    while (crnt_price > 0)
    {
        scanf ("%f", &crnt_price);
        if (prev_price <= crnt_price)
        {
            seq ++;
        }
        else
        {
            if (seq > maxseq)
            {
                maxseq = seq;
            }
            seq = 1;
        }
        prev_price = crnt_price;
    }

    printf ("%d\n", maxseq);

    return 0;
}
