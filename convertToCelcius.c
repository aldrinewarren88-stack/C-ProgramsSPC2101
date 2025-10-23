/*
 *NAME :ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION :PROGRAM TO CONVERT FAHRENHEIT TO CELSIUS USING C
 */
#include <stdio.h>

//main function
 int main() {

    //we use floats data type since degrees are in decimal values
    float celcius,fahrenheit;
    printf("Enter the temperature in Fahrenheit:\n");
    scanf("%f",&fahrenheit);

    // realisation of the formula c=(F-32)*5/9
    celcius = (fahrenheit - 32) * 5/9;

    //realisation of the output
    printf("The temperature in Celcius is %.2f\n",celcius);
    return 0;
}