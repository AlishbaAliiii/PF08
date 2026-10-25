#include <stdio.h>

int main() {
    int stock[3][4];
    
    // 1. Fill the 2D array with prompted values entered by the user
    printf("Enter the stock units for 3 aisles (4 shelf positions each):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter stock for Aisle %d, Position %d: ", i + 1, j + 1);
            scanf("%d", &stock[i][j]);
        }
    }

    // 2. Print the original grid
    printf("\nOriginal stock:\n");
    for (int i = 0; i < 3; i++) {
        printf("Aisle %d:", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%4d", stock[i][j]);
        }
        printf("\n");
    }

    // 3. Find the aisle with the greatest total stock
    int maxAisle = 0;
    int maxTotal = -1;
    for (int i = 0; i < 3; i++) {
        int aisleTotal = 0;
        for (int j = 0; j < 4; j++) {
            aisleTotal += stock[i][j];
        }
        if (aisleTotal > maxTotal) {
            maxTotal = aisleTotal;
            maxAisle = i;
        }
    }
    printf("\nAisle with most stock: Aisle %d (%d units)\n", maxAisle + 1, maxTotal);

    // 4 & 5. Low stock alerts and empty shelves count (< 5 units)
    printf("\nLow stock alerts:\n");
    int emptyShelves = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (stock[i][j] < 5) {
                printf("Aisle %d, Position %d -> %d units\n", i + 1, j + 1, stock[i][j]);
                if (stock[i][j] == 0) {
                    emptyShelves++;
                }
            }
        }
    }
    printf("\nEmpty shelves: %d\n", emptyShelves);

    // 6. Restock: add 10 units to every shelf with fewer than 5 units
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (stock[i][j] < 5) {
                stock[i][j] += 10;
            }
        }
    }

    // 7. Print grid after restocking and display new grand total
    printf("\nStock after restocking:\n");
    int grandTotal = 0;
    for (int i = 0; i < 3; i++) {
        printf("Aisle %d:", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%4d", stock[i][j]);
            grandTotal += stock[i][j];
        }
        printf("\n");
    }

    printf("\nNew grand total: %d units\n", grandTotal);

    return 0;
}
