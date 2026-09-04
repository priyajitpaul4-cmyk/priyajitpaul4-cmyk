/*
    Program 08: Print Prime Numbers in a Given Range
    Topic: Loops (nested loop)
    Lab question: "Print prime no. in a given range."

    A prime number is greater than 1 and is divisible only by 1 and
    itself. For every number in the range we try dividing it by 2, 3, ...
    up to number/2. If nothing divides it, the number is prime.
*/

#include <stdio.h>
#include "../projects.h"

void program08(void)
{
    int low, high;
    int number, divisor;
    int isPrime;
    int count = 0;

    printf("\n--- Program 08: Prime Numbers in a Given Range ---\n");

    printf("Enter the lower and upper limit of the range: ");
    if (scanf("%d %d", &low, &high) != 2) {
        printf("Invalid input! Two whole numbers are required.\n");
        return;
    }

    /* If the user typed the bigger number first, correct it quietly. */
    if (low > high) {
        int temp = low;
        low      = high;
        high     = temp;
        printf("(Limits were swapped to %d to %d)\n", low, high);
    }

    if (high < 2) {
        printf("There is no prime number between %d and %d.\n", low, high);
        return;
    }

    if (low < 2) {
        low = 2;      /* 0 and 1 are not prime */
    }

    printf("\nPrime numbers between %d and %d are:\n", low, high);

    for (number = low; number <= high; number++) {
        isPrime = 1;

        for (divisor = 2; divisor <= number / 2; divisor++) {
            if (number % divisor == 0) {
                isPrime = 0;      /* it divides evenly, so not prime */
                break;
            }
        }

        if (isPrime) {
            printf("%d ", number);
            count++;

            if (count % 10 == 0) {          /* keep the output tidy */
                printf("\n");
            }
        }
    }

    printf("\nTotal prime numbers found : %d\n", count);
}

/*
    ==================================================================
    EXPLANATION  -  Program 08: Print Prime Numbers in a Given Range
    ==================================================================
    Two loops are needed. The outer for loop walks through every number in the
    range; the inner for loop trial-divides that number from 2 up to number/2.
        number % divisor == 0  ->  a divisor was found  ->  not prime  ->  break
    'break' leaves the inner loop early, which saves time. isPrime is a flag: it
    starts at 1 and is only switched off. Two guards make the program safe: the
    limits are swapped if typed the wrong way round, and 'low' is raised to 2
    because 0 and 1 are not prime numbers.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 08: Prime Numbers in a Given Range ---
        Enter the lower and upper limit of the range: 1 30

        Prime numbers between 2 and 30 are:
        2 3 5 7 11 13 17 19 23 29 

        Total prime numbers found : 10

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
