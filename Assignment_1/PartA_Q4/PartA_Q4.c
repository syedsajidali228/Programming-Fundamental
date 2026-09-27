/*
    Programming Fundamentals Theory
    Task: 04
    Part: A
    Syed Sajid Ali
*/

#include <stdio.h>


int main() {

    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) continue;
        printf("Table of %d:\n", i);
        for (int j = 1; j <= 10; j++)
            printf("%d x %d = %d\n", i, j, i * j);
        printf("\n");
    }


    return 0;
}