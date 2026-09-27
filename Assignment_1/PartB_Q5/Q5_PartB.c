/*
    Programming Fundamentals Theory 
    Question 5 Part B
    Syed Sajid Ali
*/
#include <stdio.h>

int main() {
    char user_type, permit, arriving_source, emergency_vehicle, space_available;
    int space_free; 
    printf("Is it an emergency vehicle? (Y/N): ");
    scanf(" %c", &emergency_vehicle);
    if (emergency_vehicle == 'n' || emergency_vehicle == 'N') {

        printf("1.Faculty\n2.Student\n3.Guest\nEnter User Type(F/S/G): ");
        scanf(" %c", &user_type);
        printf("1.Valid Permit (Y)\n2.Invalid Permit (N)\nEnter Permit (Y/N): ");
        scanf(" %c", &permit);
        printf("1.Car\n2.Bike\n3.Van\nEnter Arriving Source(C/B/V): ");
        scanf(" %c", &arriving_source);
        printf("1.Space Available (Y)\n2.Space Not Available (N)\nEnter Space Availability (Y/N): ");
        scanf(" %c", &space_available);

        if (user_type == 'F' || user_type == 'f') {

            if (permit == 'Y' || permit == 'y') {

                if (arriving_source == 'C' || arriving_source == 'c') {
                    printf("Faculty member with valid permit can park in Zone A.\n");
                } else if (arriving_source == 'B' || arriving_source == 'b') {
                    printf("Faculty member with valid permit can park in Zone A.\n");
                } else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'Y' || space_available == 'y')) {
                    printf("Faculty member with valid permit can park in Zone A.\n");
                }
                else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'N' || space_available == 'n')) {
                    printf("No space available for Van in Zone A. Proceed with other options.\n");
                }
                else 
                {
                    printf("Invalid arriving source.\n");
                }

            } else {
                printf("Faculty member without valid permit cannot enter.\n");
            }

        } else if (user_type == 'S' || user_type == 's') {
            if (permit == 'Y' || permit == 'y') {
                if (arriving_source == 'C' || arriving_source == 'c') {
                    printf("Student with valid permit can park in Zone B.\n");
                } else if (arriving_source == 'B' || arriving_source == 'b') {
                    printf("Student with valid permit can park in Zone B.\n");
                } else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'Y' || space_available == 'y')) {
                    printf("Student with valid permit can park in Zone B.\n");
                }
                else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'N' || space_available == 'n')) {
                    printf("No space available for Van in Zone B. Proceeding to Zone C.\n");
                    printf("Is there space available in Zone C? (Y/N): ");
                    scanf(" %c", &space_available);
                    if (space_available == 'Y' || space_available == 'y') {
                        printf("Space available in Zone C.\n");
                    } else if (space_available == 'N' || space_available== 'n')
                    {
                        printf("No space available in any Zone.\n");
                    }
                    {
                        printf("No space available in Zone C. Not allowed to park.\n");
                    }
                }
                else 
                {
                    printf("Invalid arriving source.\n");
                }

            } 
            else {
                printf("Student without valid permit cannot enter.\n");
            }
        } else if (user_type == 'G' || user_type == 'g') {
            if (permit == 'Y' || permit == 'y') {
                if (arriving_source == 'C' || arriving_source == 'c') {
                    printf("Guest with valid permit can park in Zone C.\n");
                } else if (arriving_source == 'B' || arriving_source == 'b') {
                    printf("Guest with valid permit can park in Zone C.\n");
                } else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'Y' || space_available == 'y')) {
                    printf("Guest with valid permit can park in Zone C.\n");
                }
                else if ((arriving_source == 'V' || arriving_source == 'v') && (space_available == 'N' || space_available == 'n')) {
                    printf("No space available for Van in Zone C. Proceed with other options.\n");
                    printf("Is there space available in any Zone? (Y/N): ");
                    scanf(" %c", &space_available);
                    if ((space_available == 'Y' || space_available == 'y') && space_free == 2) {
                        printf("Space available in Zone C.\n");
                    } else {
                        printf("No space available in Zone C. Not allowed to park.\n");
                    }
                }
                else 
                {
                    printf("Invalid arriving source.\n");
                }

            } else {
                printf("Guest without valid permit cannot enter.\n");
            }
        } else {
            printf("Invalid user type.\n");
        }
    } 
    else if ((emergency_vehicle == 'Y' || emergency_vehicle == 'y') && (user_type == 'F' || user_type == 'f')) {
        printf("Emergency vehicle can park in Zone A.\n");
    }
    else if ((emergency_vehicle == 'Y' || emergency_vehicle == 'y') && (user_type == 'S' || user_type == 's')) {
        printf("Emergency vehicle can park in Zone B.\n");
    }
    else if ((emergency_vehicle == 'Y' || emergency_vehicle == 'y') && (user_type == 'G' || user_type == 'g')) {
        printf("Emergency vehicle can park in Zone C.\n");
    }
    else {
        printf("Invalid input.\n");
    }

    return 0;
}