// Programming Fundamental Theory

// Programmer Name: Syed Sajid Ali

// Question: 05

#include <stdio.h>
#include <string.h>

void display_menu ( ) {
    printf ( "\n1. Register\n2. View Books\n3. Borrow\n4. Return\n5. Member Record\n6. Exit\nChoice: " );
}

void register_member ( char member_name[], int *student_id, int *member_type ) {
    printf ( "Name: " );
    scanf ( " %49[^\n]", member_name );

    printf ( "ID: " );
    scanf ( "%d", student_id );

    printf ( "Type (1-Student, 2-Faculty): " );
    scanf ( "%d", member_type );

    while (*member_type != 1 && *member_type != 2) {
        printf ( "Enter 1 for Student or 2 for Faculty: " );
        scanf ( "%d", member_type );
    }
}

void display_books ( int book_ids[], char book_titles[][50], int available_copies[], int total_books ) {
    printf ( "\nBook ID\tTitle\tCopies\n" );

    for (int book_index= 0; book_index < total_books; book_index++) {
        printf ( "%d\t%s\t%d\n", book_ids[book_index], book_titles[book_index], available_copies[book_index] );
    }
}

void borrow_book ( int book_ids[], int available_copies[], int total_books,
                   int borrowed_book_ids[], int *borrowed_count ) {

    if (*borrowed_count >= 3) {
        printf ( "Borrowing limit reached (maximum 3 books).\n" );
        return;
    }

    int book_id;
    printf ( "Enter Book ID: " );
    scanf ( "%d", &book_id );

    int book_index_found= -1;

    for (int book_index= 0; book_index < total_books; book_index++) {
        if (book_ids[book_index] == book_id) {
            book_index_found= book_index;
            break;
        }
    }

    if (book_index_found == -1 || available_copies[book_index_found] <= 0) {
        printf ( "Invalid ID or book is unavailable.\n" );
    }

    else {
        borrowed_book_ids[*borrowed_count]= book_id;
        (*borrowed_count)++;
        available_copies[book_index_found]--;
        printf ( "Book borrowed successfully!\n" );
    }
}

float return_book ( int book_ids[], int available_copies[], int total_books,
                    int borrowed_book_ids[], int *borrowed_count,
                    int member_type, float *total_fine ) {

    int book_id;
    printf ( "Return Book ID: " );
    scanf ( "%d", &book_id );

    int borrowed_index= -1;

    for (int book_index= 0; book_index < *borrowed_count; book_index++) {
        if (borrowed_book_ids[book_index] == book_id) {
            borrowed_index= book_index;
            break;
        }
    }

    if (borrowed_index == -1) {
        printf ( "You did not borrow this book.\n" );
        return 0;
    }

    int days_kept;
    printf ( "Days kept: " );
    scanf ( "%d", &days_kept );

    while (days_kept < 0) {
        printf ( "Enter a valid number of days: " );
        scanf ( "%d", &days_kept );
    }

    int allowed_days;
    float fine_per_day;

    if (member_type == 1) {
        allowed_days= 14;
        fine_per_day= 20.0;
    }

    else {
        allowed_days= 30;
        fine_per_day= 10.0;
    }

    float fine= 0;

    if (days_kept > allowed_days) {
        fine= (days_kept - allowed_days) * fine_per_day;
    }

    *total_fine += fine;

    for (int book_index= 0; book_index < total_books; book_index++) {
        if (book_ids[book_index] == book_id) {
            available_copies[book_index]++;
            break;
        }
    }

    // Remove the returned book from the borrowed list

    for (int book_index= borrowed_index; book_index < *borrowed_count - 1; book_index++) {
        borrowed_book_ids[book_index]= borrowed_book_ids[book_index + 1];
    }

    (*borrowed_count)--;

    printf ( "Book returned. Fine: Rs. %.2f\n", fine );

    return fine;
}

int main ( ) {
    int book_ids[]= {101, 102, 103, 104};
    char book_titles[][50]= {"C", "DS", "DB", "Networks"};
    int available_copies[] = {5, 3, 0, 4};

    char member_name[50]= "";
    int student_id= 0;
    int member_type= 1;
    int borrowed_book_ids[3];
    int borrowed_count= 0;

    float total_fine= 0;
    float fine_after_waiver= 0;
    int choice;

    do {
        display_menu ( );
        scanf ( "%d", &choice );

        switch (choice) {
            case 1:
                register_member ( member_name, &student_id, &member_type );
                break;

            case 2:
                display_books ( book_ids, book_titles, available_copies, 4 );
                break;

            case 3:
                borrow_book ( book_ids, available_copies, 4,
                              borrowed_book_ids, &borrowed_count );
                break;

            case 4: {
                return_book ( book_ids, available_copies, 4,
                              borrowed_book_ids, &borrowed_count,
                              member_type, &total_fine );

                char promo_code[20];
                printf ( "Enter promo code: " );
                scanf ( "%19s", promo_code );

                if (strcmp ( promo_code, "LIB2026" ) == 0) {
                    fine_after_waiver= total_fine * 0.5;
                }

                else {
                    fine_after_waiver= total_fine;
                }

                break;
            }

            case 5:
                printf ( "Member: %s | ID: %d | Fine: Rs. %.2f | After waiver: Rs. %.2f\n",
                         member_name, student_id, total_fine, fine_after_waiver );
                break;

            case 6:
                printf ( "Exiting library system.\n" );
                break;

            default:
                printf ( "Invalid choice. Try again.\n" );
        }

    } while (choice != 6);

    return 0;
}
