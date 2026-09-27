/*
    Programming Fundamentals Theory 
    Question 3 Part B
    Syed Sajid Ali
*/

#include <stdio.h>

int main() {
    int sub1, sub2, sub3, sub4, sub5;
    for (int i = 1; i < 5; i++) {
        printf("Enter Subject 1 marks: ");
        scanf("%d", &sub1);
        printf("Enter Subject 2 marks: ");
        scanf("%d", &sub2);
        printf("Enter Subject 3 marks: ");
        scanf("%d", &sub3);
        printf("Enter Subject 4 marks: ");
        scanf("%d", &sub4);
        printf("Enter Subject 5 marks: ");
        scanf("%d", &sub5);
        int average = (sub1 + sub2 + sub3 + sub4 + sub5) / 5.0;
        printf("Average marks: %d\n", average);

        if (average >= 80 && average <= 100) {
            if (sub1 > 33 && sub2 > 33 && sub3 > 33 && sub4 > 33 && sub5 > 33) {
                printf("Distinction\n");
            }
            else {
                printf("Fail-Subject Deficiency\n");
            }
        } else if (average >= 60 && average < 80) {
            if (sub1 > 33 && sub2 > 33 && sub3 > 33 && sub4 > 33 && sub5 > 33) {
                printf("Pass\n");
            }
            else {
                printf("Fail-Subject Deficiency\n");
            }
        } else {
            printf("Fail\n");
        }

    return 0;
}
}