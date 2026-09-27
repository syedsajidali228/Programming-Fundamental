/*
    Programming Fundamentals Theory
    Task: 03
    Part: A
    Syed Sajid Ali
*/

#include <stdio.h>


int main() {

    int n, count = 0, temp;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    if (n == 0) count = 1;
    while (temp != 0) {
        count++;
        temp /= 10;
    }
    printf("Digits: %d\n", count);
    if (count == 1) printf("Single-digit");
    else if (count == 2) 
         printf("Double-digit");
    else if (count == 3) 
        printf("Triple-digit");
    else printf("More than triple-digit");

    
    return 0;
}