/* GAUSSIAN ELIMINATION WITH COMPLETE PIVOTING
author: Hidir Yuzuguzel
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// swap function swaps two number
void swap(float *i, float *j)
{
    float temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
// swapOrder function swaps two integers
void swapOrder(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
int main(int argc, char *argv[])
{
    // print something
    printf("Gaussian Elimination with Complete Pivoting\n");
    FILE *infile1;
    int row = 0, column = 0, n, i = 0, j = 0, k = 0, l = 0, tempi = 0, tempj = 0, t = 0, N_add = 0, N_mult = 0;
    float element, pivot, multip, multip2, c;
    float *arr1, *arr2, *x;
    int *order;
    char ch;

    // print the file name
    printf("The file name is: %s\n", argv[1]);

    infile1 = fopen(argv[1], "r");
    // The loop determines the number of items in the given matrix
    while (fscanf(infile1, "%f", &c) != EOF)
    {
        column++;
    }

    fclose(infile1);
    // fclose(infile2);
    column = sqrt(column);
    row = column;
    n = row * column;

    arr1 = (float *)malloc(n * sizeof(float));
    x = (float *)malloc(n * sizeof(float));
    arr2 = (float *)malloc(row * sizeof(float));
    order = (int *)malloc(row * sizeof(int));
    // The loop equates the element with index
    for (i = 0; i < row; i++)
    {
        order[i] = i;
    }
    infile1 = fopen(argv[1], "r");
    i = 0;
    // The loop reads the elements of the given matrix into the array arr1
    while (fscanf(infile1, "%f", &element) != EOF)
    {
        arr1[i] = element;
        i++;
    }

    // print the given matrix
    // for (i = 0; i < row; i++)
    // {
    //     for (j = 0; j < column; j++)
    //     {
    //         printf("%f ", arr1[i * row + j]);
    //     }
    //     printf("\n");
    // }

    i = 0;
    // The three for loop makes the given matrix Uppertriangular
    for (k = 0; k < row - 1; k++)
    {
        element = arr1[column * k + k];
        tempi = k;
        tempj = k;
        for (i = k; i < column; i++)
        {
            for (j = k; j < row; j++)
            {
                if (abs(arr1[column * i + j]) > abs(element))
                {
                    element = arr1[column * i + j];
                    tempi = i;
                    tempj = j;
                }
            }
        }

        // The loop makes row exchange
        for (l = 0; l < column; l++)
        {
            swap(&(arr1[column * tempi + l]), &(arr1[column * k + l]));
        }
        swap(&(arr2[tempi]), &(arr2[k]));
        // The loop makes column exchange
        for (l = 0; l < row; l++)
        {
            swap(&(arr1[column * l + tempj]), &(arr1[column * l + k]));
        }
        swapOrder(&(order[tempj]), &(order[k]));
        pivot = arr1[column * k + k];
        for (t = k + 1; t < row; t++)
        {
            multip = arr1[column * t + k] / arr1[column * k + k];
            N_mult++;
            for (j = k; j < column; j++)
            {
                arr1[column * t + j] = arr1[column * t + j] - multip * arr1[column * k + j];
                N_add++;
                N_mult++;
            }
            arr2[t] -= multip * arr2[k];
            N_add++;
            N_mult++;
        }
    }

    // print the upper triangular matrix
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%f ", arr1[i * row + j]);
        }
        printf("\n");
    }

    // The loop makes back substitution
    // for (j = row - 1; j >= 0; j--)
    // {
    //     // The if controls the singularity condition
    //     if (arr1[j * row + j] == 0)
    //     {
    //         printf("The matrix is singular!");
    //         system("PAUSE");
    //         return -1;
    //     }
    //     x[(order[j])] = arr2[j] / arr1[j * row + j];
    //     N_mult++;
    //     for (i = 0; i < j; i++)
    //     {
    //         arr2[i] -= arr1[i * row + j] * x[(order[j])];
    //         N_add++;
    //         N_mult++;
    //     }
    // }

    fclose(infile1);

    return 0;
}