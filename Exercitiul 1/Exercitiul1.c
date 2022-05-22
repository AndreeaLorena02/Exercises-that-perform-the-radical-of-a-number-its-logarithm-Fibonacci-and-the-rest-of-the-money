#include<stdio.h>
#include<stdlib.h>

double absolute(double v)
{
    return v * ((v>0) - (v<0));
}

double sqrt_2(double l, double r, double val)
{
    double e = 0.000001;
    double m = (l+r)/2;
    double y=m*m;
    if ((y == val) || (absolute(y - val) < e))
        return m;
    else if(y<val)
        return sqrt_2(m, r,val);

    else
        return sqrt_2(l, m,val);
}

double sqrt_3(double l, double r, double val)
{
    double e = 0.000001;
    double m = (l+r)/2;
    double y=m*m*m;
    if ((y == val) || (absolute(y - val) < e))
        return m;
    else if(y<val)
        return sqrt_3(m, r,val);

    else
        return sqrt_3(l, m,val);
}

int main()
{
    double n;
    printf("Dati numarul:");
    scanf("%lf",&n);
    printf("Alegeti optiunea: 2-> radical de ord 2 sau 3 ->radical de ord 3\n");
    int k;
    scanf("%d",&k);
    switch (k)
    {
    case 2:
        if(n<0)
            printf("Nu se poate radical de ordin 2!");
        else if(n>0)
            printf("%lf",sqrt_2(-1,n,n));
        break;
    case 3:
        printf("%lf",sqrt_3(-1,n,n));
        break;
    default:
        printf("Nu s-a gasit optiunea!");
        break;
    }

    return 0;
}
