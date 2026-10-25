#include <stdio.h>

int main() {
    // 1. Declare 3D array: 2 floors, 3 wards, 2 beds, initialized to 0 (vacant)
    int beds[2][3][2] = {0};
    int choice;

    while (1) {
        // 2. Menu display and choice prompt
        printf("\n--- Hospital Ward Management Menu ---\n");
        printf("1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Print Occupancy Report\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        if (choice == 1) {
            // 3. Admit: ask for floor and patient ID
            int floor, patientID;
            printf("Enter floor number (1 or 2): ");
            scanf("%d", &floor);
            printf("Enter patient ID: ");
            scanf("%d", &patientID);

            int fIdx = floor - 1;
            int admitted = 0;

            for (int w = 0; w < 3; w++) {
                for (int b = 0; b < 2; b++) {
                    if (beds[fIdx][w][b] == 0) {
                        beds[fIdx][w][b] = patientID;
                        printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n", 
                               patientID, floor, w + 1, b + 1);
                        admitted = 1;
                        break;
                    }
                }
                if (admitted) break;
            }

            if (!admitted) {
                printf("Floor %d is full.\n", floor);
            }
        } 
        else if (choice == 2) {
            // 4. Discharge: ask for patient ID
            int patientID;
            printf("Enter patient ID to discharge: ");
            scanf("%d", &patientID);

            int found = 0;
            for (int f = 0; f < 2; f++) {
                for (int w = 0; w < 3; w++) {
                    for (int b = 0; b < 2; b++) {
                        if (beds[f][w][b] == patientID) {
                            beds[f][w][b] = 0;
                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n", 
                                   patientID, f + 1, w + 1, b + 1);
                            found = 1;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }

            if (!found) {
                printf("Patient ID %d not found.\n", patientID);
            }
        } 
        else if (choice == 3) {
            // 5 & 6. Report: occupied and vacant beds per ward, floor occupancy percentage, and warnings
            printf("\n--- Occupancy Report ---\n");

            int maxOccupied = -1;
            int maxWardF = 0, maxWardW = 0;

            for (int f = 0; f < 2; f++) {
                printf("Floor %d\n", f + 1);
                int floorOccupied = 0;
                int totalBedsOnFloor = 6; // 3 wards * 2 beds

                for (int w = 0; w < 3; w++) {
                    int wardOccupied = 0;
                    for (int b = 0; b < 2; b++) {
                        if (beds[f][w][b] != 0) {
                            wardOccupied++;
                        }
                    }
                    int wardVacant = 2 - wardOccupied;
                    floorOccupied += wardOccupied;

                    printf("Ward %d: Occupied %d, Vacant %d\n", w + 1, wardOccupied, wardVacant);

                    // Track highest occupancy ward (first one if there is a tie)
                    if (wardOccupied > maxOccupied) {
                        maxOccupied = wardOccupied;
                        maxWardF = f + 1;
                        maxWardW = w + 1;
                    }
                }

                float floorPerc = ((float)floorOccupied / totalBedsOnFloor) * 100.0;
                printf("Floor occupancy: %.1f%%\n", floorPerc);

                if (floorPerc > 80.0) {
                    printf("WARNING: Floor %d is more than 80%% full.\n", f + 1);
                }
            }

            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n", maxWardF, maxWardW, maxOccupied);
        }
        else {
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
