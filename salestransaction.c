/*
 *NAME:ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION:PROGRAM TO READ ALL TRANSACTIONS  LINE BY LINE ,CALCULATE TOTAL SALES ,ENSURE FILE CLOSES PROPERLY
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    float amount, total = 0;

    file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(file, "%f", &amount) == 1) {
        total += amount;
    }

    fclose(file);

    printf("✅ Total sales for the day: %.2f\n", total);
    printf("File closed successfully.\n");

    return 0;
}
