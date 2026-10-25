#include <stdio.h>

int main() {
    int image[4][4];
    int result[4][4];
    int brightness_amount, threshold;

    // 1. Prompt and read 16 pixel values for the 4x4 image
    printf("Enter 16 pixel values for the 4x4 image (row by row, 0-255):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter pixel [%d][%d]: ", i, j);
            scanf("%d", &image[i][j]);
        }
    }

    // Prompt and read brightness amount and threshold value
    printf("Enter brightness amount (can be positive or negative): ");
    scanf("%d", &brightness_amount);

    printf("Enter threshold value (0-255): ");
    scanf("%d", &threshold);

    // 7. Print Original Image
    printf("\nOriginal image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }

    // 2. Brightness Edit: add amount, clamp between 0 and 255
    printf("\nBrightness (%+d):\n", brightness_amount);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = image[i][j] + brightness_amount;
            if (val > 255) val = 255;
            if (val < 0) val = 0;
            printf("%4d ", val);
        }
        printf("\n");
    }

    // 3. Black and White Edit: threshold logic
    printf("\nBlack and white (threshold %d):\n", threshold);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = (image[i][j] >= threshold) ? 255 : 0;
            printf("%4d ", val);
        }
        printf("\n");
    }

    // 4. Flip Horizontally Edit: reverse each row
    printf("\nFlipped horizontally:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Border pixels stay unchanged
            if (i == 0 || i == 3 || j == 0 || j == 3) {
                result[i][j] = image[i][j];
            } else {

                int sum = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        sum += image[i + di][j + dj];
                    }
                }
                result[i][j] = sum / 9;
            }
        }
    }


    printf("\nSmoothed image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
