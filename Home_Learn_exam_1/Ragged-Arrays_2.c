#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Allocate memory for the array of pointers to integer arrays
    int **raggedArray = (int **)malloc(rows * sizeof(int *));
    
    // Read the number of columns for each row and allocate memory accordingly
    for (int i = 0; i < rows; i++) {
        int columns;
        printf("Enter the number of columns for row %d: ", i+1);
        scanf("%d", &columns);

        raggedArray[i] = (int *)malloc(columns * sizeof(int));
        
        // Read the elements for each row
        printf("Enter the elements for row %d: ", i+1);
        for (int j = 0; j < columns; j++) {
            scanf("%d", &raggedArray[i][j]);
        }
    }

    // Display the elements of the ragged array
    printf("\nElements in the ragged array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizeof(raggedArray[i]) / sizeof(int); j++) {
            printf("%d ", raggedArray[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for the ragged array
    for (int i = 0; i < rows; i++) {
        free(raggedArray[i]);
    }
    free(raggedArray);

    return 0;
}
