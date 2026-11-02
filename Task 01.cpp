#include <stdio.h>

float calculateBill(int units)
{
    float bill;

    if (units <= 100)
        bill = units * 10;
    else if (units <= 200)
        bill = 100 * 10 + (units - 100) * 15;
    else
        bill = 100 * 10 + 100 * 15 + (units - 200) * 20;

    return bill + 150;
}

void printBill(int units, float bill)
{
    printf("Units Consumed: %d\n", units);
    printf("Total Bill: Rs. %.2f\n", bill);
}

int main()
{
    int units, i;
    float bill;

    for (i = 1; i <= 3; i++)
    {
        printf("\nCustomer %d\n", i);

        do
        {
            printf("Enter units: ");
            scanf("%d", &units);

            if (units < 0)
                printf("Units cannot be negative.\n");
        } while (units < 0);

        bill = calculateBill(units);
        printBill(units, bill);
    }

    return 0;
}
