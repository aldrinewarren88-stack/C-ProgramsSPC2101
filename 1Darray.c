/*NAME:ALDRINE WARREN
 *REG NO:PA106/G/28818/25
 *DESCRIPTION : PROGRAM TO CALCULATE TOTAL TOTAL WEEKLY REVENUE AND AVERAGE DAILY REVENUE
*/


#include <stdio.h>// printf(),scanf()

#define DAYS_IN_WEEK 7
//main function
int main() {
    double revenue[DAYS_IN_WEEK];
    double totalRevenue = 0.0, averageRevenue;
    int i;

    printf(" Hotel Weekly Revenue Tracker\n\n");



    // Inputing the revenue for each day
    for(i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Enter revenue for day %d: $", i + 1);
        scanf("%lf", &revenue[i]);
        totalRevenue += revenue[i];//totalRevenue=totalRevenue +revenue
    }



    // Calculate average daily revenue
    averageRevenue = totalRevenue / DAYS_IN_WEEK;

    // Display results
    printf("\n Weekly Revenue Report \n");
    printf("Daily Revenues:\n");
    for(i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Day %d: $%.2lf\n", i + 1, revenue[i]);
    }


    //Displaying totalRevenue and averageRevenue

    printf("\nTotal Weekly Revenue: $%.2lf\n", totalRevenue);
    printf("Average Daily Revenue: $%.2lf\n", averageRevenue);

    return 0;
}