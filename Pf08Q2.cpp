#include <stdio.h>

int main() {
    float marks[4][3];
    char *subjects[] = {"Programming", "Calculus", "Physics"};
    float studentTotal[4] = {0};
    float studentAvg[4] = {0};
    float subTotal[3] = {0};
    float subAvg[3] = {0};
    
    // 1 & 2. Read marks with validation
    printf("Enter Marks: \n")
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            while (1) {
                scanf("%f", &marks[i][j]);
                if (marks[i][j] >= 0 && marks[i][j] <= 100) {
                    break;
                }
                printf("Invalid mark! Enter a value between 0 and 100.\n");
            }
        }
    }

    // 3. Row-wise calculations (Total and Average)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            studentTotal[i] += marks[i][j];
        }
        studentAvg[i] = studentTotal[i] / 3.0;
    }

    // 4. Column-wise calculations (Highest, Lowest, Average)
    float highest[3], lowest[3];
    for (int j = 0; j < 3; j++) {
        highest[j] = marks[0][j];
        lowest[j] = marks[0][j];
        for (int i = 0; i < 4; i++) {
            if (marks[i][j] > highest[j]) highest[j] = marks[i][j];
            if (marks[i][j] < lowest[j]) lowest[j] = marks[i][j];
            subTotal[j] += marks[i][j];
        }
        subAvg[j] = subTotal[j] / 4.0;
    }

    // Print table header and student results
    printf("\nStudent     Prog    Calc    Phys   Total   Average  Grade\n");
    for (int i = 0; i < 4; i++) {
        char grade;
        if (studentAvg[i] >= 80) grade = 'A';
        else if (studentAvg[i] >= 65) grade = 'B';
        else if (studentAvg[i] >= 50) grade = 'C';
        else grade = 'F';

        printf("Student %d  ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%7.0f ", marks[i][j]);
        }
        printf("%7.0f %8.2f    %c\n", studentTotal[i], studentAvg[i], grade);
    }

    // Print subject statistics
    printf("\nSubject statistics:\n");
    printf("Subject        Highest    Lowest   Average\n");
    for (int j = 0; j < 3; j++) {
        printf("%-12s   %7.0f   %7.0f   %8.2f\n", subjects[j], highest[j], lowest[j], subAvg[j]);
    }

    // 5. Top student and worst subject
    int topStudent = 0;
    for (int i = 1; i < 4; i++) {
        if (studentAvg[i] > studentAvg[topStudent]) {
            topStudent = i;
        }
    }

    int worstSub = 0;
    for (int j = 1; j < 3; j++) {
        if (subAvg[j] < subAvg[worstSub]) {
            worstSub = j;
        }
    }

    printf("\nTop student: Student %d (Average %.2f)\n", topStudent + 1, studentAvg[topStudent]);
    printf("Worst subject: %s (Average %.2f)\n", subjects[worstSub], subAvg[worstSub]);

    return 0;
}
