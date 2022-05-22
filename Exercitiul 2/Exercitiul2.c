#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define E 0.0001

double logaritm(double l,double r,double n)
{
    double m = (l+r)/2;
    double y = pow(10,m);
    if ( n-E < y && y < n+E)
        return m;
    else if(y<n)
        return logaritm(m, r,n);

    else
        return logaritm(l, m,n);
}
int main()
{
    double n;
    printf("Dati numarul : ");
    scanf("%lf",&n);
    printf("lg(%lf) = %lf .",n,logaritm(0,n,n));
    return 0;
}
