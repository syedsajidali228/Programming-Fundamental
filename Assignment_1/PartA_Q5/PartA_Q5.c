/*
    Programming Fundamentals Theory
    Task: 05
    Part: A
    Syed Sajid Ali
*/

#include <stdio.h>


int main() {

    int n, sum;
    printf("Enter number: ");
    scanf("%d", &n);

    while (n >= 10) {
        sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        printf("Sum: %d\n", sum);
        n = sum;
    }
    printf("Final single digit: %d\n", n);


    return 0;
}