/*
    Programming Fundamentals Theory
    Task: 01
    Part: A
    Syed Sajid Ali
*/

#include <stdio.h>
int main() {
    int n;

    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--)
        printf("%d ", i);

        
    return 0;
}