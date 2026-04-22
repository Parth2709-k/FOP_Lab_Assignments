#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** allocMatrix(int rows, int cols)
{
    double** mat = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++)
        mat[i] = (double*)calloc(cols, sizeof(double));
    return mat;
}

void freeMatrix(double** mat, int rows)
{
    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
}

void printMatrix(double** mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%10.4f ", mat[i][j]);
        printf("\n");
    }
}

void inputMatrix(double** mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            printf("  [%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
}

double** AddMatrix(double** A, double** B, int rows, int cols)
{
    double** result = allocMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

void SaddlePoint(double** mat, int rows, int cols)
{
    int f = 0;
    for (int i = 0; i < rows; i++)
    {
        // Finding the minimum element from the row
        double rowMin = mat[i][0];
        for (int j = 1; j < cols; j++)
            if (mat[i][j] < rowMin)
            rowMin = mat[i][j];

        // Checking each position that equals row min
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] != rowMin) continue;

            // Check if it is also the column maximum
            double colMax = mat[0][j];
            for (int k = 1; k < rows; k++)
                if (mat[k][j] > colMax) colMax = mat[k][j];

            if (mat[i][j] == colMax)
            {
                printf("  Saddle point at [%d][%d] = %.4f\n", i, j, mat[i][j]);
                f = 1;
            }
        }
    }
    if (!f)
        printf("  No saddle point exists in this matrix.\n");
}


double** copyMatrix(double** src, int n)
{
    double** dst = allocMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dst[i][j] = src[i][j];
    return dst;
}

double** inverseMatrix(double** A, int n)
{
    //Making augmented matrix 
    double** aug = allocMatrix(n, 2 * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            aug[i][j] = A[i][j];
        aug[i][i + n] = 1.0;   // identity block
    }

    //We will now perform forward elmination using partial pivoting
    for (int col = 0; col < n; col++) {
        //Finding the pivot row
        int pivot = col;
        for (int row = col + 1; row < n; row++)
            if (fabs(aug[row][col]) > fabs(aug[pivot][col]))
                pivot = row;

        //Now, Swap the rows
        double* tmp = aug[col];
        aug[col] = aug[pivot];
        aug[pivot] = tmp;

        if (fabs(aug[col][col]) < 1e-9) {
            printf(" Singular Matrix:-  inverse does not exist \n");
            freeMatrix(aug, n);
            return NULL;
        }

        double divisor = aug[col][col];
        for (int j = 0; j < 2 * n; j++)
            aug[col][j] /= divisor;

        for (int row = 0; row < n; row++)
        {
            if (row == col) continue;
            double factor = aug[row][col];
            for (int j = 0; j < 2 * n; j++)
                aug[row][j] -= factor * aug[col][j];
        }
    }

    //Extracting the right half ,i.e, The inverse
    double** inv = allocMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = aug[i][j + n];

    freeMatrix(aug, n);
    return inv;
}

void MagicSquare(int n)
{
    if (n % 2 == 0)
    {
        printf("  Magic square can only be done for odd n\n");
        return;
    }
    
    if (n < 1)
    {
        printf("  n must be a positive odd integer.\n");
        return;
    }

    double** ms = allocMatrix(n, n);   // calloc already zeros it

    int row = 0, col = n / 2;
    for (int num = 1; num <= n * n; num++)
    {
        ms[row][col] = num;
        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;
        if (ms[newRow][newCol] != 0)
        {
            //Cell is getting occupied, instead we move straight down
            row = (row + 1) % n;
        }
        else 
        {
            row = newRow;
            col = newCol;
        }
    }

    printf("  Magic Square of order %d:\n", n);
    printMatrix(ms, n, n);
    printf("  Magic constant = %d\n", n * (n * n + 1) / 2);
    freeMatrix(ms, n);
}

int main()
{
    int choice;

    printf("----------------------------------------\n");
    printf("      MATRIX OPERATIONS PROGRAM       \n");
    printf("----------------------------------------\n");

    do {
        printf("\n--- MENU -----------------------------\n");
        printf("  1. Addition of matrix\n");
        printf("  2. Saddle Point\n");
        printf("  3. Inverse of Matrix\n");
        printf("  4. Magic Square\n");
        printf("  0. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
            {
                int r, c;
                printf("\nEnter dimensions (rows cols): ");
                scanf("%d %d", &r, &c);

                double** A = allocMatrix(r, c);
                double** B = allocMatrix(r, c);

                printf("Enter Matrix A:\n");
                inputMatrix(A, r, c);
                printf("Enter Matrix B:\n");
                inputMatrix(B, r, c);

                double** sum = AddMatrix(A, B, r, c);

                printf("\nMatrix A:\n");       printMatrix(A,   r, c);
                printf("Matrix B:\n");         printMatrix(B,   r, c);
                printf("A + B:\n");            printMatrix(sum, r, c);

                freeMatrix(A, r);
                freeMatrix(B, r);
                freeMatrix(sum, r);
                break;
            }

            case 2:
            {
                int r, c;
                printf("\nEnter dimensions (rows cols): ");
                scanf("%d %d", &r, &c);

                double** A = allocMatrix(r, c);
                printf("Enter Matrix:\n");
                inputMatrix(A, r, c);

                printf("\nMatrix:\n");
                printMatrix(A, r, c);
                printf("\nSaddle Point:\n");
                SaddlePoint(A, r, c);

                freeMatrix(A, r);
                break;
            }

            case 3: 
            {
                int n;
                printf("\nEnter order of square matrix (n): ");
                scanf("%d", &n);

                double** A = allocMatrix(n, n);
                printf("Enter Matrix:\n");
                inputMatrix(A, n, n);

                printf("\nMatrix A:\n");
                printMatrix(A, n, n);

                double** inv = inverseMatrix(A, n);
                if (inv)
                {
                    printf("\nInverse of A:\n");
                    printMatrix(inv, n, n);
                    freeMatrix(inv, n);
                }

                freeMatrix(A, n);
                break;
            }

            case 4:
            {
                int n;
                printf("\nEnter odd order for magic square: ");
                scanf("%d", &n);
                printf("\n");
                MagicSquare(n);
                break;
            }

            case 0:
                printf("Exited\n");
                break;

            default:
                printf("Invalid choice\n");
            }

    } while (choice != 0);

    return 0;
}

