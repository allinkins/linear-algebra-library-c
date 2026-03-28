#include <stdlib.h>
#include <math.h>
#include "../include/slae.h"

#define EPS 1e-9

static void free_augmented_matrix(double **aug, int rows) {
    if (aug != NULL) {
        for (int i = 0; i < rows; i++) {
            free(aug[i]);
        }
        free(aug);
    }
}

static void swap_rows(double **aug, int row1, int row2) {
    double *temp = aug[row1];
    aug[row1] = aug[row2];
    aug[row2] = temp;
}

int solve_slae_gauss(const Matrix *A, const Vector *b, Vector *x) {
    if (A == NULL || b == NULL || x == NULL) {
        return 0;
    }

    if (A->rows != A->cols) {
        return 0;
    }

    int n = A->rows;

    if (b->size != n || x->size != n) {
        return 0;
    }

    double **aug = (double **)malloc(n * sizeof(double *));
    if (aug == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        aug[i] = (double *)malloc((n + 1) * sizeof(double));
        if (aug[i] == NULL) {
            free_augmented_matrix(aug, i);
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = A->data[i][j];
        }
        aug[i][n] = b->data[i];
    }

    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(aug[k][i]) > fabs(aug[max_row][i])) {
                max_row = k;
            }
        }

        if (fabs(aug[max_row][i]) < EPS) {
            free_augmented_matrix(aug, n);
            return 0;
        }

        if (max_row != i) {
            swap_rows(aug, i, max_row);
        }

        for (int k = i + 1; k < n; k++) {
            double factor = aug[k][i] / aug[i][i];
            for (int j = i; j <= n; j++) {
                aug[k][j] -= factor * aug[i][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = aug[i][n];

        for (int j = i + 1; j < n; j++) {
            sum -= aug[i][j] * x->data[j];
        }

        if (fabs(aug[i][i]) < EPS) {
            free_augmented_matrix(aug, n);
            return 0;
        }

        x->data[i] = sum / aug[i][i];
    }

    free_augmented_matrix(aug, n);
    return 1;
}