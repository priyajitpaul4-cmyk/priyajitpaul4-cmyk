/* ==========================================================================
   Code with C — content data
   32 programs · community problem set · interview questions
   ========================================================================== */

const C_COLORS = {
  purple: "#a855f7",
  blue: "#3b82f6",
  green: "#22c55e",
  orange: "#f59e0b",
  pink: "#ec4899",
};

const PROGRAMS = [
  { n: 1,  title: "Hexadecimal, Decimal, Octal display",     cat: "Basic Programs",     c: "purple" },
  { n: 2,  title: "Largest and smallest among three numbers", cat: "Basic Programs",     c: "blue"   },
  { n: 3,  title: "Class/grade based on marks",               cat: "Basic Programs",     c: "green"  },
  { n: 4,  title: "Even or odd number",                       cat: "Basic Programs",     c: "orange" },
  { n: 5,  title: "Leap year check",                          cat: "Basic Programs",     c: "pink"   },
  { n: 6,  title: "Spellings of numbers 1-10",                cat: "Basic Programs",     c: "blue"   },
  { n: 7,  title: "Sum of digits of a number",                cat: "Basic Programs",     c: "purple" },
  { n: 8,  title: "Reverse a number",                         cat: "Basic Programs",     c: "green"  },
  { n: 9,  title: "Palindrome number check",                  cat: "Basic Programs",     c: "orange" },
  { n: 10, title: "Armstrong number check",                   cat: "Basic Programs",     c: "pink"   },
  { n: 11, title: "Prime number check",                       cat: "Basic Programs",     c: "blue"   },
  { n: 12, title: "Primes up to N",                           cat: "Basic Programs",     c: "purple" },
  { n: 13, title: "Fibonacci series up to N",                 cat: "Basic Programs",     c: "green"  },
  { n: 14, title: "Factorial using loop",                     cat: "Basic Programs",     c: "orange" },
  { n: 15, title: "Factorial using recursion",                cat: "Recursion",          c: "pink"   },
  { n: 16, title: "GCD & LCM of two numbers",                 cat: "Basic Programs",     c: "blue"   },
  { n: 17, title: "Multiplication table generator",           cat: "Basic Programs",     c: "purple" },
  { n: 18, title: "Simple & compound interest",               cat: "Basic Programs",     c: "green"  },
  { n: 19, title: "Celsius to Fahrenheit table",              cat: "Basic Programs",     c: "orange" },
  { n: 20, title: "Pyramid star pattern",                     cat: "Patterns",           c: "pink"   },
  { n: 21, title: "Diamond star pattern",                     cat: "Patterns",           c: "blue"   },
  { n: 22, title: "Floyd's triangle",                         cat: "Patterns",           c: "purple" },
  { n: 23, title: "Sum of two matrices",                      cat: "Arrays",             c: "green"  },
  { n: 24, title: "Transpose of a matrix",                    cat: "Arrays",             c: "orange" },
  { n: 25, title: "Linear search",                            cat: "Arrays",             c: "pink"   },
  { n: 26, title: "Binary search",                            cat: "Arrays",             c: "blue"   },
  { n: 27, title: "Bubble sort",                              cat: "Arrays",             c: "purple" },
  { n: 28, title: "String length & reverse",                  cat: "Strings",            c: "green"  },
  { n: 29, title: "Vowel & consonant counter",                cat: "Strings",            c: "orange" },
  { n: 30, title: "Student records with struct",              cat: "Structures",         c: "pink"   },
  { n: 31, title: "Swap two numbers using pointers",          cat: "Pointers",           c: "blue"   },
  { n: 32, title: "Climbing stairs (1-D DP)",                 cat: "Dynamic Programming", c: "orange" },
];

const PROBLEMS = [
  {
    title: "Check Armstrong Number",
    diff: "easy",
    desc: "Write a program to check whether a number is an Armstrong number or not.",
    by: "user123", likes: 45, comments: 12,
  },
  {
    title: "Matrix Addition",
    diff: "medium",
    desc: "Write a program to add two matrices and display the result.",
    by: "coder_ash", likes: 32, comments: 8,
  },
  {
    title: "Palindrome String",
    diff: "easy",
    desc: "Check whether a given string is a palindrome or not using C.",
    by: "dev_sakshi", likes: 28, comments: 6,
  },
  {
    title: "Merge Two Sorted Arrays",
    diff: "hard",
    desc: "Merge two sorted arrays into a single sorted array.",
    by: "codehunter", likes: 51, comments: 15,
  },
  {
    title: "Binary Search",
    diff: "medium",
    desc: "Implement binary search in a sorted array.",
    by: "prog_wizard", likes: 37, comments: 9,
  },
];

const QUESTIONS = [
  {
    q: "What is the difference between == and = ?",
    a: "<code>=</code> is the assignment operator — it stores a value in a variable. <code>==</code> is a relational operator — it compares two values and returns 1 if they are equal, otherwise 0.",
  },
  {
    q: "What is the use of pointers in C?",
    a: "A pointer holds the memory address of another variable. Pointers enable dynamic memory allocation, efficient arrays and strings, pass-by-reference to functions, and building data structures like linked lists and trees.",
  },
  {
    q: "What is the difference between malloc() and calloc()?",
    a: "<code>malloc(size)</code> allocates one block of the given size and leaves it uninitialized. <code>calloc(n, size)</code> allocates n elements of that size and initializes every byte to zero.",
  },
  {
    q: "What is the difference between arrays and pointers?",
    a: "An array is a fixed-size block of contiguous elements whose name is a constant address, while a pointer is a variable that can be reassigned to point anywhere. <code>sizeof</code> an array gives the whole block; sizeof a pointer gives only the address size.",
  },
  {
    q: "What is recursion? Give an example.",
    a: "Recursion is when a function calls itself to solve smaller sub-problems, with a base case to stop. Example: factorial — <code>fact(n) = n * fact(n - 1)</code> with base case <code>fact(0) = 1</code>.",
  },
  {
    q: "What is the difference between struct and union?",
    a: "A struct allocates separate memory for every member, so all members hold values at once. A union shares one memory block for all members, so only one member can hold a meaningful value at a time.",
  },
  {
    q: "What is the difference between i++ and ++i?",
    a: "<code>i++</code> (post-increment) returns the current value and then increments it. <code>++i</code> (pre-increment) increments first and then returns the new value.",
  },
  {
    q: "What is a NULL pointer?",
    a: "A pointer that does not point to any valid memory location (its value is 0). It is used to indicate “no object yet” and protects against wild or dangling pointers.",
  },
  {
    q: "What is the use of the static keyword?",
    a: "Inside a function, <code>static</code> keeps a local variable's value between calls. At file scope, it limits the visibility of a variable or function to that file only.",
  },
  {
    q: "What are command line arguments?",
    a: "Values passed to a program when it is run, received by <code>main(int argc, char *argv[])</code>. <code>argc</code> is the count and <code>argv</code> holds the argument strings.",
  },
];
