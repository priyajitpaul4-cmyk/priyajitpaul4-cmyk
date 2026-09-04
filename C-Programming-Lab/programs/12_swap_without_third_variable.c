/*
    Program 12: Swap Two Variables Without Using a Third Variable
    Topic: Operators & Expressions
    Lab question: "Write a program to swap two variables without using
                   third variable."

    Arithmetic method (the one used in the lab notes):
        a = a + b;   -> a now stores the sum
        b = a - b;   -> b becomes the old a
        a = a - b;   -> a becomes the old b
*/

#include <stdio.h>
#include "../projects.h"

void program12(void)
{
    int a, b;

    printf("\n--- Program 12: Swap Without a Third Variable ---\n");

    printf("Enter value of a: ");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input for a.\n");
        return;
    }

    printf("Enter value of b: ");
    if (scanf("%d", &b) != 1) {
        printf("Invalid input for b.\n");
        return;
    }

    printf("\nBefore swapping : a = %d, b = %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping  : a = %d, b = %d\n", a, b);

    printf("\nNote: the + and - method works for every int here. Another\n"
           "      way is  a = a ^ b; b = a ^ b; a = a ^ b;  (bitwise XOR).\n");
}

/*
    ==================================================================
    EXPLANATION  -  Program 12: Swap Two Variables Without Using a Third Variable
    ==================================================================
    No extra variable is allowed, so the two values are recovered from their sum:
        a = a + b;   a now holds the total of both
        b = a - b;   total minus b  = old a  -> b is now the old a
        a = a - b;   total minus new b = old b
    Trace with 3 and 5:  a=8, then b=8-5=3, then a=8-3=5.
    The comment at the bottom also shows the bitwise XOR swap, a third method.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 12: Swap Without a Third Variable ---
        Enter value of a: 3
        Enter value of b: 5

        Before swapping : a = 3, b = 5
        After swapping  : a = 5, b = 3

        Note: the + and - method works for every int here. Another
              way is  a = a ^ b; b = a ^ b; a = a ^ b;  (bitwise XOR).

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
