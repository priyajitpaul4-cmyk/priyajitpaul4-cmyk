/*
    projects.h
    ----------
    Function prototypes for every program in the C Programming Lab.

    Every .c file inside programs/ implements exactly one of these.
    main.c includes this header and calls them through the menu.

    NOTE on (void):  `void program01(void);` is used instead of
    `void program01();` because (void) tells the compiler the function
    takes NO arguments. A bare () is an old-style declaration that
    silently accepts any arguments, which can hide real mistakes.
*/

#ifndef PROJECTS_H
#define PROJECTS_H

/* Basic Programs & Format Specifiers */
void program01(void);   /* Decimal, octal and hexadecimal of a number      */
void program04(void);   /* Even or odd                                      */

/* Operators & Expressions */
void program11(void);   /* Swap two variables using a third variable        */
void program12(void);   /* Swap two variables without using a third variable*/

/* Conditional Statements */
void program02(void);   /* Largest and smallest among three numbers         */
void program03(void);   /* First/second division according to marks entered */
void program05(void);   /* Leap year or not                                 */
void program07(void);   /* Real roots of a quadratic equation               */

/* Switch Case */
void program10(void);   /* Menu driven +, -, x, / using switch              */

/* Loops */
void program06(void);   /* Display numbers 1 to 10 on entry                 */
void program08(void);   /* Prime numbers in a given range                   */
void program09(void);   /* Print college name 20 times                      */
void program16(void);   /* Check whether a given number is prime or not     */
void program17(void);   /* Print all Armstrong numbers in range 100 - 1000  */
void program18(void);   /* Check whether a given number is Armstrong or not */
void program19(void);   /* Sum of digits of a number                        */

/* Functions & Recursion */
void program13(void);   /* Factorial of a given number using a loop         */
void program14(void);   /* Factorial of a given number using recursion      */

/* Arrays */
void program15(void);   /* Add numbers using an array                       */
void program20(void);   /* Print the smallest element of an array           */

#endif /* PROJECTS_H */
