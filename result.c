/*
 *NAME:ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION:PROGRAM TO READ STUDENT RECORDS FROM THE STRUCTURED FILE ,DISPLAY NAMES AND MARKS ON THE SCREEN
 */
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char regNo[20];
    float marks;
};

int main() {
    FILE *file;
    struct Student s;
    int choice;

    // Step 1: Write records to binary file
    file = fopen("results.dat", "ab"); // append binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter student details (enter 0 to stop):\n");
    while (1) {
        printf("\nEnter 1 to add student or 0 to stop: ");
        scanf("%d", &choice);
        if (choice == 0) break;

        printf("Name: ");
        getchar(); // clear input buffer
        fgets(s.name, sizeof(s.name), stdin);
        printf("Registration No: ");
        fgets(s.regNo, sizeof(s.regNo), stdin);
        printf("Total Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(s), 1, file);
        printf("✅ Record saved successfully!\n");
    }
    fclose(file);

    // Step 2: Read and display records
    file = fopen("results.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    printf("\n--- Student Results ---\n");
    while (fread(&s, sizeof(s), 1, file)) {
        printf("Name: %s", s.name);
        printf("Reg No: %s", s.regNo);
        printf("Marks: %.2f\n", s.marks);
        printf("----------------------\n");
    }

    fclose(file);
    return 0;
}
