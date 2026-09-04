/*
    Program 04: Check Whether a Number is Even or Odd
    Topic: Basic Programs & Format Specifiers (modulus operator)
    Lab question: "Write a program to check whether a no. is even or odd."

    A number is even when dividing it by 2 leaves remainder 0.
    The % (modulus) operator gives that remainder.
*/

#include <stdio.h>
#include "../projects.h"

void program04(void)
{
    int number;

    printf("\n--- Program 04: Even or Odd ---\n");

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please type a whole number.\n");
        return;
    }

    if (number % 2 == 0) {
        printf("%d is an EVEN number.\n", number);
    } else {
        printf("%d is an ODD number.\n", number);
    }

    /*
        Note: % with a negative odd number gives -1 (for example -3 % 2),
        which is why we compare against 0 only. Zero itself is even.
    */
}

/*
    ==================================================================
    EXPLANATION  -  Program 04: Check Whether a Number is Even or Odd
    ==================================================================
    % (modulus) gives the remainder of a division. A number is even exactly when
    dividing it by 2 leaves remainder 0.
        7 % 2  ->  1  ->  not 0  ->  odd
      - 3 % 2  -> -1  ->  not 0  ->  odd   (a negative remainder is still not zero,
                                              which is why we compare against 0 only)
    Zero is even. This is the shortest program in the lab and the classic example
    for the modulus operator.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 04: Even or Odd ---
        Enter an integer: 7
        7 is an ODD number.

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
