// Programming Fundamental Theory

// Programmer Name: Syed Sajid Ali

// Question: 04

#include <stdio.h>

int get_valid_days ( ) {
    int days;

    do {
        printf ( "Enter number of festival days (1-7): " );
        scanf ( "%d", &days );

        if (days < 1 || days > 7) {
            printf ( "Invalid days. Try again.\n" );
        }

    } while (days < 1 || days > 7);

    return days;
}

float calculate_daily_sales ( int day_number ) {
    int orders;

    printf ( "Day %d - Number of orders: ", day_number );
    scanf ( "%d", &orders );

    while (orders <= 0) {
        printf ( "Enter at least one order: " );
        scanf ( "%d", &orders );
    }

    float total_sales= 0;
    float highest_order= 0;

    printf ( "Enter order amounts: " );

    for (int order_index= 0; order_index < orders; order_index++) {
        float amount;
        scanf ( "%f", &amount );

        while (amount <= 0) {
            printf ( "Invalid amount. Re-enter: " );
            scanf ( "%f", &amount );
        }

        total_sales += amount;

        if (amount > highest_order) {
            highest_order= amount;
        }
    }

    printf ( "Total sales: Rs. %.2f\n", total_sales );
    printf ( "Average: Rs. %.2f\n", total_sales / orders );
    printf ( "Highest order: Rs. %.2f\n", highest_order );

    return total_sales;
}

int find_highest_sales_day ( float daily_sales[], int number_of_days ) {
    int best_day= 1;
    float highest_sales= daily_sales[0];

    for (int day_index= 1; day_index < number_of_days; day_index++) {
        if (daily_sales[day_index] > highest_sales) {
            highest_sales= daily_sales[day_index];
            best_day= day_index + 1;
        }
    }

    return best_day;
}

void display_bar_chart ( float daily_sales[], int number_of_days ) {
    printf ( "\nBAR CHART (one * represents Rs. 100):\n" );

    for (int day_index= 0; day_index < number_of_days; day_index++) {
        printf ( "Day %d: ", day_index + 1 );

        int star_count= (int)(daily_sales[day_index] / 100);

        for (int star_index= 0; star_index < star_count; star_index++) {
            printf ( "*" );
        }

        printf ( " (Rs. %.2f)\n", daily_sales[day_index] );
    }
}

int main ( ) {
    int days= get_valid_days ( );
    float daily_sales[days];
    float total_festival_sales= 0;

    for (int day_index= 0; day_index < days; day_index++) {
        daily_sales[day_index]= calculate_daily_sales ( day_index + 1 );
        total_festival_sales += daily_sales[day_index];
    }

    int top_day= find_highest_sales_day ( daily_sales, days );

    printf ( "\nFESTIVAL SUMMARY:\n" );
    printf ( "Total sales: Rs. %.2f\n", total_festival_sales );
    printf ( "Top sales day: Day %d\n", top_day );

    display_bar_chart ( daily_sales, days );

    return 0;
}
