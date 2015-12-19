/*
 *
 */
#include <stdio.h>
#include <math.h>

void integral_recur (int nmin, int nmax, double vals[]);
void integral_gen (int nmin, int nmax, double vals[]);

void integral_recur (int nmin, int nmax, double vals[])
{
    vals[nmax] = 0.;
    for (int i = nmax - 1; i >= nmin; i--)
    {
        vals[i] = (1. / M_E + vals[i + 1]) / (i + 1);
    }
}

#define NMAX 100

int main (void)
{

    double vals1[NMAX + 1], vals2[NMAX + 1];
    int nmin = 10;
    int nmax = 100;
    int i;

    integral_recur (nmin, nmax, vals1);
    integral_gen (nmin, nmax, vals2);

    for (i = nmin; i <= nmax; i++)
    {
        printf ("%5d      %24.6f   %24.6f\n", i, vals1[i], vals2[i]);
    }

    return 0;
}
