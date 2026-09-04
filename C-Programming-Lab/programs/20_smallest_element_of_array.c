/*
    Program 20: Print the Smallest Element of an Array
    Topic: Arrays
    Lab question: "Write a program to print small element of an array."

    Store the elements, assume the first one is the smallest, then compare
    it with every other element and keep the smaller one.
*/

#include <stdio.h>
#include "../projects.h"

#define MAX_SIZE 100

void program20(void)
{
    int numbers[MAX_SIZE];
    int count, i;
    int smallest, position;

    printf("\n--- Program 20: Smallest Element of an Array ---\n");

    printf("How many elements (1 - %d)? ", MAX_SIZE);
    if (scanf("%d", &count) != 1) {
        printf("Invalid input! Enter a whole number for the size.\n");
        return;
    }

    if (count < 1 || count > MAX_SIZE) {
        printf("Invalid size! It must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("Enter %d integer(s):\n", count);
    for (i = 0; i < count; i++) {
        printf("  element [%d] : ", i);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input! Stopped reading after %d value(s).\n", i);
            return;
        }
    }

    smallest = numbers[0];
    position = 0;

    for (i = 1; i < count; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
            position = i;
        }
    }

    printf("\nArray elements : ");
    for (i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\nSmallest element = %d (found at index %d, i.e. position %d)\n",
           smallest, position, position + 1);
}

/*
    ==================================================================
    EXPLANATION  -  Program 20: Print the Smallest Element of an Array
    ==================================================================
    'Assume the first one, then prove it wrong' is the standard way to search an
    array:
        smallest = numbers[0];              start with the first element
        if (numbers[i] < smallest) { ... }  every smaller value replaces it
    The loop starts at i = 1 because element 0 is already the assumed answer.
    'position' is updated together with the value, so the program can also report
    where the smallest element was found - index 3 means position 4, since C arrays
    start at 0. count is checked against MAX_SIZE before the reading loop runs.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 20: Smallest Element of an Array ---
        How many elements (1 - 100)? 5
        Enter 5 integer(s):
          element [0] : 9
          element [1] : 3
          element [2] : 7
          element [3] : 1
          element [4] : 8

        Array elements : 9 3 7 1 8 
        Smallest element = 1 (found at index 3, i.e. position 4)

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
