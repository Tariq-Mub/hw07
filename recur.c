/*
 *
 */
#include <stdio.h>
#include <math.h>

void integral_recur (int nmin, int nmax, double vals[]);

void integral_recur (int nmin, int nmax, double vals[])
{
    vals[nmax] = 0.;
    for (int i = nmax - 1; i >= nmin; i--)
    {
        vals[i] = 1. / (i * M_E) + vals[i + 1] / i;
    }
}

#define NMAX 100

int main (void)
{

    double vals1[NMAX + 1], vals2[NMAX + 1];
    int nmin = 1;
    int nmax = 100;
    int i;
    integral_recur (nmin, nmax, vals1);

    for (i = nmin; i <= nmax; i++)
    {
        printf ("%5d      %24.6f\n", i, vals1[i]);
    }

    return 0;
}
