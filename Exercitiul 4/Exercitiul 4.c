#include<stdio.h>
#include<stdlib.h>

int cate_tipuri_monede = 4;

int da_rest_memo(int rest, int *monede, int tip_moneda, int aux[101][4])
{
    if (aux[rest][tip_moneda]>0)
        return aux[rest][tip_moneda];
    if ( tip_moneda >=cate_tipuri_monede-1 )
        return 1;
    int cate_moduri = 0;
    int i, ce_ramane, val=monede[tip_moneda];
    for (i=0; i*val <= rest; i++)
    {
        ce_ramane = rest-i*val;
        cate_moduri+=da_rest_memo(ce_ramane, monede, tip_moneda+1,aux);
    }
    aux[rest][tip_moneda]=cate_moduri;
    return cate_moduri;
}


int da_rest(int rest, int *monede, int tip_moneda)
{
    if ( tip_moneda >=cate_tipuri_monede-1 )
        return 1;
    int cate_moduri = 0;
    int val=monede[tip_moneda];
    int i, ce_ramane;
    for (i=0; i*val <= rest; i++)
    {
        ce_ramane = rest-i*val;
        cate_moduri+=da_rest(ce_ramane, monede, tip_moneda+1);
    }
    return cate_moduri;
}

int main()
{
    int i,j,n=100;
    int monede[4] = {25,10,5,1};
    int aux[101][4] = {0};
    printf("Rest memoizare : %d", da_rest_memo(n,monede,0,aux));
    printf("\nRest fara memoizare : %d", da_rest(n,monede,0));
    return 0;
}
