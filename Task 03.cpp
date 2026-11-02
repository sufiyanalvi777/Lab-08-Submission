#include <stdio.h>
#include <math.h>

int validateWithdrawal(float balance, float amount)
{
    if (amount <= 0 || fmodf(amount, 500.0f) != 0)
        return 0;

    if (amount > balance)
        return -1;

    if (balance - amount < 1000)
        return -2;

    return 1;
}

float withdraw(float balance, float amount)
{
    return balance - amount;
}

void showMessage(int code)
{
    switch (code)
    {
        case 1:
            printf("Withdrawal successful. ");
            break;

        case 0:
            printf("Error: Enter a positive multiple of 500.\n");
            break;

        case -1:
            printf("Error: Insufficient balance.\n");
            break;

        case -2:
            printf("Error: Minimum balance of Rs. 1000 "
                   "must be maintained.\n");
            break;
    }
}

int main()
{
    float balance, amount;
    int code;

    do
    {
        printf("Balance: ");
        scanf("%f", &balance);

        if (balance < 0)
            printf("Balance cannot be negative.\n");

    } while (balance < 0);

    while (1)
    {
        printf("Enter amount (0 to exit): ");
        scanf("%f", &amount);

        if (amount == 0)
            break;

        code = validateWithdrawal(balance, amount);
        showMessage(code);

        if (code == 1)
        {
            balance = withdraw(balance, amount);
            printf("New balance: %.2f\n", balance);
        }
    }

    return 0;
}
