/*
    Program 13: Factorial of a Given Number (using a loop)
    Topic: Functions & Recursion group / Loops
    Lab question: "Program to find the factorial of a given number."

    factorial(n) = 1 * 2 * 3 * ... * n      and  0! = 1
*/

#include <stdio.h>
#include "../projects.h"

void program13(void)
{
    int number, i;
    long long fact = 1;

    printf("\n--- Program 13: Factorial of a Number Using a Loop ---\n");

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
        printf("%d! is too large to store in a long long (it needs more\n", number);
        printf("than 64 bits), so the answer would be wrong. Try 20 or less.\n");
        return;
    }

    for (i = 1; i <= number; i++) {
        fact = fact * i;
    }

    printf("\n%d! = %lld\n", number, fact);
}

/*
    ==================================================================
    EXPLANATION  -  Program 13: Factorial of a Given Number (using a loop)
    ==================================================================
    factorial(n) = 1 * 2 * 3 * ... * n. An accumulator variable is started at 1
    (1 is the identity of multiplication, so multiplying by nothing leaves it
    correct) and the loop multiplies it by 2, 3, ... n.
    0! and 1! are both 1, and the loop handles them correctly by simply not
    running for 0. long long is used instead of int because 13! = 6227020800 is
    already too big for a 32-bit int; the guard at n > 20 stops the program from
    printing a silently wrong number.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 13: Factorial of a Number Using a Loop ---
        Enter a whole number: 5

        5! = 120

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
