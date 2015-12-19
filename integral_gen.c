#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

void integral_gen (int nmin, int nmax, double vals[]);
double f (double x, void *params);

double f (double x, void *params)
{
    double n = (double) *(int *) params;
    double f = exp (-x) * pow (x, n);

    return f;
}

void integral_gen (int nmin, int nmax, double vals[])
{

    double a = 0., b = 1.;      // limits of integration
    double abserr = 0., relerr = 1.e-8; // requested errors
    double result;              // the integral value
    double error;               // the error estimate
    int n;

    size_t np = 1000;           // work area size
    gsl_integration_workspace *w = gsl_integration_workspace_alloc (np);

    gsl_function F;

    F.function = &f;
    F.params = &n;

    for (n = nmin; n <= nmax; n++)
    {
        gsl_integration_qag (&F, a, b, abserr, relerr, np, GSL_INTEG_GAUSS15,
            w, &result, &error);
        vals[n] = result;
    }

    gsl_integration_workspace_free (w);
}
