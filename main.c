#include <stdio.h>
#include "include/vector.h"
#include "include/matrix.h"
#include "include/slae.h"

int main() {
    printf("=== Демонстрация работы библиотеки линейной алгебры ===\n\n");

    Vector v1 = create_vector(3);
    Vector v2 = create_vector(3);
    Vector v_result = create_vector(3);

    v1.data[0] = 1; v1.data[1] = 2; v1.data[2] = 3;
    v2.data[0] = 4; v2.data[1] = 5; v2.data[2] = 6;

    printf("Вектор 1: ");
    print_vector(&v1);

    printf("Вектор 2: ");
    print_vector(&v2);

    add_vectors(&v1, &v2, &v_result);
    printf("Сумма векторов: ");
    print_vector(&v_result);

    printf("Скалярное произведение: %.2f\n\n", dot_product(&v1, &v2));

    Matrix m1 = create_matrix(2, 2);
    Matrix m2 = create_matrix(2, 2);
    Matrix m_result = create_matrix(2, 2);
    Matrix m_transpose = create_matrix(2, 2);

    m1.data[0][0] = 1; m1.data[0][1] = 2;
    m1.data[1][0] = 3; m1.data[1][1] = 4;

    m2.data[0][0] = 5; m2.data[0][1] = 6;
    m2.data[1][0] = 7; m2.data[1][1] = 8;

    printf("Матрица 1:\n");
    print_matrix(&m1);

    printf("Матрица 2:\n");
    print_matrix(&m2);

    add_matrices(&m1, &m2, &m_result);
    printf("Сумма матриц:\n");
    print_matrix(&m_result);

    transpose_matrix(&m1, &m_transpose);
    printf("Транспонированная матрица 1:\n");
    print_matrix(&m_transpose);

    printf("Определитель матрицы 1: %.2f\n\n", determinant_2x2(&m1));

    Matrix A = create_matrix(2, 2);
    Vector b = create_vector(2);
    Vector x = create_vector(2);

    A.data[0][0] = 2; A.data[0][1] = 1;
    A.data[1][0] = 1; A.data[1][1] = 3;

    b.data[0] = 5;
    b.data[1] = 6;

    if (solve_slae_gauss(&A, &b, &x)) {
        printf("Решение СЛАУ:\n");
        print_vector(&x);
    } else {
        printf("Не удалось решить СЛАУ.\n");
    }

    free_vector(&v1);
    free_vector(&v2);
    free_vector(&v_result);

    free_matrix(&m1);
    free_matrix(&m2);
    free_matrix(&m_result);
    free_matrix(&m_transpose);

    free_matrix(&A);
    free_vector(&b);
    free_vector(&x);

    return 0;
}