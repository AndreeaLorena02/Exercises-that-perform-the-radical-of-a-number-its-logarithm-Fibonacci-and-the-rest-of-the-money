#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

long int Fibonacci(long int n)
{
    if (n < 0)
        return Fibonacci(n * -1);
    if ((n == 0) || (n == 1))
        return n;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

long int Fibonacci_memo(long int n, long int memo[])
{
    if (n < 0)
        return Fibonacci_memo(n * -1,memo);
    if ((n==0) || (n==1))
        return n;
    if (memo[n]==0)
        memo[n] = Fibonacci_memo(n-1,memo) + Fibonacci_memo(n-2,memo) ;
    return memo[n];
}

int main()
{
    long int n,m;
    printf("Dati numarul:");
    scanf("%ld",&n);
    double time_spent = 0.0;
    clock_t begin = clock();
    if((-n)%2==0 && n<0 )
        printf("\nFara memoizare = %ld",-Fibonacci(n));
    else if((-n)%2==1 && n<0 || n>0)
        printf("\nFara memoizare = %ld",Fibonacci(n));

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTimpul fara memoizare este %f seconds", time_spent);

     long int *v=(int*)calloc(abs(n)+1,sizeof(int));
    if(n<0)
    {
        double time_spent = 0.0;
        clock_t begin = clock();
        m=Fibonacci_memo(n,v);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nTimpul cu memoizare este %f seconds", time_spent);
        if((-n)%2==0)
            printf("\nCu memoizare = %ld",-m);
        else if((-n)%2==1)
            printf("\nCu memoizare = %ld",m);

    }
    else if(n>0)
    {
        double time_spent = 0.0;
        clock_t begin = clock();
        m=Fibonacci_memo(n,v);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nTimpul cu memoizare este %f seconds", time_spent);
        printf("\nCu memoizare = %ld",m);
    }

    return 0;
}
