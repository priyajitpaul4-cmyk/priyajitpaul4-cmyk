/*
    Program 14: Factorial of a Given Number (using recursion)
    Topic: Functions & Recursion
    Lab question: "Factorial using recursion of a given number."

    Recursion means the function calls itself with a smaller value:
        factorial(n) = n * factorial(n - 1)      for n >= 1
        factorial(0) = 1                          (stopping condition)
*/

#include <stdio.h>
#include "../projects.h"

/*
    static = private to this file. That way no other program file can
    clash with the name factorial(), which keeps the modular build safe.
*/
static long long factorial(int n)
{
    if (n == 0 || n == 1) {
        return 1;               /* base case: recursion stops here */
    }
    return n * factorial(n - 1);
}

void program14(void)
{
    int number;
    long long answer;

    printf("\n--- Program 14: Factorial Using Recursion ---\n");

    printf("Enter a whole number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! A factorial needs a whole number.\n");
        return;
    }

    if (number < 0) {
        printf("Factorial of a negative number (%d) is not defined.\n", number);
        return;
    }

    if (number > 20) {
        printf("%d! is too large to store in a long long, so the answer\n", number);
        printf("would overflow. Try 20 or less.\n");
        return;
    }

    answer = factorial(number);

    printf("\nfactorial(%d) = %lld\n", number, answer);
}

/*
    ==================================================================
    EXPLANATION  -  Program 14: Factorial of a Given Number (using recursion)
    ==================================================================
    Same task as Program 13, solved by recursion - the function calls itself with
    a smaller argument and multiplies the result:
        factorial(6) = 6 * factorial(5) = 6 * 5 * factorial(4) ... down to
        factorial(1) = 1                     <- base case, the recursion stops
    Every recursive function needs that base case; without it the calls would never
    end and the program would crash with a stack overflow. The helper is declared
    static, meaning it is private to this file, so no other program in the project
    can clash with the name factorial.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 14: Factorial Using Recursion ---
        Enter a whole number: 6

        factorial(6) = 720

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
