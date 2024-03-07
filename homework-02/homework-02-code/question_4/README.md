# Gaussian Elimination and LU Decomposition with Complete Pivoting

## Steps to run the code

1. Compile the c code using the following command:

   ```bash
   gcc matrix.c -0 matrix -lm
   ```

   and

   ```bash
   gcc gecp.c -0 gecp -lm
   ```

2. Make the matrix A using the following command:

   ```bash
   ./matrix > {n}matrixA.txt
   ```

   where n is the size of the matrix. It will create a file with the name {n}matrixA.txt containing the matrix A.

3. Perform Gaussian Elimination with Complete Pivoting using the following command:

   ```bash
   ./gecp > {n}matrixU.txt
   ```

   where n is the size of the matrix. It will create a file with the name {n}matrixU.txt containing the matrix U.
