#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int size;
    double *data;
} Vector;

Vector create_vector(int size);
void free_vector(Vector *v);
void print_vector(const Vector *v);
int add_vectors(const Vector *a, const Vector *b, Vector *result);
int scalar_multiply_vector(const Vector *v, double scalar, Vector *result);
double dot_product(const Vector *a, const Vector *b);

#endif