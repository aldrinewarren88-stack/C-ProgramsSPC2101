/*
 *NAME:ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION:PROGRAM TO DISPLAY THE TOTAL NUMBER OF OCCUPIED ROOMS ACROSS ALL BRANCHES
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//define the functions
#define BRANCHES 3
#define FLOORS 5
#define ROOMS_PER_FLOOR 10
//main function
int main() {
    // 3D array to represent the hotel chain
    int chain[BRANCHES][FLOORS][ROOMS_PER_FLOOR];

    // Initialize random seed
    srand(time(NULL));

    // Assign random occupancy (1 or 0) to each room
    for (int branch = 0; branch < BRANCHES; branch++) {
        for (int floor = 0; floor < FLOORS; floor++) {
            for (int room = 0; room < ROOMS_PER_FLOOR; room++) {
                chain[branch][floor][room] = rand() % 2; // 0 or 1
            }
        }
    }

    // Calculate total number of occupied rooms
    int totalOccupied = 0;
    for (int branch = 0; branch < BRANCHES; branch++) {
        for (int floor = 0; floor < FLOORS; floor++) {
            for (int room = 0; room < ROOMS_PER_FLOOR; room++) {
                if (chain[branch][floor][room] == 1) {
                    totalOccupied++;
                }
            }
        }
    }

    // Display the total number of occupied rooms
    printf("Hotel Chain Occupancy Report\n");
    printf("============================\n");
    printf("Branches: %d\n", BRANCHES);
    printf("Floors per branch: %d\n", FLOORS);
    printf("Rooms per floor: %d\n", ROOMS_PER_FLOOR);
    printf("Total rooms in chain: %d\n", BRANCHES * FLOORS * ROOMS_PER_FLOOR);
    printf("\nTotal occupied rooms across all branches: %d\n", totalOccupied);

    // Optional: Display occupancy by branch
    printf("\nOccupancy by branch:\n");
    for (int branch = 0; branch < BRANCHES; branch++) {
        int branchOccupied = 0;
        for (int floor = 0; floor < FLOORS; floor++) {
            for (int room = 0; room < ROOMS_PER_FLOOR; room++) {
                if (chain[branch][floor][room] == 1) {
                    branchOccupied++;
                }
            }
        }
        printf("Branch %d: %d occupied rooms\n", branch + 1, branchOccupied);
    }

    return 0;
}