/*
    Programming Fundamentals Theory 
    Question 2 Part B
    Syed Sajid Ali
*/

#include <stdio.h>
int main() {
    int req_floor, i, N;
    printf("Enter the required floor: ");
    scanf("%d", &req_floor);
    for (int N = 1; N < 6; N++) {
        for (int i = 0; i <= req_floor; i++) {
            printf("Current Floor %d\n", i);
            if (req_floor<i)
            {
                printf("Moving Down\n");
                continue;
            }
            else if (req_floor>i)
            {
                printf("Moving Up\n");
                continue;
            }
            else
            {
                printf("Door's Opening\n");
                continue;
            }         
      }
return 0;
}
}
