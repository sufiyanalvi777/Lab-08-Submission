#include <stdio.h>
#include <limits.h>

long factorial(int n)
{
    long result = 1;
    int i;

    for (i = 1; i <= n; i++)
        result *= i;

    return result;
}

int reverseNumber(int n)
{
    int reverse = 0, digit;

    while (n > 0)
    {
        digit = n % 10;

        /* Check whether the reversed value would overflow. */
        if (reverse > (INT_MAX - digit) / 10)
            return -1;

        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    return reverse;
}

int isPalindrome(int n)
{
    return n == reverseNumber(n);
}

int sumOfDigits(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

void printFibonacci(int terms)
{
    int a = 0, b = 1, next, i;

    printf("Fibonacci Series: ");

    for (i = 0; i < terms; i++)
    {
        printf("%d ", a);

        if (i < terms - 1)
        {
            next = a + b;
            a = b;
            b = next;
        }
    }

    printf("\n");
}

int main()
{
    int choice, n, reversed;

    do
    {
        printf("\n1. Factorial\n");
        printf("2. Reverse Number\n");
        printf("3. Check Palindrome\n");
        printf("4. Sum of Digits\n");
        printf("5. Fibonacci Series\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            printf("Enter %s: ",
                   choice == 5 ? "number of terms" : "number");
            scanf("%d", &n);

            if (n < 0)
            {
                printf("Enter a non-negative number.\n");
                continue;
            }
        }

        switch (choice)
        {
            case 1:
                if (n > 12)
                    printf("Enter a number from 0 to 12.\n");
                else
                    printf("Factorial: %ld\n", factorial(n));
                break;

            case 2:
                reversed = reverseNumber(n);

                if (reversed == -1)
                    printf("Reversed number is too large.\n");
                else
                    printf("Reversed number: %d\n", reversed);
                break;

            case 3:
                if (isPalindrome(n))
                    printf("%d is a palindrome.\n", n);
                else
                    printf("%d is not a palindrome.\n", n);
                break;

            case 4:
                printf("Sum of digits: %d\n", sumOfDigits(n));
                break;

            case 5:
                if (n < 1 || n > 47)
                    printf("Enter between 1 and 47 terms.\n");
                else
                    printFibonacci(n);
                break;

            case 6:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice. Choose 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}
