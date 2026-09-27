/*
    Programming Fundamentals Theory 
    Question 1 Part B
    Syed Sajid Ali
*/

#include <stdio.h>
int main() {
    char room_type, season;
    int N, night_stayed, room_rate;
    for (int i = 1; i <= 4; i++)
    {
        printf("1.Peak Season\n2.Off-Peak Season\nEnter Season(P/O): ");
        scanf(" %c", &season);
        printf("1.Standard\n2.Deluxe\n3.Suite\nEnter Room Type(S/D/S): ");
        scanf(" %c", &room_type);
        printf("Enter number of nights: ");
        scanf("%d", &night_stayed);
        if (season == 'P' || season == 'p') {
            if (room_type == 'S' || room_type == 's') {
                if (night_stayed > 7) {
                    N = night_stayed * 5000 * .85;
                    printf("Total cost for %d nights in Standard room during Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 5000;
                    printf("Total cost for %d nights in Standard room during Peak Season: %d\n", night_stayed, N);
                }
            } else if (room_type == 'D' || room_type == 'd') {
                if (night_stayed > 7) {
                    N = night_stayed * 8000 * .85;
                    printf("Total cost for %d nights in Deluxe room during Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 8000;
                    printf("Total cost for %d nights in Deluxe room during Peak Season: %d\n", night_stayed, N);
                }
            } else if (room_type == 'S' || room_type == 's') {
                if (night_stayed > 7) {
                    N = night_stayed * 12000 * .85;
                    printf("Total cost for %d nights in Suite room during Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 12000 * .85;
                    printf("Total cost for %d nights in Suite room during Peak Season: %d\n", night_stayed, N);
                }
            }
        } else if (season == 'O' || season == 'o') {
            if (room_type == 'S' || room_type == 's') {
                if (night_stayed > 7) {
                    N = night_stayed * 3000 * .85;
                    printf("Total cost for %d nights in Standard room during Off-Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 3000;
                    printf("Total cost for %d nights in Standard room during Off-Peak Season: %d\n", night_stayed, N);
                }
            } else if (room_type == 'D' || room_type == 'd') {
                if (night_stayed > 7) {
                    N = night_stayed * 5000 * .85;
                    printf("Total cost for %d nights in Deluxe room during Off-Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 5000;
                    printf("Total cost for %d nights in Deluxe room during Off-Peak Season: %d\n", night_stayed, N);
                }
            } else if (room_type == 'U' || room_type == 'u') {
                if (night_stayed > 7) {
                    N = night_stayed * 8000 * .85;
                    printf("Total cost for %d nights in Suite room during Off-Peak Season with discount: %d\n", night_stayed, N);
                } else {
                    N = night_stayed * 8000;
                    printf("Total cost for %d nights in Suite room during Off-Peak Season: %d\n", night_stayed, N);
                }
            }
        }
    }
     
    
    return 0;
}