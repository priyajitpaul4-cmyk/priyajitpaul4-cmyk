/*
    Program 16: Check Whether a Given Number is Prime or Not
    Topic: Loops
    Lab question: "Write a program to check whether a number is prime
                   or not."

    Prime  : a number greater than 1 that has no divisor other than 1
             and itself (2, 3, 5, 7, 11 ...).
    Method : try dividing by 2, 3, 4 ... up to number/2. If any of them
             divides it exactly, the number is not prime.
*/

#include <stdio.h>
#include "../projects.h"

void program16(void)
{
    int number, divisor;
    int isPrime = 1;

    printf("\n--- Program 16: Prime or Not ---\n");

    printf("Enter a whole number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please type a whole number.\n");
        return;
    }

    if (number < 2) {
        printf("%d is NOT a prime number (primes start from 2).\n", number);
        return;
    }

    for (divisor = 2; divisor <= number / 2; divisor++) {
        if (number % divisor == 0) {
            isPrime = 0;                       /* found a divisor */
            break;
        }
    }

    if (isPrime) {
        printf("%d IS a prime number.\n", number);
    } else {
        printf("%d is NOT a prime number (it is divisible by a number"
               " other than 1 and itself).\n", number);
    }

    printf("\nFaster version for big numbers: run the loop only up to the\n"
           "square root, i.e.  for (divisor = 2; divisor * divisor <= number; divisor++)\n");
}

/*
    ==================================================================
    EXPLANATION  -  Program 16: Check Whether a Given Number is Prime or Not
    ==================================================================
    One number this time (Program 08 does the same test across a range). The loop
    tries every divisor from 2 to number/2; if any of them divides exactly, the
    number is not prime and 'break' ends the loop at once.
    The check number < 2 runs first, because 1 - and every negative number - is not
    prime, yet the loop would never find a divisor for it and would wrongly call it
    prime. The closing comment shows the faster upper limit, sqrt(number).

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 16: Prime or Not ---
        Enter a whole number: 29
        29 IS a prime number.

        Faster version for big numbers: run the loop only up to the
        square root, i.e.  for (divisor = 2; divisor * divisor <= number; divisor++)

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
