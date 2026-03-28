#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = NULL;

    if (rows <= 0 || cols <= 0) {
        m.rows = 0;
        m.cols = 0;
        return m;
    }

    m.data = (double **)malloc(rows * sizeof(double *));
    if (m.data == NULL) {
        m.rows = 0;
        m.cols = 0;
        return m;
    }

    for (int i = 0; i < rows; i++) {
        m.data[i] = (double *)calloc(cols, sizeof(double));
        if (m.data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m.data[j]);
            }
            free(m.data);
            m.data = NULL;
            m.rows = 0;
            m.cols = 0;
            return m;
        }
    }

    return m;
}

void free_matrix(Matrix *m) {
    if (m->data != NULL) {
        for (int i = 0; i < m->rows; i++) {
            free(m->data[i]);
        }
        free(m->data);
        m->data = NULL;
    }

    m->rows = 0;
    m->cols = 0;
}

void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

int add_matrices(const Matrix *a, const Matrix *b, Matrix *result) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return 0;
    }

    if (result->rows != a->rows || result->cols != a->cols) {
        return 0;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return 1;
}

int multiply_matrices(const Matrix *a, const Matrix *b, Matrix *result) {
    if (a->cols != b->rows) {
        return 0;
    }

    if (result->rows != a->rows || result->cols != b->cols) {
        return 0;
    }

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = 0.0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return 1;
}

int transpose_matrix(const Matrix *m, Matrix *result) {
    if (result->rows != m->cols || result->cols != m->rows) {
        return 0;
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }

    return 1;
}

double determinant_2x2(const Matrix *m) {
    if (m->rows != 2 || m->cols != 2) {
        return 0.0;
    }

    return m->data[0][0] * m->data[1][1] - m->data[0][1] * m->data[1][0];
}