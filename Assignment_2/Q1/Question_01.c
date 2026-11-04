// Programming Fundamental Theory

// Programmer Name: Syed Sajid Ali

// Question: 01

#include <stdio.h>

int main ( ) {
    int rows, seats, group_size;

    printf ( "Enter number of rows: " );
    scanf ( "%d", &rows );

    printf ( "Enter number of seats per row: " );
    scanf ( "%d", &seats );

    if (rows <= 0 || seats <= 0) {
        printf ( "Invalid hall size.\n" );
        return 0;
    }

    int hall[rows][seats];

    printf ( "Enter seating status (0 for available, 1 for booked):\n" );

    for (int row_index= 0; row_index < rows; row_index++) {
        for (int seat_index= 0; seat_index < seats; seat_index++) {
            scanf ( "%d", &hall[row_index][seat_index] );
        }
    }

    int total_free= 0;

    printf ( "Free seats per row: " );

    for (int row_index= 0; row_index < rows; row_index++) {
        int free_count= 0;

        for (int seat_index= 0; seat_index < seats; seat_index++) {
            if (hall[row_index][seat_index] == 0) {
                free_count++;
            }
        }

        total_free += free_count;
        printf ( "%d ", free_count );
    }

    printf ( "\nTotal free seats: %d\n", total_free );

    printf ( "Enter number of customers to sit together: " );
    scanf ( "%d", &group_size );

    if (group_size <= 0 || group_size > seats) {
        printf ( "Invalid group size.\n" );
        return 0;
    }

    int middle_row= rows / 2;
    int found= 0;
    int target_row= -1;
    int start_seat= -1;

    // Search from the middle row outwards

    for (int distance= 0; distance < rows; distance++) {
        int row_option[2];
        int row_option_count= 0;

        if (distance == 0) {
            row_option[row_option_count]= middle_row;
            row_option_count++;
        }

        else {
            if (middle_row - distance >= 0) {
                row_option[row_option_count]= middle_row - distance;
                row_option_count++;
            }

            if (middle_row + distance < rows) {
                row_option[row_option_count]= middle_row + distance;
                row_option_count++;
            }
        }

        for (int option_index= 0; option_index < row_option_count; option_index++) {
            int current_row= row_option[option_index];
            int consecutive_count= 0;
            int first_seat= -1;

            for (int seat_index= 0; seat_index < seats; seat_index++) {
                if (hall[current_row][seat_index] == 0) {
                    if (consecutive_count == 0) {
                        first_seat= seat_index;
                    }

                    consecutive_count++;

                    if (consecutive_count == group_size) {
                        target_row= current_row;
                        start_seat= first_seat;
                        found= 1;
                        break;
                    }
                }

                else {
                    consecutive_count= 0;
                    first_seat= -1;
                }
            }

            if (found == 1) {
                break;
            }
        }

        if (found == 1) {
            break;
        }
    }

    if (found == 1) {
        printf ( "Group of %d seated in Row %d, Seats %d to %d\n",
                 group_size, target_row, start_seat, start_seat + group_size - 1 );

        // Mark the selected seats as booked

        for (int seat_index= start_seat; seat_index < start_seat + group_size; seat_index++) {
            hall[target_row][seat_index]= 1;
        }
        total_free -= group_size;

        printf ( "\nUpdated seating layout (X means booked):\n" );

        for (int row_index= 0; row_index < rows; row_index++) {
            printf ( "R%d  ", row_index );

            for (int seat_index= 0; seat_index < seats; seat_index++) {
                if (hall[row_index][seat_index] == 1) {
                    printf ( "X " );
                }

                else {
                    printf ( "_ " );
                }
            }

            printf ( "\n" );
        }
        printf ( "Remaining free seats: %d\n", total_free );
    }

    else {
        printf ( "No row contains %d consecutive available seats.\n", group_size );
    }

    return 0;
}
