#include <stdio.h>
#include <math.h>
#include "../include/vector.h"
#include "../include/matrix.h"
#include "../include/slae.h"

#define EPS 1e-6

int double_equal(double a, double b) {
    return fabs(a - b) < EPS;
}

void test_add_vectors() {
    Vector a = create_vector(3);
    Vector b = create_vector(3);
    Vector result = create_vector(3);

    a.data[0] = 1; a.data[1] = 2; a.data[2] = 3;
    b.data[0] = 4; b.data[1] = 5; b.data[2] = 6;

    int ok = add_vectors(&a, &b, &result);

    if (ok &&
        double_equal(result.data[0], 5) &&
        double_equal(result.data[1], 7) &&
        double_equal(result.data[2], 9)) {
        printf("test_add_vectors: PASSED\n");
    } else {
        printf("test_add_vectors: FAILED\n");
    }

    free_vector(&a);
    free_vector(&b);
    free_vector(&result);
}

void test_scalar_multiply_vector() {
    Vector a = create_vector(3);
    Vector result = create_vector(3);

    a.data[0] = 1;
    a.data[1] = -2;
    a.data[2] = 3;

    int ok = scalar_multiply_vector(&a, 2.0, &result);

    if (ok &&
        double_equal(result.data[0], 2) &&
        double_equal(result.data[1], -4) &&
        double_equal(result.data[2], 6)) {
        printf("test_scalar_multiply_vector: PASSED\n");
    } else {
        printf("test_scalar_multiply_vector: FAILED\n");
    }

    free_vector(&a);
    free_vector(&result);
}

void test_dot_product() {
    Vector a = create_vector(3);
    Vector b = create_vector(3);

    a.data[0] = 1; a.data[1] = 2; a.data[2] = 3;
    b.data[0] = 4; b.data[1] = 5; b.data[2] = 6;

    double result = dot_product(&a, &b);

    if (double_equal(result, 32)) {
        printf("test_dot_product: PASSED\n");
    } else {
        printf("test_dot_product: FAILED\n");
    }

    free_vector(&a);
    free_vector(&b);
}

void test_add_matrices() {
    Matrix a = create_matrix(2, 2);
    Matrix b = create_matrix(2, 2);
    Matrix result = create_matrix(2, 2);

    a.data[0][0] = 1; a.data[0][1] = 2;
    a.data[1][0] = 3; a.data[1][1] = 4;

    b.data[0][0] = 5; b.data[0][1] = 6;
    b.data[1][0] = 7; b.data[1][1] = 8;

    int ok = add_matrices(&a, &b, &result);

    if (ok &&
        double_equal(result.data[0][0], 6) &&
        double_equal(result.data[0][1], 8) &&
        double_equal(result.data[1][0], 10) &&
        double_equal(result.data[1][1], 12)) {
        printf("test_add_matrices: PASSED\n");
    } else {
        printf("test_add_matrices: FAILED\n");
    }

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

void test_multiply_matrices() {
    Matrix a = create_matrix(2, 2);
    Matrix b = create_matrix(2, 2);
    Matrix result = create_matrix(2, 2);

    a.data[0][0] = 1; a.data[0][1] = 2;
    a.data[1][0] = 3; a.data[1][1] = 4;

    b.data[0][0] = 2; b.data[0][1] = 0;
    b.data[1][0] = 1; b.data[1][1] = 2;

    int ok = multiply_matrices(&a, &b, &result);

    if (ok &&
        double_equal(result.data[0][0], 4) &&
        double_equal(result.data[0][1], 4) &&
        double_equal(result.data[1][0], 10) &&
        double_equal(result.data[1][1], 8)) {
        printf("test_multiply_matrices: PASSED\n");
    } else {
        printf("test_multiply_matrices: FAILED\n");
    }

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

void test_transpose_matrix() {
    Matrix a = create_matrix(2, 3);
    Matrix result = create_matrix(3, 2);

    a.data[0][0] = 1; a.data[0][1] = 2; a.data[0][2] = 3;
    a.data[1][0] = 4; a.data[1][1] = 5; a.data[1][2] = 6;

    int ok = transpose_matrix(&a, &result);

    if (ok &&
        double_equal(result.data[0][0], 1) &&
        double_equal(result.data[1][0], 2) &&
        double_equal(result.data[2][0], 3) &&
        double_equal(result.data[0][1], 4) &&
        double_equal(result.data[1][1], 5) &&
        double_equal(result.data[2][1], 6)) {
        printf("test_transpose_matrix: PASSED\n");
    } else {
        printf("test_transpose_matrix: FAILED\n");
    }

    free_matrix(&a);
    free_matrix(&result);
}

void test_determinant_2x2() {
    Matrix a = create_matrix(2, 2);

    a.data[0][0] = 4; a.data[0][1] = 7;
    a.data[1][0] = 2; a.data[1][1] = 6;

    double det = determinant_2x2(&a);

    if (double_equal(det, 10)) {
        printf("test_determinant_2x2: PASSED\n");
    } else {
        printf("test_determinant_2x2: FAILED\n");
    }

    free_matrix(&a);
}

void test_solve_slae_gauss() {
    Matrix A = create_matrix(2, 2);
    Vector b = create_vector(2);
    Vector x = create_vector(2);

    A.data[0][0] = 2; A.data[0][1] = 1;
    A.data[1][0] = 1; A.data[1][1] = 3;

    b.data[0] = 5;
    b.data[1] = 6;

    int ok = solve_slae_gauss(&A, &b, &x);

    if (ok &&
        double_equal(x.data[0], 1.8) &&
        double_equal(x.data[1], 1.4)) {
        printf("test_solve_slae_gauss: PASSED\n");
    } else {
        printf("test_solve_slae_gauss: FAILED\n");
    }

    free_matrix(&A);
    free_vector(&b);
    free_vector(&x);
}

int main() {
    printf("Running tests...\n\n");

    test_add_vectors();
    test_scalar_multiply_vector();
    test_dot_product();
    test_add_matrices();
    test_multiply_matrices();
    test_transpose_matrix();
    test_determinant_2x2();
    test_solve_slae_gauss();

    return 0;
}