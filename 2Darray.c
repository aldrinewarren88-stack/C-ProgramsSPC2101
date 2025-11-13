/*
 *NAME:ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION:PROGRAM TO INPUT RANDOM ROOM OCCUPANCY (SIMULATE INPUT),AND TO DISPLAY THE NUMBER OF OCCUPIED AND VACANT ROOMS PER FLOOR
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 5
#define ROOMS_PER_FLOOR 10

void initializeOccupancy(int occupancy[FLOORS][ROOMS_PER_FLOOR]) {


    //To bring conclusuvity, Seed the random number generator
    srand(time(NULL));

    // Fill the array with random occupancy data (0 or 1)
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            occupancy[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}

void displayOccupancy(int occupancy[FLOORS][ROOMS_PER_FLOOR]) {
    printf("\n ROOM OCCUPANCY STATUS \n");
    printf("Floor | Room Status (1=Occupied, 0=Vacant)\n");
    printf("------|----------------------------------\n");

    for (int i = 0; i < FLOORS; i++) {
        printf("%5d | ", i + 1);
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            printf("%d ", occupancy[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void calculateStatistics(int occupancy[FLOORS][ROOMS_PER_FLOOR]) {
    printf("\n OCCUPANCY STATISTICS PER FLOOR \n");
    printf("Floor | Occupied | Vacant | Total\n");
    printf("------|----------|--------|------\n");

    int totalOccupied = 0;
    int totalVacant = 0;

    for (int i = 0; i < FLOORS; i++) {
        int occupiedCount = 0;
        int vacantCount = 0;

        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (occupancy[i][j] == 1) {
                occupiedCount++;
            } else {
                vacantCount++;
            }
        }

        totalOccupied += occupiedCount;
        totalVacant += vacantCount;

        printf("%5d | %8d | %6d | %5d\n",
               i + 1, occupiedCount, vacantCount, ROOMS_PER_FLOOR);
    }

    printf("------|----------|--------|------\n");
    printf("TOTAL | %8d | %6d | %5d\n",
           totalOccupied, totalVacant, FLOORS * ROOMS_PER_FLOOR);
}

void displayFloorDetails(int occupancy[FLOORS][ROOMS_PER_FLOOR]) {
    printf("\n=== DETAILED FLOOR INFORMATION ===\n");

    for (int i = 0; i < FLOORS; i++) {
        printf("\nFloor %d:\n", i + 1);
        printf("Occupied rooms: ");
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (occupancy[i][j] == 1) {
                printf("%d ", j + 1);
            }
        }

        printf("\nVacant rooms: ");
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (occupancy[i][j] == 0) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
}

int main() {
    int occupancy[FLOORS][ROOMS_PER_FLOOR];

    printf("=== HOTEL ROOM OCCUPANCY SYSTEM ===\n");
    printf("Branch has %d floors with %d rooms each\n\n", FLOORS, ROOMS_PER_FLOOR);

    // Initialize with random occupancy data
    initializeOccupancy(occupancy);

    // Display the occupancy matrix
    displayOccupancy(occupancy);

    // Calculate and display statistics
    calculateStatistics(occupancy);

    // Display detailed floor information
    displayFloorDetails(occupancy);

    return 0;
}