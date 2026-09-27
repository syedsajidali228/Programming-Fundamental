/*
    Programming Fundamentals Theory
    Task: 02
    Part: A
    Syed Sajid Ali
*/

#include <stdio.h>


int main() {

    int y;
    printf("Enter year: ");
    scanf("%d", &y);

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        printf("Leap year");
    else
        printf("Not leap year");


    return 0;
}