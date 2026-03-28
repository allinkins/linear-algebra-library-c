#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
void print_matrix(const Matrix *m);
int add_matrices(const Matrix *a, const Matrix *b, Matrix *result);
int multiply_matrices(const Matrix *a, const Matrix *b, Matrix *result);
int transpose_matrix(const Matrix *m, Matrix *result);
double determinant_2x2(const Matrix *m);

#endif