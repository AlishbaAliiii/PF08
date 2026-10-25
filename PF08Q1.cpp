#include <stdio.h>

#define ROWS 5
#define COLS 6

int main() {
    int seats[ROWS][COLS] = {0};   // 0 = empty, 1 = booked
    int row, col;
    int totalBooked = 0, totalEmpty = 0;
    int maxBooked = -1, maxRow = 0;

    
    while (1) {
        printf("Enter row (1-%d, -1 to stop): ", ROWS);
        scanf("%d", &row);
        if (row == -1) {
            break;
        }
        printf("Enter column (1-%d): ", COLS);
        scanf("%d", &col);

        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Error: Invalid row or column!\n");
        } else if (seats[row - 1][col - 1] == 1) {
            printf("Error: Seat already booked!\n");
        } else {
            seats[row - 1][col - 1] = 1;
            printf("Seat booked successfully.\n");
        }
    }

  
    printf("\nSeating Chart:\n");
    printf("      ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        int rowBooked = 0;
        printf("Row %d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 1) {
                printf("X ");
                rowBooked++;
            } else {
                printf("O ");
            }
        }
        printf("\n");

        totalBooked += rowBooked;
        if (rowBooked > maxBooked) {   //  keeps the FIRST row on a tie
            maxBooked = rowBooked;
            maxRow = i + 1;
        }
    }

    totalEmpty = ROWS * COLS - totalBooked;

    printf("\nTotal booked seats: %d\n", totalBooked);
    printf("Total empty seats: %d\n", totalEmpty);
    printf("Row with most bookings: Row %d\n", maxRow);

    return 0;
}
