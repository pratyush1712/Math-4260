#include <stdio.h>

int main() {
    int n, i, j;

    // Ask the user for the size of the matrix
    // printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    // Declare the matrix
    int matrix[n][n];

    // Initialize and populate the matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // Rule 1: All diagonal elements are 1s
            if(i == j) {
                matrix[i][j] = 1;
            }
            // Rule 2: All elements below the diagonal are -1s
            else if(i > j) {
                matrix[i][j] = -1;
            }
            // Rule 3: Last column of the matrix is all 1s
            else if(j == n - 1) {
                matrix[i][j] = 1;
            }
            // Rule 4: All other elements are 0s
            else {
                matrix[i][j] = 0;
            }
        }
    }

    // Print the matrix
    // printf("Generated matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
