// Programming Fundamental Theory

// Programmer Name: Syed Sajid Ali

// Question: 03

#include <stdio.h>

void input_readings ( int sensors, int hours, float temperatures[sensors][hours] ) {
    for (int sensor_index= 0; sensor_index < sensors; sensor_index++) {
        printf ( "Sensor %d: ", sensor_index + 1 );

        for (int hour_index= 0; hour_index < hours; hour_index++) {
            scanf ( "%f", &temperatures[sensor_index][hour_index] );
        }
    }
}

void analyze_sensor ( int hours, float readings[], int sensor_number, float *average_output ) {
    float total= 0;
    float maximum= readings[0];
    float minimum= readings[0];

    int critical_count= 0;
    int warning_count= 0;
    int current_streak= 0;
    int longest_streak= 0;

    for (int hour_index= 0; hour_index < hours; hour_index++) {
        float temperature= readings[hour_index];
        total += temperature;

        if (temperature > maximum) {
            maximum= temperature;
        }

        if (temperature < minimum) {
            minimum= temperature;
        }

        if (temperature >= 40.0) {
            critical_count++;
        }

        if (temperature >= 35.0 && temperature < 40.0) {
            warning_count++;
        }

        if (temperature >= 35.0) {
            current_streak++;

            if (current_streak > longest_streak) {
                longest_streak= current_streak;
            }
        }

        else {
            current_streak= 0;
        }
    }

    *average_output= total / hours;

    printf ( "Sensor %d: Total %.2f | Avg = %.2f | Max = %.0f | Min = %.0f | Critical = %d | Warning = %d | Hot streak = %d\n",
             sensor_number, total, *average_output, maximum, minimum,
             critical_count, warning_count, longest_streak );
}

int find_highest_average_sensor ( float averages[], int sensors ) {
    int best_index= 0;

    for (int sensor_index= 1; sensor_index < sensors; sensor_index++) {
        if (averages[sensor_index] > averages[best_index]) {
            best_index= sensor_index;
        }
    }

    return best_index + 1;
}

int main ( ) {
    int sensors, hours;

    printf ( "Enter number of sensors and hours: " );
    scanf ( "%d %d", &sensors, &hours );

    if (sensors <= 0 || hours <= 0) {
        printf ( "Invalid number of sensors or hours.\n" );
        return 0;
    }

    float temperatures[sensors][hours];

    printf ( "Enter temperature readings for each sensor:\n" );
    input_readings ( sensors, hours, temperatures );

    float averages[sensors];

    for (int sensor_index= 0; sensor_index < sensors; sensor_index++) {
        float average= 0;

        analyze_sensor ( hours, temperatures[sensor_index], sensor_index + 1, &average );
        averages[sensor_index]= average;
    }

    int best_sensor= find_highest_average_sensor ( averages, sensors );

    printf ( "Highest average: Sensor %d (%.2f)\n", best_sensor, averages[best_sensor - 1] );

    return 0;
}
