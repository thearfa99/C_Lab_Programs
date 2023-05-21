/*

Matrix multiplication

Write a C program to multiply two matrices.
Implement the below functions:
void readMatrix(int m,int n,int a[][n]);
void displayMatrix(int m,int n,int a[][n]);
void multiplyMatrix(int m,int n,int p,int q,int a[m][n],int b[p][q],int c[m][q]);

Input Format:
First line: m n --> order of matrix 1 separated by space
Second line: p q --> order of matrix 2 separated by space
Third line: m*n integers of matrix 1 separated by space
Fourth line: p*q integers of matrix 2 separated by space

Output Format:
If n != p, message: Matrix multiplication is not possible
If n == p, matrix of order m x q in matrix format

Testcase

Input:
2 2
2 2
1 2 3 4
1 2 3 4

Output:
7 10 
15 22

*/

//Solution:
#include <stdio.h>

void readMatrix(int m, int n, int a[][n]) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int m, int n, int a[][n]) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int m, int n, int p, int q, int a[m][n], int b[p][q], int c[m][q]) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n, p, q;
    scanf("%d %d", &m, &n);
    scanf("%d %d", &p, &q);
    if (n != p) {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }
    int a[m][n], b[p][q], c[m][q];
    readMatrix(m, n, a);
    readMatrix(p, q, b);
    multiplyMatrix(m, n, p, q, a, b, c);
    displayMatrix(m, q, c);
    return 0;
}