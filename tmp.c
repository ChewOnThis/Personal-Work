#include <stdio.h>
#include <cs50.h>

int main() {
    // Prompt user for temperature reading
    float temp = get_float("Enter a temperature to convert: ");

    // Prompt user for unit of measurement
    int unit = get_int("Enter 1 to convert from Celsius to Fahrenheit or 0 for Fahrenheit to Celsius: ");

    // Perform conversion based on user input
    if (unit == 1) {
        // Convert Celsius to Fahrenheit
        float fahrenheit = (9.0 / 5.0) * temp + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temp, fahrenheit);
    } else if (unit == 0) {
        // Convert Fahrenheit to Celsius
        float celsius = (5.0 / 9.0) * (temp - 32);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temp, celsius);
    } else {
        // Invalid input
        printf("Invalid unit entered. Please enter 0 or 1.\n");
    }

    return 0;
}
