/*
    Program 18: Check Whether a Given Number is an Armstrong Number
    Topic: Loops
    Lab question: "Write a program to check given no. is Armstrong or not."

    Armstrong number = sum of its own digits, each raised to the power of
    the number of digits.
        153   -> 1^3 + 5^3 + 3^3 = 153        (Armstrong)
        1634  -> 1^4 + 6^4 + 3^4 + 4^4 = 1634 (Armstrong)

    The digits version is used here (not only cubes) so the program also
    gives the correct answer for numbers with 1, 2, 4 or more digits.
*/

#include <stdio.h>
#include "../projects.h"

/* returns how many digits the number has */
static int count_digits(int n)
{
    int digits = 0;

    while (n > 0) {
        digits++;
        n = n / 10;
    }

    return digits;
}

/* returns base raised to the power exp, using a simple loop */
static int int_power(int base, int exp)
{
    int result = 1;
    int i;

    for (i = 1; i <= exp; i++) {
        result = result * base;
    }

    return result;
}

void program18(void)
{
    int number, temp, digit, digits, sum = 0;

    printf("\n--- Program 18: Armstrong or Not ---\n");

    printf("Enter a positive whole number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please type a whole number.\n");
        return;
    }

    if (number < 0) {
        printf("Please enter a positive number (got %d).\n", number);
        return;
    }

    digits = count_digits(number);
    temp   = number;

    while (temp > 0) {
        digit = temp % 10;                                  /* last digit   */
        sum   = sum + int_power(digit, digits);             /* digit ^ n    */
        temp  = temp / 10;                                  /* drop the digit*/
    }

    printf("\nNumber        : %d  (%d digit%s)\n", number, digits,
           digits == 1 ? "" : "s");
    printf("Sum of powers : %d\n", sum);

    if (sum == number) {
        printf("%d IS an Armstrong number.\n", number);
    } else {
        printf("%d is NOT an Armstrong number.\n", number);
    }
}

/*
    ==================================================================
    EXPLANATION  -  Program 18: Check Whether a Given Number is an Armstrong Number
    ==================================================================
    Program 17 fixes the range to 3-digit numbers, so it can get away with cubes.
    This program must work for any length, so it counts the digits first and raises
    every digit to THAT power - 153 uses cubes, 1634 uses fourth powers.
    Two small helper functions are used, and both are static (private to this file):
        count_digits(n)  how many digits does n have
        int_power(b, e)  b raised to e, done with a loop so math.h is not needed
    153 -> 1 + 125 + 27 = 153, which equals the number, so it is an Armstrong number.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 18: Armstrong or Not ---
        Enter a positive whole number: 153

        Number        : 153  (3 digits)
        Sum of powers : 153
        153 IS an Armstrong number.

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
