// Programming Fundamental Theory

// Programmer Name: Syed Sajid Ali

// Question: 02

#include <stdio.h>

int sum_of_proper_divisors ( int number ) {
    int divisor_sum= 0;

    for (int divisor= 1; divisor <= number / 2; divisor++) {
        if (number % divisor == 0) {
            divisor_sum += divisor;
        }
    }

    return divisor_sum;
}

int main ( ) {
    int limit;

    printf ( "Enter number n: " );
    scanf ( "%d", &limit );

    if (limit < 1) {
        printf ( "Enter a positive number.\n" );
        return 0;
    }

    printf ( "Amicable pairs up to %d:\n", limit );

    int pair_count= 0;

    for (int first_number= 1; first_number <= limit; first_number++) {
        int second_number= sum_of_proper_divisors ( first_number );

        if (second_number > first_number && second_number <= limit) {
            int second_sum= sum_of_proper_divisors ( second_number );

            if (second_sum == first_number) {
                printf ( "(%d, %d)\n", first_number, second_number );
                pair_count++;
            }
        }
    }

    printf ( "Total pairs: %d\n", pair_count );

    return 0;
}
