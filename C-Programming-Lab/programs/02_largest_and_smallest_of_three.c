/*
    Program 02: Find the Largest and Smallest Among Three Numbers
    Topic: Conditional Statements
    Lab question: "Find the largest & smallest among three no."

    Uses only if / else if / else, which is the method taught in the
    first lab classes (no library function, no array).
*/

#include <stdio.h>
#include "../projects.h"

void program02(void)
{
    int a, b, c;
    int largest, smallest;

    printf("\n--- Program 02: Largest and Smallest of Three Numbers ---\n");

    printf("Enter three integers separated by space: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input! Three whole numbers are required.\n");
        return;
    }

    /* ----- largest ----- */
    if (a >= b && a >= c) {
        largest = a;
    } else if (b >= a && b >= c) {
        largest = b;
    } else {
        largest = c;
    }

    /* ----- smallest ----- */
    if (a <= b && a <= c) {
        smallest = a;
    } else if (b <= a && b <= c) {
        smallest = b;
    } else {
        smallest = c;
    }

    printf("\nNumbers entered : %d, %d, %d\n", a, b, c);
    printf("Largest number  : %d\n", largest);
    printf("Smallest number : %d\n", smallest);
}

/*
    ==================================================================
    EXPLANATION  -  Program 02: Find the Largest and Smallest Among Three Numbers
    ==================================================================
    Three numbers are read into a, b and c, then two independent if - else if
    ladders find the largest and the smallest.
        if (a >= b && a >= c)  ->  a is not smaller than either number, so a is largest
        &&  is the logical AND: the branch runs only when both sides are true.
    The second ladder repeats the same idea with <= for the smallest value.
    Using >= and <= (instead of > and <) keeps the output correct when two or all
    three numbers are equal, e.g. 5 5 5.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 02: Largest and Smallest of Three Numbers ---
        Enter three integers separated by space: 12 7 34

        Numbers entered : 12, 7, 34
        Largest number  : 34
        Smallest number : 7

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
