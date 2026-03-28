#include <stdio.h>
#include <stdlib.h>
#include "../include/vector.h"

Vector create_vector(int size) {
    Vector v;
    v.size = size;
    v.data = (double *)malloc(size * sizeof(double));

    if (v.data == NULL) {
        v.size = 0;
    }

    return v;
}

void free_vector(Vector *v) {
    if (v->data != NULL) {
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
}

void print_vector(const Vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%.2f ", v->data[i]);
    }
    printf("\n");
}

int add_vectors(const Vector *a, const Vector *b, Vector *result) {
    if (a->size != b->size || result->size != a->size) {
        return 0;
    }

    for (int i = 0; i < a->size; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }

    return 1;
}

int scalar_multiply_vector(const Vector *v, double scalar, Vector *result) {
    if (result->size != v->size) {
        return 0;
    }

    for (int i = 0; i < v->size; i++) {
        result->data[i] = v->data[i] * scalar;
    }

    return 1;
}

double dot_product(const Vector *a, const Vector *b) {
    if (a->size != b->size) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < a->size; i++) {
        sum += a->data[i] * b->data[i];
    }

    return sum;
}