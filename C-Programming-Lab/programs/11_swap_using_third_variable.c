/*
    Program 11: Swap Two Variables Using a Third Variable
    Topic: Operators & Expressions
    Lab question: "Write a program to swap values of two variables using
                   third variable."

    The third variable (temp) holds the value of a while a receives b.
*/

#include <stdio.h>
#include "../projects.h"

void program11(void)
{
    int a, b, temp;

    printf("\n--- Program 11: Swap Using a Third Variable ---\n");

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

    temp = a;      /* temp  holds 3 */
    a    = b;      /* a     holds 5 */
    b    = temp;   /* b     holds 3 */

    printf("After swapping  : a = %d, b = %d\n", a, b);
}

/*
    ==================================================================
    EXPLANATION  -  Program 11: Swap Two Variables Using a Third Variable
    ==================================================================
    If we only wrote a = b, the old value of a would be lost, so it is saved in
    a third variable first. Three steps:
        temp = a;   save what would be destroyed
        a    = b;   now a has b's value
        b    = temp; give b the saved old value of a
    This is the safe method and the one to use when the values are not numbers
    (for example when swapping strings with strcpy).

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 11: Swap Using a Third Variable ---
        Enter value of a: 3
        Enter value of b: 5

        Before swapping : a = 3, b = 5
        After swapping  : a = 5, b = 3

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
