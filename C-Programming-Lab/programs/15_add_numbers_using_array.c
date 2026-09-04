/*
    Program 15: Add Numbers Using an Array
    Topic: Arrays
    Lab question: "Write a program to add number using array."

    The numbers are stored in an array first, then a loop adds them up.
*/

#include <stdio.h>
#include "../projects.h"

#define MAX_SIZE 100      /* the array cannot hold more than this */

void program15(void)
{
    int numbers[MAX_SIZE];
    int count, i;
    long long sum = 0;

    printf("\n--- Program 15: Add Numbers Using an Array ---\n");

    printf("How many numbers do you want to add (1 - %d)? ", MAX_SIZE);
    if (scanf("%d", &count) != 1) {
        printf("Invalid input! Enter a whole number for the count.\n");
        return;
    }

    if (count < 1 || count > MAX_SIZE) {
        printf("Invalid count! It must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("Enter %d integer(s), separated by space or Enter:\n", count);
    for (i = 0; i < count; i++) {
        printf("  element [%d] : ", i);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input! Stopped reading after %d value(s).\n", i);
            return;
        }
    }

    /* add all the stored numbers */
    for (i = 0; i < count; i++) {
        sum = sum + numbers[i];
    }

    printf("\nNumbers stored in the array : ");
    for (i = 0; i < count; i++) {
        printf("%d", numbers[i]);
        if (i < count - 1) {
            printf(" + ");
        }
    }

    printf("\nSum of %d number(s)          : %lld\n", count, sum);
    printf("Average                        : %.2f\n", (double)sum / count);
}

/*
    ==================================================================
    EXPLANATION  -  Program 15: Add Numbers Using an Array
    ==================================================================
    'Using an array' means the numbers are kept in memory first and only then
    processed, so the program has three clear stages: read the count, store each
    value in numbers[], and run a second loop that adds them up.
    count is compared with MAX_SIZE before any reading, so the loop can never write
    past the end of the array - the most common array mistake in C.
    sum is long long so a long list cannot overflow, and the average casts to double
    so 100/4 prints 25.00 instead of the integer result 25.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 15: Add Numbers Using an Array ---
        How many numbers do you want to add (1 - 100)? 4
        Enter 4 integer(s), separated by space or Enter:
          element [0] : 10
          element [1] : 20
          element [2] : 30
          element [3] : 40

        Numbers stored in the array : 10 + 20 + 30 + 40
        Sum of 4 number(s)          : 100
        Average                        : 25.00

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
