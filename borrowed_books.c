/*
*NAME:ALDRINE WARREN
*REG NO:PA106/G/28818/25
*DESCRIPTION:PROGRAM TO ALLOW LIBRARIAN TO ENTER BOOK TITLES , APPEND NEW TITLES ,DISPLAY A CONFIRMATION MESSAGE AFTER SAVING
 */
 #include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char title[100];

    file = fopen("borrowed_books.txt", "a");  // open in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter book title (type 'exit' to stop):\n");

    while (1) {
        printf("Book Title: ");
        fgets(title, sizeof(title), stdin);

        // check if user typed "exit"
        if (strncmp(title, "exit", 4) == 0)
            break;

        fprintf(file, "%s", title);
        printf("✅ Book title successfully stored!\n");
    }

    fclose(file);
    printf("\nAll book titles saved in borrowed_books.txt\n");

    return 0;
}
