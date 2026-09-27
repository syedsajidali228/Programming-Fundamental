/*
    Programming Fundamentals Theory 
    Question 6 Part B
    Syed Sajid Ali
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i;
    for (i = 1; i <= 5; i++) {     
        char vehicle_type, membership, disabled_priority, station_available;
        int battery_level, required_charging_level, parking_duration, current_time;
        printf("Enter vehicle type (E for Electric, H for Hybrid): ");
        scanf(" %c", &vehicle_type);
        vehicle_type = toupper(vehicle_type);
        printf("Enter battery charge level (%%): ");
        scanf("%d", &battery_level);
        printf("Enter required charging level (%%): ");
        scanf("%d", &required_charging_level);
        printf("Enter expected parking duration (hours): ");
        scanf("%d", &parking_duration);
        printf("Enter current time (24-hour format, e.g., 14 for 2 PM): ");
        scanf("%d", &current_time);
        printf("Enter parking membership (Y/N): ");
        scanf(" %c", &membership);
        membership = toupper(membership);
        printf("Enter disabled-person priority status (Y/N): ");
        scanf(" %c", &disabled_priority);
        disabled_priority = toupper(disabled_priority);
        printf("Enter charging station availability (Y/N): ");
        scanf(" %c", &station_available);
        station_available = toupper(station_available);
        double charging_cost = 0.0;
        double parking_cost = 0.0;


        double charging_discount = 0.0;
        double parking_discount = 0.0;
        double final_amount = 0.0;
        char charging_priority[50] = "N/A";
        char peak_status[20] = "Off-peak";
        char message[300] = "";


        if (current_time >= 17 && current_time <= 22) {
            strcpy(peak_status, "Peak");
        } else {
            strcpy(peak_status, "Off-peak");
        }


        if (station_available == 'N') {
            if (vehicle_type == 'H') {
                strcat(message, "Charging unavailable – Parking only. ");
            } else {
                strcat(message, "No charging slot available. ");
            }
        } 
        else {
            int qualifies = 0;
            if (vehicle_type == 'E') {
                qualifies = 1;
            } 
            else if (vehicle_type == 'H') {
                if (battery_level < 40) {
                    qualifies = 1;
                } 
                else {
                    strcat(message, "Vehicle does not qualify for EV charging. ");
                }
            } 
            else {
                strcat(message, "Invalid vehicle type. ");
            }
            


            if (qualifies) {
                int required_charging = required_charging_level - battery_level;
                if (required_charging <= 0) {
                    strcat(message, "No charging required. ");
                } 
                else {
                    if (battery_level <= 15 && required_charging_level >= 80) {
                        strcpy(charging_priority, "Emergency Charging Priority");
                    } 
                    
                    else if ((disabled_priority == 'Y') || 
                               (membership == 'Y' && battery_level <= 30)) {
                        strcpy(charging_priority, "Priority Charging");
                    } 
                    else {
                        strcpy(charging_priority, "Normal Charging");
                    }
                    double rate = (strcmp(peak_status, "Peak") == 0) ? 50.0 : 35.0;
                    double charging_cost_before_discount = required_charging * rate;
                    
                    // Apply membership discount (not for Emergency Charging)
                    if (strcmp(charging_priority, "Emergency Charging Priority") != 0) {
                        if (membership == 'Y') {
                            if (strcmp(peak_status, "Off-peak") == 0) {
                                charging_discount = charging_cost_before_discount * 0.20;
                            } else {
                                charging_discount = charging_cost_before_discount * 0.10;
                                }
                    }
                    }
                    charging_cost = charging_cost_before_discount - charging_discount;
                        }
        }
        }
 
        if (parking_duration <= 2) {
            parking_cost = 200.0;
        } 
        else if (parking_duration <= 5) {
            parking_cost = 400.0;
        } 
        else {
            parking_cost = 700.0;
        }

        if (disabled_priority == 'Y') {
            parking_discount = parking_cost;
        } 
        else {
            parking_discount = 0.0;
        }
        parking_cost = parking_cost - parking_discount;
        if (parking_duration > 8) {
            strcat(message, "Long-stay warning: Please relocate your vehicle after charging. ");
        } 
        else {
            strcat(message, "Standard parking duration. ");
        }




        final_amount = charging_cost + parking_cost;

        double total_discount = charging_discount + parking_discount;

        printf("Vehicle Type: %c\n", vehicle_type);
        printf("Current Battery Percentage: %d%%\n", battery_level);
        printf("Required Charging Percentage: %d%%\n", required_charging_level);
        printf("Charging Priority: %s\n", charging_priority);
        printf("Peak/Off-peak Status: %s\n", peak_status);
        printf("Charging Cost: Rs. %.2f\n", charging_cost);
        printf("Parking Cost: Rs. %.2f\n", parking_cost);
        printf("Total Discount: Rs. %.2f\n", total_discount);
        printf("Final Payable Amount: Rs. %.2f\n", final_amount);
        printf("Message: %s\n", message);
    }
    


    return 0;
}