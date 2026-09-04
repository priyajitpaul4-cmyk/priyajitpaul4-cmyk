/*
    Program 17: Print All Armstrong Numbers in the Range 100 - 1000
    Topic: Loops
    Lab question: "Print all Armstrong number in a range 100-1000."

    An Armstrong (narcissistic) number equals the sum of the cubes of
    its digits, e.g. 153 = 1^3 + 5^3 + 3^3.
    The cube rule fits this range because every number in it has 3 digits
    (100 to 999); 1000 is checked as well and correctly reported as
    not an Armstrong number.
*/

#include <stdio.h>
#include "../projects.h"

void program17(void)
{
    int start = 100;         /* range fixed by the lab question */
    int finish = 1000;
    int number, temp, digit, sum;
    int count = 0;

    printf("\n--- Program 17: Armstrong Numbers in Range 100 - 1000 ---\n");

    printf("Armstrong numbers between %d and %d are:\n\n", start, finish);

    for (number = start; number <= finish; number++) {
        sum  = 0;
        temp = number;

        /* add the cube of every digit */
        while (temp > 0) {
            digit = temp % 10;             /* take the last digit  */
            sum   = sum + (digit * digit * digit);
            temp  = temp / 10;             /* remove that digit    */
        }

        if (sum == number) {
            printf("%d  =  ", number);

            temp = number;                 /* print the digits again for the record */
            while (temp > 0) {
                digit = temp % 10;
                printf("%d^3", digit);
                temp = temp / 10;
                if (temp > 0) {
                    printf(" + ");
                }
            }

            printf(" = %d\n", sum);
            count++;
        }
    }

    printf("\nTotal Armstrong numbers found : %d\n", count);
}

/*
    ==================================================================
    EXPLANATION  -  Program 17: Print All Armstrong Numbers in the Range 100 - 1000
    ==================================================================
    The outer for loop visits every number from 100 to 1000. For each one, an
    inner while loop peels off the digits and adds their cubes:
        temp % 10   last digit      temp / 10   remove that digit
    temp destroys itself, so the original value is kept in 'number' for the final
    comparison  sum == number. That comparison is the definition of an Armstrong
    number. Result for this range: 153, 370, 371 and 407, so the count is 4.
    The digit breakdown is printed next to each answer to show the working.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 17: Armstrong Numbers in Range 100 - 1000 ---
        Armstrong numbers between 100 and 1000 are:

        153  =  3^3 + 5^3 + 1^3 = 153
        370  =  0^3 + 7^3 + 3^3 = 370
        371  =  1^3 + 7^3 + 3^3 = 371
        407  =  7^3 + 0^3 + 4^3 = 407

        Total Armstrong numbers found : 4

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
