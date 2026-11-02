#include <stdio.h>

int isPrime(int n)
{
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void printPrimes(int start, int end)
{
    int i;

    printf("Primes: ");

    for (i = start; i <= end; i++)
    {
        if (isPrime(i) == 1)
            printf("%d ", i);
    }

    printf("\n");
}

int countPrimes(int start, int end)
{
    int i, count = 0;

    for (i = start; i <= end; i++)
    {
        if (isPrime(i) == 1)
            count++;
    }

    return count;
}

int main()
{
    int start, end;

    do
    {
        printf("Enter range: ");
        scanf("%d %d", &start, &end);

        if (start >= end)
            printf("Start must be smaller than end.\n");

    } while (start >= end);

    printPrimes(start, end);

    printf("Total primes found: %d\n",
           countPrimes(start, end));

    return 0;
}
